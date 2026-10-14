#pragma once
#include "Payment.hpp"
#include <iostream>

class CardPayment:public Payment{
public:
    void pay(double amount)override{
        std::cout << "Paid Rs." << amount
                  << " using Card" << std::endl;
    }
};