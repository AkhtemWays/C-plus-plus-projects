
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;



struct Email {
  string from;
  string to;
  string body;
};
inline istream& operator>>(istream& input, Email& email) {
   string from, to, body;
   getline(input, from);
   getline(input, to);
   getline(input, body);
   email = Email{move(from), move(to), move(body)};
   return input;
}
inline ostream& operator<<(ostream& out, const Email& email) {
    out << email.from << '\n';
    out << email.to << '\n';
    out << email.body << '\n';
    return out;
}


class Worker {
public:
  virtual ~Worker() = default;
  virtual void Process(unique_ptr<Email> email) = 0;
  virtual void Run() {
    // С‚РѕР»СЊРєРѕ РїРµСЂРІРѕРјСѓ worker-Сѓ РІ РїР°Р№РїР»Р°Р№РЅРµ РЅСѓР¶РЅРѕ СЌС‚Рѕ РёРјРїР»РµРјРµРЅС‚РёСЂРѕРІР°С‚СЊ
    throw logic_error("Unimplemented");
  }

protected:
  // СЂРµР°Р»РёР·Р°С†РёРё РґРѕР»Р¶РЅС‹ РІС‹Р·С‹РІР°С‚СЊ PassOn, С‡С‚РѕР±С‹ РїРµСЂРµРґР°С‚СЊ РѕР±СЉРµРєС‚ РґР°Р»СЊС€Рµ
  // РїРѕ С†РµРїРѕС‡РєРµ РѕР±СЂР°Р±РѕС‚С‡РёРєРѕРІ
  void PassOn(unique_ptr<Email> email) const {
      if (next_) {
          next_->Process(move(email));
      }
  }

public:
  void SetNext(unique_ptr<Worker> next) {
      if (!next_) {
          next_ = move(next);
      } else {
          next_->SetNext(move(next));
      }
  }
private:
  unique_ptr<Worker> next_ = nullptr;
};


class Reader : public Worker {
public:
  Reader(istream& in)  {
    Email email;
    while(in >> email) {
        emails_.emplace_back(make_unique<Email>(move(email)));
    }
  }
  void Run() override {
      for (unique_ptr<Email>& email : emails_) {
          PassOn(move(email));
      }
  }
  void Process(unique_ptr<Email> email) override {
      Run();
  }

      
private:
  vector<unique_ptr<Email>> emails_;
};


class Filter : public Worker 
{
public:
	using Function = function<bool(const Email&)>;

	explicit Filter(const Function& function) : function_(function) {}

    void Process(std::unique_ptr<Email> email) override
	{
		if (function_(*email))
			PassOn(std::move(email));
	}

private:
	const Function function_;
};


class Copier : public Worker {
public:
  Copier(const string& recipient) : recipient_(recipient) {}
  void Process(unique_ptr<Email> email) {
      unique_ptr<Email> new_email = nullptr;
       if (recipient_ != email->to) {
           new_email = make_unique<Email>(Email{email->from, recipient_, email->body});
       }
       PassOn(move(email));
       if (new_email) { PassOn(move(new_email)); }
  }
  
private:
  const string recipient_;
};


class Sender : public Worker {
public:
  Sender(ostream& out) : out_(out) {}
  void Process(unique_ptr<Email> email) override {
      out_ << *email; 
      PassOn(move(email));

  }
private:
  ostream& out_;
};


// СЂРµР°Р»РёР·СѓР№С‚Рµ РєР»Р°СЃСЃ
class PipelineBuilder {
public:
  // РґРѕР±Р°РІР»СЏРµС‚ РІ РєР°С‡РµСЃС‚РІРµ РїРµСЂРІРѕРіРѕ РѕР±СЂР°Р±РѕС‚С‡РёРєР° Reader
  explicit PipelineBuilder(istream& in) {
     head_ = make_unique<Reader>(in);

  }

  // РґРѕР±Р°РІР»СЏРµС‚ РЅРѕРІС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє Filter
  PipelineBuilder& FilterBy(Filter::Function filter) {
      head_->SetNext(make_unique<Filter>(move(filter)));
      return *this;
  }

  // РґРѕР±Р°РІР»СЏРµС‚ РЅРѕРІС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє Copier
  PipelineBuilder& CopyTo(string recipient) {
      head_->SetNext(make_unique<Copier>(recipient));
      return *this;
  }

  // РґРѕР±Р°РІР»СЏРµС‚ РЅРѕРІС‹Р№ РѕР±СЂР°Р±РѕС‚С‡РёРє Sender
  PipelineBuilder& Send(ostream& out) {
      head_->SetNext(make_unique<Sender>(out));
      return *this;
  }

  // РІРѕР·РІСЂР°С‰Р°РµС‚ РіРѕС‚РѕРІСѓСЋ С†РµРїРѕС‡РєСѓ РѕР±СЂР°Р±РѕС‚С‡РёРєРѕРІ
  unique_ptr<Worker> Build() {
      return move(head_);
  }
private:
  unique_ptr<Worker> head_;
};


void TestSanity() {
  string input = (
    "erich@example.com\n"
    "richard@example.com\n"
    "Hello there\n"

    "erich@example.com\n"
    "ralph@example.com\n"
    "Are you sure you pressed the right button?\n"

    "ralph@example.com\n"
    "erich@example.com\n"
    "I do not make mistakes of that kind\n"
  );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  builder.FilterBy([](const Email& email) {
    return email.from == "erich@example.com";
  });
  builder.CopyTo("richard@example.com");
  builder.Send(outStream);
  auto pipeline = builder.Build();

  pipeline->Run();

  string expectedOutput = (
    "erich@example.com\n"
    "richard@example.com\n"
    "Hello there\n"

    "erich@example.com\n"
    "ralph@example.com\n"
    "Are you sure you pressed the right button?\n"

    "erich@example.com\n"
    "richard@example.com\n"
    "Are you sure you pressed the right button?\n"
  );

  
}


int main() {
    TestSanity();
    return 0;
}