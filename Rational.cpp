

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    while (a % b)
        swap(a %= b, b);
    return b;
}

class Rational {
public:
    Rational() {
        n = 0;
        d = 1;
    }

    Rational(int numerator, int denominator) {
    	if (denominator == 0) {
    		throw invalid_argument("denominator is zero, can't continue");
    	} else {
        int gcd = GCD(numerator, denominator);
        n = numerator / gcd;
        d = denominator / gcd;
      }
    }
    int Numerator() const {
        return n;
    }

    int Denominator() const {
        return d;
    }

private:
    int n;
    int d;
};

//#2
bool operator==(const Rational& l, const Rational& r) {
    return (l.Numerator() == r.Numerator()) &&
           (l.Denominator() == r.Denominator());
}

Rational operator+(const Rational& l, const Rational& r) {
    int n = (l.Numerator() * r.Denominator()) +
            (r.Numerator() * l.Denominator());
    int d = l.Denominator() * r.Denominator();
    return Rational {n, d};
}

Rational operator-(const Rational& l, const Rational& r) {
    int n = (l.Numerator() * r.Denominator()) -
            (r.Numerator() * l.Denominator());
    int d = l.Denominator() * r.Denominator();
    return Rational {n, d};
}

//#3
Rational operator*(const Rational& l, const Rational& r) {
    int n = l.Numerator() * r.Numerator();
    int d = l.Denominator() * r.Denominator();
    return Rational {n, d};
}

Rational operator/(const Rational& l, const Rational& r) {
    if (r.Numerator() == 0) {
    	throw domain_error("Would you your number by zero?");
    }
    else {
	int n = l.Numerator() * r.Denominator();
    int d = l.Denominator() * r.Numerator();
    return Rational {n, d};
  }
}

//#4
ostream& operator<<(ostream& stream, const Rational& r) {
    stream << r.Numerator() << '/' << r.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& r) {
    int n, d;
    if (stream.good()) {
        stream >> n;
        stream.ignore(1);
        stream >> d;
        r = Rational {n, d};
    }
    return stream;
}

//#5
bool operator<(const Rational& l, const Rational& r) {
    if ((l.Numerator() * r.Denominator()) <
        (r.Numerator() * l.Denominator()))
        return true;
}



void Calculator(const Rational& num1, const Rational& num2, const char& oper) {
   if (oper == '+') {
	   cout << num1 + num2 << endl;
   } else if (oper == '-') {
	   cout << num1 - num2 << endl;

   } else if (oper == '/') {
	   cout << num1 / num2 << endl;

   } else {
	   cout << num1 * num2 << endl;
   }
}

int main(int argv, char* argc[]) {
	Rational a, b;
	char oper;
	cin >> a >> oper >> b;
	Calculator(a, b, oper);





    //#1
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(-4, -8);
        if (r.Numerator() != 1 || r.Denominator() != 2) {
            cout << "Rational(-4, -8) != 1/2" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    //#2
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            cout << c.Numerator() << '/' << c.Denominator() << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    //#3
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    //#4
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    //#5
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }
    try {
            Rational r(1, 0);
            cout << "Doesn't throw in case of zero denominator" << endl;
            return 1;
        } catch (invalid_argument& ex) { cout << ex.what() << endl;
        }

        try {
            auto x = Rational(1, 2) / Rational(0, 1);
            cout << "Doesn't throw in case of division by zero" << endl;
            return 2;
        } catch (domain_error& ex) { cout << ex.what() << endl;
        }

    cout << "OK" << endl;
    return EXIT_SUCCESS;
}
