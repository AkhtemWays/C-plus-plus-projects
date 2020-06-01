#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <map>

using namespace std;

struct Date {
    int year;
    string month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
   tuple<const int&, const string&, const int&> left = tie(lhs.year, lhs.month, lhs.day);
   tuple<const int&, const string&, const int&> right = tie(rhs.year, rhs.month, rhs.day);
   return left < right;
}

void testTuple() {
    auto t = make_tuple(7, "C++", true);
    cout << get<1>(t) << " is the " << get<0>(t) << " in rating of popularity" << endl;
    cout << "is that true?" << endl;
    cout << get<2>(t);
}

void testPair() {
    pair<int, string> p = make_pair(7, "C++");
    // auto p = make_pair(7, "C++"); # alternative
    cout << p.first << " " << p.second << endl;
}


enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator==(const Region& lhs, const Region& rhs) {
  return (lhs.std_name == rhs.std_name && lhs.parent_std_name == rhs.parent_std_name && 
      lhs.population == rhs.population && lhs.names.first == rhs.names.first &&
      lhs.names.second == rhs.names.second);
};

bool operator<(const Region& lhs, const Region& rhs) {
  return (lhs.std_name < rhs.std_name && lhs.parent_std_name < rhs.parent_std_name && 
      lhs.population < rhs.population && lhs.names.first < rhs.names.first &&
      lhs.names.second < rhs.names.second);
};

int FindMaxRepetitionCount(const vector<Region>& regions) {
  map<Region, int> counter;
  for (auto& reg : regions) {
      counter[reg] += 1;
    
  } int max = 0;
  for (auto& item : counter) {
      if (counter[item.first] > max) {
          max = counter[item.first];
      }
  } return max;
}



int main() {
    // cout << (
    //     Date{1994, "June", 4} < Date{2017, "January", 10}
    // );
    cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;
  
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;
    return 0;
}