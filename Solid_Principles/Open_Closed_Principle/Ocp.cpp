#include <bits/stdc++.h>
using namespace std;

class PaymentMethod{
public:
    virtual void pay(double amount)=0;

    virtual ~PaymentMethod()=default;
};

class UpiPayment: public PaymentMethod{
    public:
    void pay(double amount) override{
        cout<<"Paid :"<<amount<<" Using UPI"<<endl;
    }
};

class CardPayment: public PaymentMethod{
public:
void pay(double amount) override{
    cout<<"Paid :"<<amount<<" Using Card"<<endl;
}
};

class PaymentProcessor{
    public:
    void process(PaymentMethod& method,double amount){
        method.pay(amount);
    }
};

int main(){
    PaymentProcessor p;
    UpiPayment Upi;
    CardPayment Card;

    p.process(Upi,100000);
    p.process(Card,30900);

    return 0;

}