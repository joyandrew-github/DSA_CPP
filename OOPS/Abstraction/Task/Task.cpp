#include<iostream>
using namespace std;
class Payment{
    public:
        virtual void pay(double amount) = 0;

};
class UPIPayment :public Payment{
    public:
     void pay(double amount) override{
        cout<<"Paid Rs."<<amount<<" using UPI"<<endl;
    }
};

class CreditCardPayment :public Payment{
    public:
     void pay(double amount) override{
        cout<<"Paid Rs."<<amount<<" using Credit Card"<<endl;
    }
};

// int main(){
//     UPIPayment up;
//     CreditCardPayment cr;
//     up.pay(500);
//     cr.pay(1000);

// }



//Run time polymorphism
int main() {
    UPIPayment up;
    CreditCardPayment cr;

    Payment* ptr;

    ptr = &up;
    ptr->pay(500);

    ptr = &cr;
    ptr->pay(1000);

    return 0;
}
