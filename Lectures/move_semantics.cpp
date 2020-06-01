#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<string> ReadStrings(istream& stream) {
    vector<string> strings;
    string s;
    while (cin >> s) {
        strings.push_back(move(s)); // позволяет считать сразу прямо в вектор сокращая время данные которые 
        // лежат на стеке
    }return strings;
}   

vector<string> SplitIntoWords(const string& s) {
    string cur_word;
    vector<string> words;
   for (const char c : s) {
       if (c == ' ') {
           words.push_back(move(cur_word));
       } else {
           cur_word.push_back(c);
       }
   } words.push_back(move(cur_word));

    return words;
}

string GenerateString() {
    const int64_t SIZE = 1000000000;
    const int64_t LENGTH = 1000000;
    string text(SIZE, 'a');
    for (int i = LENGTH; i <= SIZE; i += LENGTH) {
        text[i] = ' ';
    } return text;
}

int main() {
    string s = "Red Belt C++";
    for (auto& i : SplitIntoWords(s)) {
        cout << i << endl;
    }
    return 0;
}