#include <iostream>
#include <fstream>

#include <utility>
#include <vector>
#include <map>


using namespace std;

// template <typename First, typename Second>
// pair<First, Second> operator*(const pair<First, Second> p1, const pair<First, Second> p2) {
//     First first = p1.first * p2.first;
//     Second second = p1.second * p2.second;
//     return make_pair(first, second);
// }

// template <typename T>
// T Sqr(const T x) {
//     return x*x;
// }

// void testPair() {
//     pair<int, int> p = {2, 3};
//     auto result = Sqr(p);
//     cout << result.first << endl;
//     cout << result.second << endl;
// }
template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p);

template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi);

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m);

template <typename Collection>
string Join(const Collection& c, char d) {
  stringstream ss;
  bool first = true;
  for (const auto& i : c) {
    if (!first) {
      ss << d;
    }
    first = false;
    ss << i;
  }
  return ss.str();
}

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p) {
  return out << '(' << p.first << ',' << p.second << ')';
}

template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi) {
  return out << '[' << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m) {
  return out << '{' << Join(m, ',') << '}';
}

int main() {
  vector<double> vi = {1.4, 2, 3};
  cout << vi << endl;
  map<int, double> m = {{1, 2.5}, {3, 4}};
  cout << m << endl;
  vector<vector<int>> v = {{1, 2}, {3, 4}};
  cout << v << endl;
  return 0;
}