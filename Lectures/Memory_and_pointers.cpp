#include <iostream>
#include <set>
#include <random>


using namespace std;

// class Widget {
// public:
//   Widget() {
//       cout << "constructor" << endl;
//   }
//   ~Widget() {
//       cout << "Destructor" << endl;
//   }
// };
// template <typename T>
// class SimpleVector {
// public:
//   SimpleVector(size_t size) {
//     data = new T[size];
//   }
//   ~SimpleVector() {
//       delete[] data;
//   }
// private:
//   T* data; 
// };
template <typename T>
class ObjectPool {
public:
   T* Allocate() {
       if (released) {
           T* to_send = released[0];
           released.erase(to_send);
           pointed.insert(to_send);
           return to_send;

       } else {
           T* ptr = new T;
           pointed.insert(ptr);
           return ptr;
       }
   }
   T* TryAllocate() {
       if (released) {
           T* to_send = released[0];
           released.erase(to_send);
           pointed.insert(to_send);
           return to_send;

       } else {
           return nullptr;
       }
   }

  void Deallocate(T* object) {
      auto it = find(begin(pointed), end(pointed), object);
      if (it != end(pointed))  {
          released.insert(*it);
          pointed.erase(it);
      } else {
          throw invalid_argument;
      }
  }

  ~ObjectPool() {
      for (auto ptr : released) {
          delete ptr;
      }for (auto ptr : pointed) {
          delete ptr;
      }
  }

private:
  set<T*> released;
  set<T*> pointed;
};


int main() {
    // int n;
    // cin >> n;
    // mt19937_64 random_gen;
    // uint64_t sum = 0;
    // for (uint64_t i = 0; i < n; ++i) {
    //   auto* x = new uint64_t; // оператор new создает поинтер
    //   *x = random_gen();
    //   sum += *x;
    //   delete x; // оператор delete удаляет поинтер
    // }

    // тест конструктора и деструктора на примере поинтеров
    // Widget* ptr = new Widget; // вызывает конструктор
    // delete ptr; // вызывает деструктор
    // SimpleVector<int> v(5);
    return 0;
}
