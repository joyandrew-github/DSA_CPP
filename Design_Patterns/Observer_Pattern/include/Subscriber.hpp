#pragma once
#include "Observer.hpp"
#include <iostream>

class Subscriber:public Observer{
private:
    std::string name;
public:
    Subscriber(const std::string& name):name(name){}

    void update(const std::string& video)override{
        std::cout<<name
            <<" received notification: "
            <<video<<std::endl;
    }   
};