#include<bits/stdc++.h>
using namespace std;

class Payment {
public:
    virtual void pay(double amount)=0;
    virtual ~Payment() = default;
};

class UPIPayment:public Payment{
public:
    void pay(const double amount)override{
        cout<<"Paid "<<amount<<" Using UPI"<<endl;
    }
};

class creditCard:public Payment{
public:
    void pay(const double amount)override{
        cout<<"Paid "<<amount<<" Using Credit Card"<<endl;
    }
};

class PaymentProcessor{
public:
    void process(Payment& p,double amount){
        p.pay(amount);
    }
};


int main(){
    PaymentProcessor p;
    UPIPayment up;
    creditCard cd;

    p.process(up,100);
    p.process(cd,100);
    return 0;
}