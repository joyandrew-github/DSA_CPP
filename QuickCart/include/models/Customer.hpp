#pragma once
#include <string>

class Customer{
private:
    int id;
    std::string name;
    int loyaltyPoints;
public:
    Customer(int id,const std::string& name);

    int getId()const;
    std::string getName()const;
    int getLoyaltyPoints()const;


    void addLoyaltyPoints(int points);
};