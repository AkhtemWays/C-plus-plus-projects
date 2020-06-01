#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include <set>


using namespace std;
template <typename T>
class SimpleVector {
public:
  SimpleVector(size_t size) : capacity_(size), data(new T[size]) {}
  ~SimpleVector() {
      delete[] data;
  }
  const T* begin() const {
      return data;
  }

  const T* end() const {
      return data + size_;
  }
  T* begin() {
      return data;
  }
  T* end() {
      return data + size_;
  }
  T& operator[](size_t idx) {
      return *(data + idx); // или так data[idx]
  }
  size_t Size() const {
      return size_;
  }
  size_t Capacity() const {
     return capacity_;
  }
  void push_back(const T& value) {
      if (data == nullptr) {
          data = new T[1];
          *data[0] = value;
          capacity_ = 1;
          size_ = 1;
      } else if (size_ == Capacity() && Size() != 0) {
          auto tmp = new T[size_+1];
          
          for (size_t i = 0; i < Size(); ++i) {
              tmp[i] = data[i];
          } tmp[Size()] = &value;
          delete[] data;
          T* data = new T[2*Capacity()];
          for (size_t i = 0; i < Size() + 1; ++i)  {
              data[i] = tmp[i];
          } delete[] tmp;
          ++size_;
          capacity_ = 2*capacity_;
      } else {
          data[Size()] = value;
          ++size_;
      }
  }

private:
  T* data = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;
};

void f() {
    int a = 43;
    int b = 71;
}
template <typename G>
void PrintVector(const SimpleVector<G>& v) {
  for (auto i = begin(v); i != end(v); ++i) {
      cout << *i << endl;
  }
}

template <typename K>
void Swap(K* first, K* second) {
    auto tmp = *first;
    *first = *second;
    *second = tmp;
}
template <typename k>
void SortPointers(vector<k*>& pointers) {
   sort(begin(pointers), end(pointers), 
   [](k* p1, k* p2) {
       return *p1 < *p2;
   }
   );
}
template <typename V>
void ReversedCopy(V* src, size_t count, V* dst) {
    set<V*> copied;
    for (int i = 1; i <= count; ++i) {
        if (copied.count(src - i) == 0)  
        *(dst + i) = *(src - i); 
        }
    }


template <typename L>
class LinkedList {
public:
   struct Node {
     L value;
     Node* next = nullptr;
   };
   ~LinkedList() {
       while (head != nullptr) {
           Node* tmp = head;
           delete head;
           Node* head = tmp;
           head.next = tmp.next;
       }
   }
   const Node* GetHead() const {
       return head;
   }
   Node* GetHead() { return head; }
   void PushFront(const L& val) {
        Node* new_head = new Node;
	    new_head->value = value;
	    new_head->next = head_;

	    head_ = new_head;
   }
   void InsertAfter(Node* node, const L& val) {
           if (node == nullptr)
    {
		PushFront(val);
    }
    else
    {
		Node* insert_node = new Node;
		insert_node->value = val;
		insert_node->next = node->next;
		node->next = insert_node;
    }
   }
   void PopFront() {
       if (head == nullptr) {
           cout << "empty list";
       } else {
           if (head.next == nullptr) {
               delete head.next;
               head = nullptr;
           } else {
                head = &head.next;
                delete &head;
           }
       }
   }
   void RemoveAfter(Node* node) {
       if (node.next != nullptr) {
           if (node.next.next != nullptr) {
               delete node.next;
               node.next = &node.next.next;
               

           } else {
             delete node.next;
             node.next = nullptr;
           }
       }
   }
   
private:
  Node* head = nullptr;
  
};



int main() {
    SimpleVector<int> sv(4);
    sv[0] = 5;
    sv[1] = 1;
    sv[2] = 8;
    sv[3] = 10;
    sv[4] = 3;
    sort(begin(sv), end(sv));
    // for (int x : sv) {
    //     cout << x << endl;
    // }
      


    // играемся с поинтерами 
    // пример 1
    // int x = 5;
    // int* y = &x; // &x означает адрес места нахождения х
    // cout << y << "  " << *y; // через адрес получаем значение х
    // *y = 82; // и даже менять через обе переменные
    // x = 84;
    // cout << *y << endl;
    // cout << x;
    // пример 2
    // int c = 89;
    // for (int i = 0; i < 20; ++i) { // происходит вызов функции f которая создает стековый фрейм для своих 
    //     f(); // переменных и мы пытаемся смещением указателя c на i шагов угадать расположение переменных a, b
    //     int x = *(&c - i); 
    //     cout << i << " " << x << endl;
    // }
    // пример 3
    // играем с памятью
    // int a = 3;
    // int* b = &a;
    // int* c = b + 3;
    // cout << b << endl << c;
    // пример 4 константность указателей
    int x = 4;
    const int* ptr = &x; // в этом случае не можем изменять х, но можем изменять поинтер
    int a = 5;
    int* const ptr2 = &a;  // а в этом случае не можем менять поинтер, а можем менять значение в стеке
    int b = 6;
    const int* const ptr3 = &b; // а это вообще трогать нельзя :)
    // ++(*ptr); // даст ошибку
    // ++ptr2; // даст ошибку


    return 0;
}