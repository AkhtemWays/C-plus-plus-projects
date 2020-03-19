//============================================================================
// Name        : dsad.cpp
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
using namespace std;

bool IsPalindrom(string s) {

	string s2 = s;
	reverse(s2.begin(), s2.end());
	if (s2 == s) {
		return true;
	} else {
		return false;
	}
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;
	vector<string> lengthed_Words;
	for (auto word : words) {
		if (word.size() >= minLength) {
			lengthed_Words.push_back(word);
		}
	}
	for (auto word : lengthed_Words) {
		if (IsPalindrom(word) == true) {
			result.push_back(word);
		}
	} return result;
}


int Factorial(int n) {
	int result = 1;
	if (n < 0) {
		return 1;
	} else if (n == 0 || n == 1) {
		return 1;
	} else {
		int i = 2;
		while (i <= n) {
			result = result*i;
			i++;

		} return result;

	}
}

void PrintTypedNumbers(vector<int>& vec) {
	cout << vec.size();
}

void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void UpdateIfGreater(int a, int& b) {
	if (a > b) {
		b = a;
	}
}

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto i : source) {
		destination.push_back(i);
	} source.clear();
}

void Reverse(vector<int>& num_vec)
{
	vector<int> tmp_vec;

	for (int i = num_vec.size() - 1; i >= 0; --i) {
		tmp_vec.push_back(num_vec[i]);
	}

	num_vec = tmp_vec;
}

vector<int> reversed(const vector<int>& num_vec)
{
	vector<int> tmp_vec;

	for (int i = num_vec.size() - 1; i >= 0; --i) {
		tmp_vec.push_back(num_vec[i]);
	}

	return tmp_vec;
}
void PrintResult(const vector<int>& v) {
	for (auto i : v) {
		cout << i << " ";
	}
}
void Solve(int n) {
	vector<int> v(n);
	int sum = 0;
	  for (int& t : v) {
		  cin >> t;
		  sum += t;
	  } int mean = sum/n;
	  vector<int> result;
	  for (auto i = 0; i <= v.size(); ++i) {
		  if (v[i] > mean) {
			  result.push_back(i);
		  }
	  }cout << result.size() << endl;
	   PrintResult(result);
}

void QueueSolver() {
	vector<string> queue;
	int n;
	string request;
	cin >> n;
	for (auto i = 0; i < n; ++i) {
		cin >> request;
		if (request == "WORRY") {
			int k;
			cin >> k;
			queue[k] = "WORRY";
		} else if (request == "WORRY_COUNT") {
			int count = 0;
			for (auto j = 0; j < queue.size(); j++) {
				if (queue[j] == "WORRY") {
					count += 1;
				}
			} cout << count << endl;
		} else if (request == "COME") {
			int k;
			cin >> k;
			if (k >0) {
				for (auto c = 1; c <= k; ++c) {
					queue.push_back("QUIET");
				}
			} else if (k < 0) {
				while (k != 0) {
					queue.pop_back();
					++k;
				}
			}
		} else if (request == "QUIET") {
			int k;
			cin >> k;
			queue[k] = "QUIET";
		}
	}
}


void monthlyAffairs() {
	struct Month {
			int days;
            vector<vector<string>> plans;
	};
	vector<Month> months = {{31, vector<vector<string>>(31)},
	{28, vector<vector<string>>(28)}, {31, vector<vector<string>>(31)},
	{30, vector<vector<string>>(30)}, {31, vector<vector<string>>(31)},
	{30, vector<vector<string>>(30)}, {31, vector<vector<string>>(31)},
	{31, vector<vector<string>>(31)}, {30, vector<vector<string>>(30)},
	{31, vector<vector<string>>(31)}, {30, vector<vector<string>>(30)},
	{31, vector<vector<string>>(31)}};

	int n;
	cin >> n;
	int current_month = 0;
	for (int i = 0; i < n; ++i) {
		string request;
		cin >> request;
		if (request == "ADD") {
			int day;
			cin >> day;
			string plan;
			cin >> plan;
			months[current_month].plans[day-1].push_back(plan);
		} else if (request == "DUMP") {
			int day;
			cin >> day;
			cout << months[current_month].plans[day-1].size() << " ";
			for (const auto& k : months[current_month].plans[day-1]) {
				cout << k << " ";

			} cout << endl;
		} else if (request == "NEXT") {
			current_month += 1;
			if (current_month > 11) {
				current_month = 0;
			} if (months[current_month].days == months[current_month - 1].days) {
				for (auto c = 0; c < months[current_month].days - 1; c++) {
					months[current_month].plans[c] = months[current_month - 1].plans[c];
				} months[current_month - 1].plans = vector<vector<string>>(months[current_month - 1].days);
			} else if (months[current_month - 1].days < months[current_month].days) {
				for (auto p = 0; p < months[current_month - 1].days; p++) {
					months[current_month].plans[p] = months[current_month - 1].plans[p];
				} months[current_month - 1].plans = vector<vector<string>>(months[current_month - 1].days);
			} else if (months[current_month - 1].days > months[current_month].days) {
				for (auto o = 0; o < months[current_month].days; o++) {
					months[current_month].plans[o] = months[current_month - 1].plans[o];
				} for (int u = months[current_month].days; u < months[current_month - 1].days; u++) {
					months[current_month].plans[months[current_month].days - 1].insert(end(months[current_month].plans[months[current_month].days - 1]),
						begin(months[current_month - 1].plans[u]), end(months[current_month - 1].plans[u]));
				}

				months[current_month - 1].plans = vector<vector<string>>(months[current_month - 1].days);
			}

		}
	}

}



map<char, int> Anagrams(const string& s) {
	map<char, int> counter;
	  for (const auto& ch : s) {
		  ++counter[ch];
	  } return counter;
}

void countryDirectory() {
	int q;
	cin >> q;
	map<string, string> countryToCapital;
	for (auto i = 0; i < q; ++i) {
		string request;
		cin >> request;
		if (request == "CHANGE_CAPITAL") {
			string country;
			cin >> country;
			string new_capital;
			cin >> new_capital;
			if (countryToCapital.count(country) == 0) {
				countryToCapital[country] = new_capital;
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			} else if (new_capital != countryToCapital[country]){
				cout << "Country " << country << " has changed its capital from " << countryToCapital[country] << " to " << new_capital << endl;
				countryToCapital[country] = new_capital;
			} else if (new_capital == countryToCapital[country]) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
		} else if (request == "RENAME") {

			string oldCountryName;
			string newCountryName;
			cin >> oldCountryName;
			cin >> newCountryName;
			if (oldCountryName != newCountryName) {

			string tmp;
			tmp = countryToCapital[oldCountryName];

			countryToCapital.erase(oldCountryName);
			countryToCapital[newCountryName] = tmp;
			cout << "Country " << oldCountryName << " with capital " << tmp << " has been renamed to " << newCountryName << endl;

		  } else if (oldCountryName == newCountryName) {
			  cout << "Incorrect rename, skip" << endl;
		  }
		} else if (request == "ABOUT") {
			string country;
			cin >> country;
			if (countryToCapital.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << countryToCapital[country] << endl;
			}
		} else if (request == "DUMP") {
			if (countryToCapital.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else if (countryToCapital.size() != 0) {

				for (auto item : countryToCapital) {
					cout << item.first <<"/" << item.second << endl;
				}
			}
		}
	}
}

void autobusStops() {
	int q;
	cin >> q;
	map<string, vector<string>> busToStops;
	for (auto i = 0; i < q; ++i) {
		string request;
		cin >> request;
		if (request == "NEW_BUS") {
			string bus;
			int count_stop;
			cin >> bus;
			cin >> count_stop;
			for (int j = 0; j < count_stop; ++j) {
				string stop;
				cin >> stop;
				busToStops[bus].push_back(stop);
			}
		} else if (request == "ALL_BUSES") {
			if (busToStops.size() != 0) {
			for (auto& item : busToStops) {
				cout << "Bus " << item.first << ": ";
				for (auto& k: item.second) {
					cout << k << " ";
				} cout << endl;
			}
		} else if (busToStops.size() == 0) {
			cout << "No buses" << endl;
		}
	  } else if (request == "BUSES_FOR_STOP") {
		  string stop;
		  cin >> stop;
          int count = 0;
          for (auto item : busToStops) {
        	  for (auto c : item.second) {
        		  if (c == stop) {
        			  cout << item.first << " ";
        			  count++;
        		  }
        	  }
          } if (count == 0) {
        	  cout << "No stop" << endl;
          } else {
        	  cout << endl;
          }
	  } else if (request == "STOPS_FOR_BUS") {
		  string bus;
		  cin >> bus;
		  if (busToStops.count(bus) != 0) {
		  for (auto sto : busToStops[bus]) {
			  vector<string> v;
			  bool flag = false;
			  for (auto item : busToStops) {
				  for (auto m : item.second) {
					  if (m == sto) {
						  v.push_back(item.first);
						  flag = true;
					  }
				  }
			  } if (flag == false) {
				  cout << "Stop " << sto << ": no interchange" << endl;
			  } else {

				  cout << "Stop " << sto << ": ";
				  for (auto l : v) {
					  if (l != bus) {
					  cout << l << " ";}
				  } cout << endl;

		    }
		  }
	    } else if (busToStops.count(bus) == 0) {
	    	cout << "No bus" << endl;
	    }
	  }
	}
}

void uniqueStrings() {
	int n;
	cin >> n;
	set<string> s;
	for (auto i = 0; i < n; ++i) {
		string str;
		cin >> str;
		if (s.count(str) == 0) {
			s.insert(str);
		}
	} cout << s.size();
}



set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> s;
	for (auto item : m) {
		if (s.count(item.second) == 0) {
			s.insert(item.second);
		}
	} return s;
}


void checkSynonims(){
	int n;
	cin >> n;
	map<string, set<string>> wordToSynonims;
	for (auto i = 0; i < n; ++i) {
		string request;
		cin >> request;
		if (request == "ADD") {
			string s1;
			string s2;
			cin >> s1;
			cin >> s2;
			if (wordToSynonims.count(s1) == 1) {
				wordToSynonims[s1].insert(s2);
			} else if (wordToSynonims.count(s1) == 0) {
				wordToSynonims[s1] = {s2};
			}
			if (wordToSynonims.count(s2) == 1) {
			wordToSynonims[s2].insert(s1);
			} else if (wordToSynonims.count(s2) == 0) {
			wordToSynonims[s2] = {s1};
			}
		} else if (request == "COUNT") {
			string s1;
			cin >> s1;
			cout << wordToSynonims[s1].size() << endl;
		} else if (request == "CHECK") {
			string s1;
			string s2;
			cin >> s1;
			cin >> s2;
			if (wordToSynonims[s2].count(s1) == 1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}

void busStops() {
	int q;
	cin >> q;
	map<set<string>, int> m;
	int bus_num = 0;
	for (auto i = 0; i < q; ++i) {
		int k;
		cin >> k;
		set<string> s;
		for (auto j = 0; j < k; ++j) {
			string stop;
			cin >> stop;
			s.insert(stop);
		} if (m.count(s) == 0) {
			bus_num += 1;
			m[s] = bus_num;
			cout << "New bus " << bus_num << endl;
		} else {
			cout << "Already exists for " << m[s] << endl;
		}
	}
}

int main() {
	busStops();



	return 0;
}

