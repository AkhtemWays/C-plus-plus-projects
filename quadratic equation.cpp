//============================================================================
// Name        : one.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>


using namespace std;

int main() {
  double A, B, C;
  cin >> A >> B >> C;
  double D = B*B - 4*A*C;
  double x_1 = (-B + sqrt(D))/(2*A);
  double x_2 = (-B - sqrt(D))/(2*A);
  if (D > 0 && A != 0) {
  cout << x_1 << " " << x_2;
  }
  else if (D == 0 && B != 0 ) {
	  cout << x_1;
  }
  else if (D > 0 && A == 0) {
	  cout << -C/B;
  }
  else if (D == 0 && A == 0 && B == 0) {
	  cout << " ";
  }
  else {
	  cout << " ";
  }



  return 0;
}
