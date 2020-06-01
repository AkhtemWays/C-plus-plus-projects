#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <deque>

using namespace std;



// таблица простенькая
// template <typename T>
// class Table {
//  private:
//   vector<vector<T>> data;

//  public:
//   Table(size_t rows, size_t columns) {
//     Resize(rows, columns);
//   }

//   const vector<T>& operator [] (size_t idx) const {
//     return data[idx];
//   }

//   vector<T>& operator [] (size_t idx) {
//     return data[idx];
//   }

//   void Resize(size_t rows, size_t columns) {
//     data.resize(rows);
//     for (auto& item : data) {
//       item.resize(columns);
//     }
//   }

//   pair<size_t, size_t> Size() const {
//     return {data.size(), (data.empty() ? 0 : data[0].size())};
//   }

// };

// Deque
// template <typename G>
// class Deque {
// private:
//   vector<G> front;
//   vector<G> back;
// public:
//   Deque() {}
//   G& operator[](size_t index) {
//       if (index < front.size()) {
//           return front[front.size() - index - 1];
//       } else {
//           return back[index - front.size()];
//       }
//   }
//   const G& operator[](size_t index) const {
//       if (index < front.size()) {
//           return front[front.size() - index - 1];
//       } else {
//           return back[index - front.size()];
//       }
//   }
//   bool Empty() const {
//       return {front.empty() and back.empty()};
//   }
//   size_t Size() const {
//       return {front.size() + back.size()};
//   }
//   void PushFront(G elem) {
//       front.push_back(elem);
//   }
//   void PushBack(G elem) {
//       back.push_back(elem);
//   }
//   const void At(size_t index) const {
//       if (index >= front.size() + back.size()) {
//           throw std::out_of_range("out of range");
//       }
//   }
//   void At(size_t index) {
//       if (index >= front.size() + back.size()) {
//           throw std::out_of_range("out of range");
//       }
//   }
//   G& Front() {
//       return *end(front);
//   }
//   const G& Front() const {
//       return *end(front);
//   }
//   const G& Back() const {
//       return *end(back);
//   }
//   G& Back() {
//       return *end(back);
//   }
// };



template <class Iterator>
// Чтобы по объекту класса можно было итерироваться с помощью фор цикла, нужно ему дать методы бегин и энд
// При этом они должны возвращать итераторы!
struct IteratorRange {
   Iterator first, last;
   Iterator begin() {
       return first;
   }
   Iterator end() {
       return last;
   }
};
// этот вывод не будет работать с константными контейнерами
template <class Container>
IteratorRange<typename Container::iterator> Head(Container& v, const size_t& num) {
    return {
      v.begin(), next(v.begin(), min(num, v.size()))
    };
}

// этот вывод будет работать и с константными контейнерами
// template <class Container>
// auto Head(Container& v, const size_t& num) {
//     return IteratorRange{
//       v.begin(), next(v.begin(), min(num, v.size()))
//     };
// }
template <typename T>
size_t  RangeSize(IteratorRange<T> r) {
    return r.end() - r.begin();
}

template <typename Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end) {
    IteratorRange<Iterator>{begin, end};
}

template <typename L, typename K>
struct MyPair {
  MyPair(const L& fir, const K& sec) : first(fir), second(sec) {}
  L first;
  K second;
};


int main() {
    
    vector<int> v = {1, 2, 3, 4, 5};
    
    for (auto& x : Head(v, 3)) {
       ++x;
    }
    for (auto& x : v) {
        cout << x << " ";
    } cout << endl;
    // cout << RangeSize(Head(v , 3));
    // auto second_half = MakeRange(v.begin() + v.size() / 2, end(v));
    // MyPair<int, bool> p = {2, false};
    // cout << p.first << " " << p.second;
    set<int> s = {2, 3, 6, 7, 9};
    for (int x : Head(s, 3)) {
        cout << x << " ";
    } cout << endl;
    const deque<int> v = {3, 5, 8, 1, 9};
    for (auto x : v) {
        cout << x << " ";
    }
    return 0;
}



