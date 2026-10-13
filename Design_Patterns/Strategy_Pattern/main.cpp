#include<bits/stdc++.h>
#include "UpiPayment.hpp"
#include "CardPayment.hpp"
#include "ShoppingCart.hpp"
#include "PaymentStrategy.hpp"
using namespace std;

int main(){
    UpiPayment upi;
    CardPayment card;

    ShoppingCart cart(&upi);
    cart.checkout(1000);

    cart.setStrategy(&card);// switches to card without creating an separate objects for card
    cart.checkout(20000);


    return 0;
}
