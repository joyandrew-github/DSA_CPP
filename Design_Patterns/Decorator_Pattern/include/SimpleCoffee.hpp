#pragma once
#include <string>
#include "Coffee.hpp"

class SimpleCoffee:public Coffee{
public:
    double getCost() override{
        return 100.00;
    }
    std::string getDescription() override{
        return "Simple Coffee";
    }
};