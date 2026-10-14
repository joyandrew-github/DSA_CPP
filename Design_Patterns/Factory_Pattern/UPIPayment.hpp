#pragma once
#include "Payment.hpp"
#include <iostream>

class UPIPayment:public Payment{
public:
    void pay(double amount)override{
        std::cout << "Paid Rs." << amount
                  << " using UPI" << std::endl;
    }
};