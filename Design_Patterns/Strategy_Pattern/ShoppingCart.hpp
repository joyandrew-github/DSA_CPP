#pragma once
#include "PaymentStrategy.hpp"

class ShoppingCart{
private:
    PaymentStrategy* strategy;
public:
    ShoppingCart (PaymentStrategy* strategy):strategy(strategy){}

    void setStrategy(PaymentStrategy* strategy){
        this->strategy=strategy;
    }

    void checkout(double amount){
        strategy->pay(amount);
    }
    
};