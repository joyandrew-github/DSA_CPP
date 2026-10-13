#pragma once
#include <iostream>
#include "PaymentStrategy.hpp"

class CardPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        std::cout << "Paid Rs." << amount << " using Card\n";
    }
};