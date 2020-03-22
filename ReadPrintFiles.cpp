//============================================================================
// Name        : week33.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <map>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <set>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
using namespace std;

void sortByAbsVal() {
	int k;
	cin >> k;
	vector<int> v;
	for (auto i = 0; i < k; ++i) {
		int num;
		cin >> num;
		v.push_back(num);

	}
	sort(begin(v), end(v), [](int a, int b) {
		return (abs(a) <= abs(b));
	});
	for (auto& i : v) {
		cout << i << " ";
	}
}

void sortAlphabetically() {
	int k;
	cin >> k;
	vector<string> v;
	for (auto i = 0; i < k; ++i) {
		string str;
		cin >> str;
		v.push_back(str);

	} sort(begin(v), end(v), [](string a, string b) {
		for (auto& i : a) {
			i = tolower(i);
		} for (auto& j : b) {
			j = tolower(j);
		} return a < b;
	}); for (auto& i : v) {
		cout << i << " ";
	}
}



class SortedStrings {
public:

	void AddString(const string& s) {
		v.push_back(s);
	}
	vector<string> GetSortedStrings() {
		sort(begin(v), end(v), [](string a, string b) {
			for (auto& i : a) {
						i = tolower(i);
					} for (auto& j : b) {
						j = tolower(j);
					} return a < b;
		}); return v;
	}
private:
	vector<string> v;

};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}


class ReversibleString {
public:

    ReversibleString(const string& s) {
    	data = s;
    }
    ReversibleString() {
    	data = "";
    }
	void Reverse() {
		reverse(data.begin(), data.end());
	} string ToString() const  {
		return data;
	}
private:
	string data;
};

class Incognizable {
public:
	Incognizable () {}
	Incognizable(const int& num) {
		num1 = num;
	}
	Incognizable (const int& numm1, const int& numm2) {
		num1 = numm1;
		num2 = numm2;
	}
private:
	int num1;
	int num2;
	int num3;
};
struct Specialization
{
	explicit Specialization(const string& new_valeu)
	{
		value = new_valeu;
	}
	string value;
};


struct Course
{
	explicit Course(const string& new_valeu)
	{
		value = new_valeu;
	}
	string value;
};


struct Week
{
	explicit Week(const string& new_valeu)
	{
		value = new_valeu;
	}
	string value;
};


struct LectureTitle {
	LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week)
	{
		specialization = new_specialization.value;
		course = new_course.value;
		week = new_week.value;
	}
	string specialization;
	string course;
	string week;
};

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

class FunctionPart {
public:
	FunctionPart(char new_operation, double new_value) {
		operation = new_operation;
		value = new_value;
	}
	double Apply(double& source_value) const {
		if (operation == '+') {
			return source_value + value;
		} else {
			return source_value - value;
		}
	}
	void Invert() {
		if (operation == '+') {
			operation = '-';
		} else if (operation == '-') {
			operation = '+';
		} else if (operation == '*') {
			operation = '*';
		} else if (operation == '/') {
			operation = '/';
		}
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(char operation, double value) {
	    parts.push_back({operation, value});
	  }
	double Apply(double value) const {
	    for (const FunctionPart& part : parts) {
	      value = part.Apply(value);
	    }
	    return value;
	  }

	void Invert() {
		for (FunctionPart& part : parts) {
			part.Invert();
		}
	}
private:
	vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params, const Image& image) {
	Function function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.a + params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	function.Apply(weight);
}

void ReadAndPrint(const string& path) {
	ifstream input(path);
	string line;
	if (input.is_open()) {
		cout << "file is opened" << endl;
	while (getline(input, line)) {
		cout << line << endl;
	}
  } else {
	  cout << "no file opened" << endl;
  }
}

void read(const string& path) {
	ifstream input(path);
	int year = 0;
	int month = 0;
	int day = 0;
	for (int i = 0; i < 3; ++i) {
		input >> year;
		input.ignore(1);
		input >> month;
		input.ignore(1);
		input >> day;
		input.ignore(1);
		cout << year << " " << month << " " << day << endl;
	}
}

void WriteToFile(const string& path) {
	ofstream output(path, ios::app); // для записи по новой
	output << " world";
}

void TableLike() {
	vector<string> letters = {"a", "b", "c"};
	vector<double> nums = {5, 0.05, 0.000005};
	cout << left;
	for (const auto& i: letters) {
		cout << setw(10) << i << " ";
	}
	cout << fixed << setprecision(6) << endl;
	cout << left;
   for (const auto& v: nums) {
	cout << setw(10) << v << " ";
  }
}

void PrintWithPrecision(const string& path, int& precision) {
	ifstream input(path);

	    double a;

	    cout << fixed << setprecision(precision);

	    while (input >> a) {
	        cout << a << endl;
	    }
}
int main() {
	struct student {
		string name;
		string surname;
		int day;
		int month;
		int year;
	};
	string name;
	string surname;
	int day;
	int month;
	int year;

    vector<student> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> name;

    	cin >> surname;

    	cin >> day;

    	cin >> month;

    	cin >> year;
    	v.push_back({name, surname, day, month, year});
    } int m;
      cin >> m;
      for (int i = 0; i < m; ++i) {
    	  string request;
    	  int idx;
    	  cin >> request;

    	  cin >> idx;
    	  if (request == "name") {
    		  cout << v[idx-1].name << " " << v[idx-1].surname << endl;
    	  } else if (request == "date") {
    		  cout << v[idx-1].day << "." << v[idx-1].month << "." << v[idx-1].year << endl;
    	  } else {
    		  cout << "bad request";
    	  }
      }





	return 0;
}



