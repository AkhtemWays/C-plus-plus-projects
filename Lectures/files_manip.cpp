#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// Считывание с файла


// int main() {
//   string year;
//   string month;
//   string day;
//   ifstream input('/home/akhtem/Документы/VSC Projects/c++_projects/hello.txt');
//   if (input.is_open()) {
//     getline(input, year, '-');
//     getline(input, month, '-');
//     getline(input, day, '-');
//   } else {
//     cout << "not opened";
//   }
//   return 0;
// }



// int main() {
//   ifstream input("VSC Projects/c++_projects/hello.txt");
//   int year;
//   int month;
//   int day;
//   if (input.is_open()) {
//     input >> year;
//     input.ignore(1);
//     input >> month;
//     input.ignore(1);
//     input >> day;
//   } else {
//     cout << "not opened";

//   } cout << year << " " << month;


//   return 0;
// }



// Запись в файл


// int main() {
//   const string path = "VSC Projects/c++_projects/output.txt";
//   ofstream output(path, ios::app);
//   output << "hello";
//   ifstream input(path);
//   string line;
//   getline(input, line);
//   cout << line;


//   return 0;
// }


// Потоковые манипуляторы


int main() {
  vector<string> names = {"a", "b", "c"};
  vector<double> values = {5, 0.01, 0.000005};
  cout << setfill('.');
  cout << left;
  for (const auto& i : names) {
    cout << setw(10) << i << " ";
  } cout << endl;
  cout << fixed << setprecision(2);
  for (const auto& j : values) {
    cout << setw(10) << j << " ";
  }


  return 0;
}