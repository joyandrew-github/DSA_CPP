#pragma once
#include <string>
#include <iostream>
#include "Observer.hpp"

class Investor:public Observer{
private:
    std::string name;
public:
    Investor(const std::string& name):name(name){}
    void update(const double& price)override{
        std::cout<<name<<" receives notification : Stock price is "<<price<<std::endl;
    }
};