#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <set>
#include <random>
using namespace std;

// operators to provide python-like representation of set and map
template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}


template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

// function takes the function to test as the first argument, answer as the
// second and hint as the last.
template<class T, class U>
void AssertEqual(const T& t, const U& u,
    const string& hint)
{
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u
       << " hint: " << hint;
    throw runtime_error(os.str());
  }
}
// func to test boolean expressions
inline void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  // Test running method taking function and test_name as arguments
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
	  func();
	  cerr << test_name << " OK" << endl;
	} catch (runtime_error& e) {
	  ++fail_count;
	  cerr << test_name << " fail: " << e.what() << endl;
	} catch (exception& ex) {
		++fail_count;
		cerr << "Unknown exception caught" << endl;
	}
  }
  // For the case if the function to be run after the tests
  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int SolveLinear(double& b, double& c) {
	if (b == 0) {
		return 0;
	} else {
		return 1;
	}
}

int SolveQuadratic(double& a, double& b, double& c) {
	double D = b*b - 4*a*c;
	if (D == 0) {
		return 1;
	} else if (b == 0 && c == 0) {
		return 1;
	} else if (c > 0 && b == 0) {
		return 0;
	}
	else {
		return 2;
	}
}
// function to test
// returns number of real roots in quadratic equation given coefficients
int GetDistinctRealRootCount(double a, double b, double c) {
	if (b*b - 4*a*c < 0) {
		return 0;
	}
  if (a == 0) {
	  SolveLinear(b, c);
  } else {
	  SolveQuadratic(a, b, c);
  }
}

void TestOneRoot() {
	mt19937 gen;
	uniform_real_distribution<> unif(-10, 10);

	for (auto i = 0; i < 100; ++i) {
		const auto x_1 = unif(gen);

		const auto p = x_1 + x_1;
		const auto q = x_1 * x_1;

		const auto count = GetDistinctRealRootCount(1, p, q);
		stringstream description;
		description << showpos << "x^2" << p << "x" << q
			<< " = 0 has 1 real root.";

		AssertEqual(count, 1, description.str());
	}
}



void TestTwoRoots() {
	AssertEqual(GetDistinctRealRootCount(1, 2, 0), 2, "two roots with c = 0");
	AssertEqual(GetDistinctRealRootCount(1, 33, 44), 2, "all possible test");
	AssertEqual(GetDistinctRealRootCount(1, 1, 0), 2, "wrong, has 2 roots");
}
void TestZeroRoots() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "c test");
	AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "a=1 test");
	AssertEqual(GetDistinctRealRootCount(2, 0, 2), 0, "a=2 test");
	AssertEqual(GetDistinctRealRootCount(3, 0, 2), 0, "a=3 test");
}

void TestLinearEquation() {
	AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1,
		"2x+1 = 0 has 1 real root.");
	AssertEqual(GetDistinctRealRootCount(0, -1, 0), 1,
		"-x = 0 has 1 real root.");
	AssertEqual(GetDistinctRealRootCount(0, 120, -10), 1,
		"120x - 10 = 0 has 1 real root.");
}

void TestConstant() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0,
		"c = 0, where c = 1 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, -10), 0,
		"c = 0, where c = -10 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, 189238910), 0,
		"c = 0, where c = 189238910 has 0 real roots.");
}

// -----------------------------------------------------------------------






int main() {
    TestRunner tr;
    tr.RunTest(TestOneRoot, "TestOneRoot");
    tr.RunTest(TestTwoRoots, "TestTwoRoots");
    tr.RunTest(TestZeroRoots, "TestZeroRoots");
    tr.RunTest(TestLinearEquation, "TestLinearEquation");
    tr.RunTest(TestConstant, "TestConstant");

	return 0;
}
