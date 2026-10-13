#pragma once
#include "DiscountStrategy.hpp"

class ShoppingCart{
private:
    DiscountStrategy* strategy;
public:
    ShoppingCart(DiscountStrategy* strategy):strategy(strategy){}

    void setStrategy(DiscountStrategy* strategy){
        this->strategy=strategy;
    }
    double checkout(double price) {
        return strategy->calculateDiscount(price);
    }
};