#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

// template <typename Iterator>
// class IteratorRange {
// public:
//   IteratorRange(Iterator begin, Iterator end)
//     : first(begin)
//     , last(end)
//   {
//   }

//   Iterator begin() const {
//     return first;
//   }

//   Iterator end() const {
//     return last;
//   }

// private:
//   Iterator first, last;
// };

// template <typename Collection>
// auto Head(Collection& v, size_t top) {
//   return IteratorRange(v.begin(), next(v.begin(), min(top, v.size())));
// }

// struct sss {
//  sss() {
//      cout << this << endl; // поинтер на объект самого себя
//  }
// };

vector<int> SortedNumbers(vector<int> v) {
    sort(begin(v), end(v));
    return v;
}

int main() {
//     set<char> s = {'a', 'b', 'c'};
//     auto it = find(begin(s), end(s), 'b');
//     --it;
//     cout << *it << endl;
// IILE - Immediately invoked lambda expression
// позволяет сделать операции над изначальна константным вектором без копирования и на месте
    const vector<int> v = []{
        vector<int> data = SortedNumbers({
            4, 7, 1, 4, 3, 7, 8, 1, 1, 2
        });
        auto it = unique(begin(data), end(data));
        data.erase(it, end(data));
        return data;
    }();
    for (const int& i : v) {
        cout << i << " ";
    }
    
    
    return 0;
}