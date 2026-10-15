#pragma once
#include <string>

class Coffee{
public:
    virtual double getCost()=0;
    virtual std::string getDescription()=0;

    virtual ~Coffee()=default;
};