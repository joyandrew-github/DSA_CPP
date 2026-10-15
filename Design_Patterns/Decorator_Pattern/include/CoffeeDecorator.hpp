#pragma once
#include "Coffee.hpp"

class CoffeeDecorator:public Coffee{
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* coffee):coffee(coffee){}

    virtual ~CoffeeDecorator()=default;
};