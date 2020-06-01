#include <iostream>
#include <string>
#include "testrunner.h"

#include <algorithm>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
#include <memory>
#include <unordered_map>
using namespace std;


// template <class T>
// class ObjectPool {
// public:
//   T* Allocate();
//   T* TryAllocate();

//   void Deallocate(T* object);

//   ~ObjectPool();

// private:
//   queue<unique_ptr<T>> free;
//   unordered_map<T*, unique_ptr<T>> allocated;
// };

// template <typename T>
// T* ObjectPool<T>::Allocate() {
//   if (free.empty()) {
//     free.push(make_unique<T>());
//   }
//   auto ptr = move(free.front()); // unique ptr только перемещается
//   T* ret = ptr.get();
//   free.pop();
//   allocated[ret] = move(ptr);
//   return ret;
// }

// template <typename T>
// T* ObjectPool<T>::TryAllocate() {
//   if (free.empty()) {
//     return nullptr;
//   }
//   return Allocate();
// }

// template <typename T>
// void ObjectPool<T>::Deallocate(T* object) {
//   auto it = allocated.find(object);
//   if (it == allocated.end()) {
//     throw invalid_argument("");
//   }
//   free.push(move(it->second));
//   allocated.erase(it);
  
// }



// void Run() {
//     ObjectPool<char> pool;
//     for (int i = 0; i < 1000; ++i) {
//         cout << "Allocating object #" << i << endl;
//         pool.Allocate();
//     }
// }

// struct Actor {
//   Actor() {cout << "I was born!" << endl;}
//   ~Actor() { cout << "I died!" << endl;}
//   void DoWork() {cout << "I did a job!" << endl;}
// };

// void run(Actor* ptr) {
//     if (ptr) {
//         ptr->DoWork();
//     } else { cout << "pointer was expected :("; }
// }



// другая задача
// class Animal {
// public:
//   virtual std::string Voice() const {
//     return "Not implemented yet";
//   }
//   virtual ~Animal() {
//   }
// };

// class Tiger: public Animal {
//   std::string Voice() const override {
//     return "Rrrr";
//   }
// };

// class Wolf: public Animal {
//   std::string Voice() const override {
//     return "Wooo";
//   }
// };

// class Fox: public Animal {
//   std::string Voice() const override {
//     return "Tyaf";
//   }
// };

// using Zoo = vector<unique_ptr<Animal>>;

// Zoo CreateZoo(std::istream& in) {
//   string animaloid;
//   Zoo zoo;
//   while(in >> animaloid) {
//     if (animaloid == "Tiger") {
      
//       zoo.push_back(move(make_unique<Tiger>()));
//     } else if (animaloid == "Fox") {
      
//       zoo.push_back(move(make_unique<Fox>()));
//     } else if (animaloid == "Wolf") {
      
//       zoo.push_back(move(make_unique<Wolf>()));
//     } 
//   } return zoo;
// }

// void Process(const Zoo& zoo, std::ostream& out) {
//   for (const auto& animal : zoo) {
//     out << animal.get()->Voice() << endl;
//   }
// }



// другая задача




int main() {
  // умный указатель удаляющий себя сам, предотвращающий утечки
    // auto ptr = unique_ptr<Actor>(new Actor);  // первый вариант создания умного указателя
    // auto ptr = make_unique<Actor>();
    // // run(ptr); // даст ошибку потому что тип не Actor*
    // run(ptr.get()); // возвращает обычный указатель из умного
    // // auto ptr2 = ptr; // не скомпилируется потому что нельзя создавать 2 unique указателя на один объект
    // // но мы можем перемещать указатель
    // auto ptr2 = move(ptr);
    // run(ptr2.get());
    // istringstream in("Tiger Pedor Fox Wolf Fox Tiger");
    // Zoo zoo = CreateZoo(in);
    // Process(zoo, cout);



    return 0;
}