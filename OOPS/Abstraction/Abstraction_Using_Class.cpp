#include <iostream>
using namespace std;

class BankAccount{
    private:
        double balance; //hides the internal data
    public:
        BankAccount(double amount){
            balance=amount;
        }
    void deposit(double amount){
        if(amount>0){
            balance+=amount;
        }
    }
    double getBalance() const{
        return balance;
    }
};

int main(){
    BankAccount b(10000);
    b.deposit(1000);
    // b.balance=9000;
    cout<<b.getBalance()<<endl;
    return 0;
}