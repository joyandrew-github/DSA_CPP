#pragma once
#include <iostream>
#include "PaymentStrategy.hpp"

class UpiPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        std::cout << "Paid Rs." << amount << " using UPI\n";
    }
};