#include <iostream>
using namespace std;
class BankAccount
{
private:
    int balance;

public:
    void setBalance(int amount)
    {
        if (amount > 0)
        {
            balance = amount;
        }
        else
        {
            cout << "Invalid Balance" << endl;
        }
    }
    int getBalance()
    {
        return balance;
    }
};
int main()
{
    BankAccount b;
    b.setBalance(10000);
    cout << b.getBalance() << endl;
    b.setBalance(-50000); // This will not work as the setBalance function is private
    b.setBalance(20000);  // This will work as the setBalance function is private
    cout << b.getBalance() << endl;
    return 0;
}