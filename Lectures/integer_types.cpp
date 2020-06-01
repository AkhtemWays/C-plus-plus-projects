#include <iostream>
#include <limits>
#include <vector>
#include <cstdint>

using namespace std;

int64_t AvgTemp() {
    int n;
    cin >> n;
    int32_t sum = 0;
    vector<int> v(n);
    for (uint32_t i = 0; i < n; ++i) {
       int32_t number;
       cin >> number;
       sum += number;
       v.push_back(number);

    } int32_t avg = sum / static_cast<int>(v.size());
     cout << avg;
}


int main() {
    // cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
    AvgTemp();

    return 0;
};

