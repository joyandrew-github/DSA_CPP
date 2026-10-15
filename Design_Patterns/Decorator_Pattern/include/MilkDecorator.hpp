#pragma once // preprocessor directive to ensure the header file is included only once in a single compilation
#include "CoffeeDecorator.hpp" // include the CoffeeDecorator header file

class MilkDecorator:public CoffeeDecorator{
public:
    MilkDecorator(Coffee* coffee):CoffeeDecorator(coffee){}

    double getCost() override{
        return coffee->getCost()+20.0;
    }
    std::string getDescription()override{
        return coffee->getDescription()+" +Milk ";
    }
};