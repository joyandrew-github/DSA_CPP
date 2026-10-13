#include <bits/stdc++.h>
using namespace std;

//Abstraction
class PaymentGateway{
public:
    virtual void pay(double amount)=0;

    virtual ~PaymentGateway()=default;
};

// Low-level implementation 1
class Razorpay : public PaymentGateway{
public:
    void pay(double amount)override{
        cout<<"Paid "<<amount<<"Using Razorpay"<<endl;
    }
};
// Low-level implementation 2
class Stripe: public PaymentGateway{
public:
    void pay(double amount)override{
        cout<<"Paid "<<amount<<"Using Stripe";
    }
};

//High level Module
class OrderService{
private:
    PaymentGateway& gateway;

public:
    OrderService(PaymentGateway& gateway):gateway(gateway){}

    void checkout(double amount){
        gateway.pay(amount);
    }
};
int main(){
    Razorpay razorpay;
    Stripe stripe;

    OrderService o1(razorpay);
    o1.checkout(2000);

    OrderService o2(stripe);
    o2.checkout(2000);

    return 0;
}