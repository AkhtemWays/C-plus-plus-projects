#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <mutex>
#include <iomanip>


struct Account {
public:
  Account(const int& balance) : balance_(balance) {}
  int balance_ = 0;
  vector<int> history;
  mutex m;

  bool Spend(const int& value) {
      lock_guard<mutex> g(m);
      if (value <= balance_) {
          balance_ -= value;
          return true;
      } return false;
  }
};

int SpendMoney(Account& account) {
   int total_spent = 0;
   for (int i = 0; i < 1000001; ++i) {
       if (account.Spend(1)) {
           ++total_spent;
       }
   } return total_spent;
}

using namespace std;




int main() {
     Account family_account(1000000);
    auto husband = async(SpendMoney, ref(family_account));
    auto wife = async(SpendMoney, ref(family_account));
    auto son = async(SpendMoney, ref(family_account));
    auto daughter = async(SpendMoney, ref(family_account));
    int total_spen = husband.get() + wife.get() + daughter.get() + son.get();  
    

    cout << "Spent money: " << SpendMoney(family_account) << endl
     << "Balance: " << family_account.balance_ << endl;
    
    return 0;
}