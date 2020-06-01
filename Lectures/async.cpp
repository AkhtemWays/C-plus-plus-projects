#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>
#include <future>
#include <map>
#include <set>
#include <utility>
using namespace std;

template <typename Iterator>
class IteratorRange {
public:
  IteratorRange(Iterator begin, Iterator end)
    : first(begin)
    , last(end)
    , size_(distance(first, last))
  {
  }

  Iterator begin() const {
    return first;
  }

  Iterator end() const {
    return last;
  }

  size_t size() const {
    return size_;
  }

private:
  Iterator first, last;
  size_t size_;
};

template <typename Iterator>
class Paginator {
private:
  vector<IteratorRange<Iterator>> pages;

public:
  Paginator(Iterator begin, Iterator end, size_t page_size) {
    for (size_t left = distance(begin, end); left > 0; ) {
      size_t current_page_size = min(page_size, left);
      Iterator current_page_end = next(begin, current_page_size);
      pages.push_back({begin, current_page_end});

      left -= current_page_size;
      begin = current_page_end;
    }
  }

  auto begin() const {
    return pages.begin();
  }

  auto end() const {
    return pages.end();
  }

  size_t size() const {
    return pages.size();
  }
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
  return Paginator(begin(c), end(c), page_size);
}

int SumTwoVectors(const vector<int>& v1, const vector<int>& v2) {
    future<int> f = async([&v1]{
       return accumulate(begin(v1), end(v1), 0);
    });
    int result = accumulate(begin(v2), end(v2), 0);
    return result + f.get();
}  
template <typename ContainerOfVectors> 
int64_t sumSingleThread(const ContainerOfVectors& matrix) {
   int64_t sum = 0;
   for (auto& row : matrix) {
       for (auto& elem : row) {
           sum += elem;
       }
   } return sum;
} 

int64_t CalculateMatrixSum(const vector<vector<int>>& matrix) {
    size_t size = matrix.size();
    size_t page_size = size/2;
    vector<future<int64_t>> futures(2);
    for (auto& page : Paginate(matrix, page_size)) {
        futures.push_back(async([=] {
            return sumSingleThread(page);
        }));
    } int64_t result = 0;
    for (auto& future : futures) {
        result += future.get();
    } return result;
}
// другая задача
struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other) {
      for (auto& stat : other.word_frequences) {
        this.word_frequencies[stat.first] += stat.second;
      }
  }
};

Stats ProcessPageThread(const string& page, const set<string>& key_words) {
     Stats stats;
     for (const auto& word : page) {
       if (find(begin(key_words), end(key_words), word) != end(key_words)) {
         stats.word_frequences[word] += 1;
       }
     } return stats;

}
Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
  string word;
  string text;
  while (input >> word) {
      text.push_back(move(word));
  } 
  size_t page_size = text.size() / 2;
  
  vector<future<Stats>> futures;
  for (const string& page : Paginate(text, page_size)) {
 
    futures.push_back(async[page, key_words] {
      return ProcessPageThread(page, key_words);
    }); 
  } Stats result;
  for (const auto& future : futures) {
    result += future.get();
  } return result;

}


int main() {
    // vector<int> v1 = {1, 1, 1, 1};
    // vector<int> v2 = {3, 3, 3};
    // cout << SumTwoVectors(v1, v2);
    
    return 0;
}