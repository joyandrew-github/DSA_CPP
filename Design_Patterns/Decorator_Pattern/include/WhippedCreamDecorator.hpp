#pragma once
#include "CoffeeDecorator.hpp"

class WhippedCreamDecorator:public CoffeeDecorator{
public:
    WhippedCreamDecorator(Coffee* coffee):CoffeeDecorator(coffee){}

    double getCost()override{
        return coffee->getCost()+30.00;
    }
    std::string getDescription()override{
        return coffee->getDescription()+" +WhippedCream";
    }
};