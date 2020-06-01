#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Fruit {
  int health = 0;
  string type;
};

struct Apple : public Fruit {
   Apple() {
       health = 10;
       type = "Apple";
   }
};

struct Orange : public Fruit {
  Orange() {
    health = 5;
    type = "Orange";
  }
    
};

class Animal {

public:
  Animal(const string& t = "animal") : type(t) {}
  void Eat(const Fruit& fruit) const {
    cout << type << " ate " << fruit.type << ". +" << fruit.health << " of health";
  }
  // virtual void MakeSound() const = 0;  требует реализации метода в каждых классах потомков, иначе даст ошибку
  virtual void MakeSound() const {}
// protected: // защищает переменные или чего либо от их модифицирования
  const string type;
};

class Cat : public Animal {
public:
    Cat() : Animal("cat") {}
    
    void MakeSound() const override {
        cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("dog") {}
    void MakeSound() const override {
        cout << "Whoaf!" << endl;
    }
};

class Parrot: public Animal {
public:
    Parrot(const string& name) : Animal("parrot"), name_(name) {}

    void MakeSound() const override {
        cout << name_ << " is good!" << endl;
    }

private:
  const string name_;
};

void Voice(const Animal& a) {
    a.MakeSound();
}

int main() {
  vector<shared_ptr<Animal>> animals = {
      make_shared<Cat>(),
      make_shared<Dog>(),
      make_shared<Parrot>("Kesha")
  };
  for (auto animal : animals) {
    //   animal->MakeSound();
    Voice(*animal);
  }
  

  return 0;
};

