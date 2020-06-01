#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


struct Duration {
    int hour;
    int min;
    Duration(int h = 0, int m = 0) {
        hour = h;
        min = m;
    }
};

Duration ReadDuration(istream& stream) {
    int h;
    int m;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration{h, m};
};

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ":" << setw(2) << duration.min;
}

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}

Duration operator+(Duration& dur1, Duration& dur2) {
    int hours = dur1.hour + dur2.hour;
    int mins = dur1.min + dur2.min;
    return Duration{hours, mins};
}

int main() {
   stringstream dur("01:50");
   Duration dur1{0, 0};
   Duration dur2{1, 5};
   dur >> dur1;
   cout << dur1 + dur2 << endl;


    return 0;
}



