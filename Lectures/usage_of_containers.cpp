#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>


using namespace std;

template <typename T>
void LogVectorParams(const vector<T>& v) {
    cout << "Length: " << v.size() << endl 
    << "Capacity: " << v.capacity() << endl; 
    const int* data = v.data(); // метод вектора дающий поинтер на данные в векторе
    for (size_t i = 0; i < v.capacity(); ++i) {
        cout << *(data + i) << " ";
    }
}
void sportsmen() {
    int n;
    cin >> n;
    
    list<int> l;
    for (int i = 0; i < n; ++i) {
        int left, right;
        cin >> left >> right;
        if (l.size() == 0) {
           l.push_back(right);
           l.push_front(left);
        } else {
           auto it = find(begin(l), end(l), right);
           l.insert(it, left);
        }
    } for (int g : l) {
        cout << g << endl;
    }
}

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0) {
     if (a_size > N) {
         throw invalid_argument("size more than capacity");
     } else {
         size = a_size;
     }
  }

  T& operator[](size_t index) {
      return v[index];
  }
  const T& operator[](size_t index) const {
      return v[index];
  }

  vector<T>::iterator begin() {
      return begin(v);
  }
  vector<T>::iterator end() {
      return end(v);
  }
  vector<T>::iterator begin() const {
      return begin(v);
  }
  vector<T>::iterator end() const {
      return end(v);
  }

  size_t Size() const {
      return size;
  }
  size_t Capacity() const {
      return capacity;
  }

  void PushBack(const T& value) {
      if (size != capacity) {
          v[size] = value;
          ++size;
      } else {
          throw overflow_error("cant add more because of size being equal to capacity");
      }
  }
  T PopBack() {
      if (!v) {
          throw underflow_error("no elements in array");
      } else {
          T elem = v.pop_back();
          --size;
          --capacity;
          return elem
      } 
  }
private:
  array<T, N> v;
  size_t size = 0
  size_t capacity = N;
};

int main() {
    vector<int> v = {1, 2, 3};
    // LogVectorParams(v);
    
    // LogVectorParams(v);
    // v.shrink_to_fit(); // метод преобразововащий capacity = size
    // LogVectorParams(v);
    // v.reserve(10000); // метод выделяет кол-во памяти, которое нужно выделить в целом, при этом
    // инвалидация ссылок - ссылки на элементы перестают работать после ресайза вектора 
    // int& first = v[0];
    // cout << first << endl;
    // v.push_back(4);
    // cout << first << endl;
    // sportsmen();
    

    return 0;
}


