#pragma once

class Customer;

class LoyaltyService{
public:
    int calculatePoints(double amount)const;
    void awardPoints(Customer& customer,double amount)const;
};
