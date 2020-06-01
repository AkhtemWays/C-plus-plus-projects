#include <iostream>
#include <vector>
#include <future>
#include <memory>
#include <string>

using namespace std;

struct Actor {
public:
  Actor(string name) : name_(name) {cout << "I was born!" << endl;}
  ~Actor() { cout << "I died!" << endl;}
  void DoWork() {cout << "I did a job!" << endl;}
private:
  string name_;
};

void run(Actor* ptr) {
    if (ptr) {
        ptr->DoWork();
    } else { cout << "pointer was expected :("; }
}

// виды объектов с точки зрения времени их жизни:
// Автоматические: Время их жизни определяет компилятор: Локальные, глобальные переменные, члены классов.
// Динамические: Время их жизни определяет программист: вызываются с помощью new, make_shared, make_unique
// удаляются с помощью delete, или в деструкторе make_shared, make_unique

// Также есть владение: считается что некоторая сущность владеет объектом - если она отвечает за его удаление
// Автоматическими объектами владеет: окружающий блок кода для локальных переменных, сама программа для 
// глобальных, объект класса владеет своими членами.
// Динамическими объектами владеют: умные указатели, сырые указатели не владеют объектами.
// Сырые указатели не владеют объектом!
// На практике не использовать new и delete, а использовать make_unique и make_shared.
// Не нужно давать в конструктор умных указателей сырые указатели


struct Data {
public:
    Data(string s) : data(s) {
        cout << "Data was constructed" << endl;
    }
    const string& Get() const {
        return data;
    }
    string
    & Get() {
        return data;
    }
    ~Data() {
        cout << "Object was destroyed" << endl;
    }
private:
  string data;
};

void ShareResource(shared_ptr<Data> ptr) {
    stringstream ss;
    ss << "Shared resource " << ptr->Get() << " in " << this_thread::get_id()
    << "counter = " << ptr.use_count() << endl; // this_thread::get_id() возвращает id треда
    // use_count возвращает кол-во ссылок на объект из различных shared_ptr
    cout << ss.str();
}

vector<future<void>> spawn() {
    vector<future<void>> tasks;
    auto data = make_shared<Data>("Meow");
    for (size_t i = 0; i < 10; ++i) {
        tasks.push_back(async([=]() {
            ShareResource(data);
        }));
    }


    return tasks;

} 


int main() {
    // // умный указатель удаляющий себя сам, предотвращающий утечки
    // // auto ptr = unique_ptr<Actor>(new Actor);  // первый вариант создания умного указателя
    // // shared ptr в отличии от unique ptr можно копировать
    // shared_ptr<Actor> ptr = make_shared<Actor>(); // shared ptr может делать всё то же самое что и unique ptr но даже больше
    // // run(ptr); // даст ошибку потому что тип не Actor*
    // run(ptr.get()); // возвращает обычный указатель из умного
    // // auto ptr2 = ptr; // не скомпилируется потому что нельзя создавать 2 unique указателя на один объект
    // // но мы можем перемещать указатель
    // auto ptr2 = ptr;
    // run(ptr2.get());
    // run(ptr.get());
    // Образец присваивания //
    // Динамический объект удаляется, когда им перестают владеть умные указатели при этом умный указатель
    // перестает владеть объектом при разрушении, присваивании, перемещении
    // auto ptr1 = make_unique<Actor>("Alice");
    // auto ptr2 = make_unique<Actor>("Boris");
    // run(ptr1.get());
    // run(ptr2.get());
    // shared ptr в многопоточности
    cout << "Spawning tasks ... \n";
    auto tasks = spawn();
    cout << "Done spawning";
    
    return 0;
}