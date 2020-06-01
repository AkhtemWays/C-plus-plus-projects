#include <iostream>
#include <string>

using namespace std;

#define MAIN int main()
#define RETURN return 0
#define X(x) #x << " = " << x
#define S(s) #s << " = " << s
#define ISTRUE(IsTrue) #IsTrue << " = " << IsTrue

MAIN {
    int x = 4;
    string s = "Hello";
    bool IsTrue = false;
    cout << X(x) << endl
    << S(s) << endl
    << ISTRUE(IsTrue);

    RETURN;

}