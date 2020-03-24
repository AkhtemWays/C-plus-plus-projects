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
enum class Lang {
  DE, FR, IT
};
struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};


// Define comparison operator for Region type
bool operator<(const Region& region1, const Region& region2) {
	const auto first = make_tuple(region1.std_name, region1.parent_std_name, region1.names, region1.population);
	const auto second = make_tuple(region2.std_name, region2.parent_std_name, region2.names, region2.population);
	return first < second;
}
// takes vector of Region type elements and returns maximum number of same
// Region type elements
int FindMaxRepetitionCount(const vector<Region>& regions) {
	map<Region, int> store;
	for (const auto& region : regions) {
		store[region] += 1;
	} int max = 0;
   for (const auto& item : store) {
	  if (item.second > max) {
		  max = item.second;
	  }
  } return max;
}

// -------------------------------------------------------------------------
// Need to solve square of arbitrary data type or vectors, maps and pairs
template<typename T> T Sqr(const T& object);
template<typename T> vector<T> operator*(const vector<T>& vec1, const vector<T>& vec2);
template<typename Key, typename Value> map<Key, Value> operator*(const map<Key, Value>& map1, const map<Key, Value>& map2);
template<typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& pair1, const pair<First, Second>& pair2);

// *operator for vector
template<typename T> vector<T> operator*(const vector<T>& vec1, const vector<T>& vec2)
{
	vector<T> result;

	for (size_t i = 0; i < vec1.size(); ++i)
	{
		result.push_back(Sqr(vec1[i]));
	}

	return result;
}

// *operator for maps
template<typename Key, typename Value> map<Key, Value> operator*(const map<Key, Value>& map1, const map<Key, Value>& map2)
{
	map<Key, Value> result;

	for (const auto& pair_ : map1)
	{
		result[pair_.first] = Sqr(pair_.second);
	}

	return result;
}

// *operator for a pair
template<typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& pair1, const pair<First, Second>& pair2)
{
	return make_pair(Sqr(pair1.first), Sqr(pair1.second));
}

// Initial problem to be solved for vectors, maps and pairs
template<typename T> T Sqr(const T& x)
{
	return x * x;
}

// solves collection type structure and returns a string from it
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
// <<operator for pair
template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
// <<operator for vector
template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi) {
	return out << '[' << Join(vi, ',') << ']';
}
// <<operator for map
template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m) {
	return out << '{' << Join(m, ',') << '}';
}

// returns reference to value
template <typename key, typename value>
value& GetRefStrict(map<key, value>& m, const key& key) {
	try {
		return m.at(key);
	} catch(out_of_range&) {
		throw runtime_error("Index is out of range");
	}
}

int main () {

	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
