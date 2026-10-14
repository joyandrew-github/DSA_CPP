#pragma once
#include "Payment.hpp"
#include <iostream>

class CashPayment:public Payment{
public:
    void pay(double amount)override{
        std::cout << "Paid Rs." << amount
                  << " using Cash" << std::endl;
    }
};