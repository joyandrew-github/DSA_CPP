#include "models/Customer.hpp"

Customer::Customer(int id,const std::string& name)
        :id(id),name(name),loyaltyPoints(0){}

int Customer::getId()const{
    return id;
}

std::string Customer::getName()const{
    return name;
}

int Customer::getLoyaltyPoints()const{
    return loyaltyPoints;
}

void Customer::addLoyaltyPoints(int points){
    if(points>0){
        loyaltyPoints+=points;
    }
}
