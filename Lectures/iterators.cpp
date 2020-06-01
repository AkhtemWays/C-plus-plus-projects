#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>

using namespace std;

// struct Lang {
//   string name;
//   int age;
// };

// void justPrintLangs() {
//   vector<Lang> langs = {{"Python", 34},
//                             {"C++", 26}, 
//                             {"Java", 22}, 
//                             {"C#", 17},
//                             {"C", 45}};
//     auto result = find_if(begin(langs), end(langs), 
//       [](const Lang& lang) {
//           return lang.name[0] == 'C';
//       }
//     );
//     if (result == end(langs)) {
//         cout << "not found";
//     } else {
//     cout << result->age; }
// }
// void PrintVectorPart(const vector<int>& numbers) {
//   auto negative_it = find_if(
//     numbers.begin(), numbers.end(),
//     [](int number) {
//       return number < 0;
//     }
//   );

//   for (auto it = negative_it; it != numbers.begin(); ) {
//     cout << *(--it) << " ";
//   }
// }

// template <typename P>
// vector<P> FindGreaterElements(const set<P>& s, P border) {
//   auto it = find(begin(s), end(s), border);
//   vector<P> v;
//   while (it != end(s)) {
//       v.push_back(*it);
//       ++it;
//   }
//   return v;
// }
template <typename G>
void PrintRange(const G& begin_range,const G& end_range) {
    for (auto i = begin_range; i < end_range; ++i) {
        cout << *i << " ";
    }
}

template <class T>
void RemoveDuplicates(vector<T>& v) {
    auto it = unique(begin(v), end(v)
    );
    PrintRange(begin(v), it);
}


void Permutations(const int& N) {
    vector<int> v;
    for (int i = 1; i <= N; ++i) {
        v.push_back(i);
    } sort(begin(v), end(v));
    
     while (next_permutation(begin(v), end(v))) {
        for (auto j : v) {
            cout << j << " ";
        } cout << endl;
    }
    
}
enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <class M>
M compute_median(const vector<Person>& persons) {
    if (persons.size() % 2 == 0) {
        return (persons[(persons.size())/2].age +  persons[((persons.size())/2) - 1].age ) / 2;

    } else {
       return persons[(persons.size() - 1) / 2].age;
    }
}






void PrintStats(const vector<Person>& persons) {
  
  vector<Person> all_women;
  vector<Person> all_men;
  vector<Person> all_busy_men;
  vector<Person> all_busy_women;
  vector<Person> all_unemployed_men;
  vector<Person> all_unemployed_women;
  for (auto person : persons) {
      if (person.gender::Female) {
          all_women.push_back(person);
          if (person.is_employed) {
              all_busy_women.push_back(person);
          } else {
              all_unemployed_women.push_back(person);
          }
      } else {
          all_men.push_back(person);
          if (person.is_employed) {
              all_busy_men.push_back(person);
          } else {
              all_unemployed_men.push_back(person);
          }
      }
  }
    auto median_all_people = compute_median(persons);
    cout << median_all_people << endl;
   auto median_all_women = compute_median(all_women);
    cout << median_all_women << endl;
    auto median_all_men = compute_median(all_men);
    cout << median_all_men << endl;
    auto median_all_unemployed_men = compute_median(all_unemployed_men);
    cout << median_all_unemployed_men << endl;
    auto median_all_unemployed_women = compute_median(all_unemployed_women);
    cout << median_all_unemployed_women << endl;
    auto median_all_busy_men = compute_median(all_busy_men);
    cout << median_all_busy_men << endl;
    auto median_all_busy_women = compute_median(all_busy_women);
    cout << median_busy_women << endl;
}


int main() {
  vector<string> langs = {"Java", "Java", "C++", "C++", "C++"};
     // возвращает итератор на удаление
//   auto it = remove_if(begin(langs), end(langs), 
//   [](const string& lang) {
//       return lang[0] == 'C';
//   });
// удаляет все уникальные элементы
//   auto it = unique(begin(langs), end(langs));
//    auto it = min_element(begin(langs), end(langs));
//    auto it = max_element(begin(langs), end(langs));
//     auto it = minmax_element(begin(langs), end(langs));
//    cout << *it.first << " " << *it.second << endl;

//   partition(begin(langs), end(langs),    // по какому то критерию разделяет элементы
//     [](const string& lang) {
//         return lang[0] == 'C';
//     }
//   );
    
    // set<int> s1 = {1, 8, 3, 2};
    // set<int> s2 = {8, 4, 5, 3};
    // vector<int> s3(s1.size());
    // auto it2 = set_intersection(begin(s1), end(s1), begin(s2), end(s2), begin(s3)); // пересечение множеств
    // сохраняющее результат в s3 
    // vector<string> c_langs;
    // copy_if(begin(langs), end(langs), back_inserter(c_langs), // back_inserter делает пушбэк в заданный вектор
    // [](const string& lang) {
    //     return lang[0] == 'C';
    // }
    // );
    // итераторы можно вычитать друг из друга и получать индексы элементов следуюищм способом
    // auto it = find_if(begin(langs), end(langs), 
    // [](const string& lang) {
    //     return lang[0] == 'C';
    // }
    // );
    // cout << it - begin(langs) << endl;
    // set<int> s = {1, 6, 8, 9};
    // auto it = s.find(6);
    // эквивалентная функция next(it) для итераторов помогающая делать ++it для итераторов

//   PrintRange(it, end(langs)); // обратное итерирование
    //  RemoveDuplicates(langs);
    // Permutations(3);
    vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}



