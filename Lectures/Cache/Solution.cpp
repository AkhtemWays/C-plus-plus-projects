#include "Common.h"
#include <utility>
#include <unordered_map>
#include <mutex>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class LruCache : public ICache {
public:
  LruCache(
      shared_ptr<IBooksUnpacker> books_unpacker,
      const Settings& settings
  ) 
  : books_unpacker_(books_unpacker), settings_(settings)
  {
    free_memory_ = settings_.max_memory;
  }

  BookPtr GetBook(const string& book_name) override {
     mutex_.lock();
     std::unique_ptr<IBook> book = books_unpacker_->UnpackBook(book_name);
     const string name = book->GetName();
     string result = find_book(name);
     if (free_memory_ == cache_.size()) {
           
     }
     if (result == name && cache_.size() < free_memory_) {
       cache_.insert({max_rank, result});
       
     } else {
         cache_.insert({max_rank, name});
     }

  }
private:
  shared_ptr<IBooksUnpacker> books_unpacker_;
  const Settings settings_;
  std::mutex mutex_ = std::mutex();
  size_t free_memory_;
  map<int, std::string> cache_;
  int max_rank;
     string find_book(const string& name) {
         auto it = find_if(begin(cache_), end(cache_), [name](const pair<int, std::string>& p){
                 return p.second == name;
         });
         if (it != end(cache_)) {
             ++max_rank;
             string result = it->second;
             cache_.erase(it);
             return move(result);
         } else {
             return "not found";
         }
     }
};


unique_ptr<ICache> MakeCache(
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
) {
  return std::make_unique<LruCache>(move(books_unpacker), settings);
}