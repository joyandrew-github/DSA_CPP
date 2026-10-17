#include "services/LoyaltyService.hpp"
#include "models/Customer.hpp"


int LoyaltyService::calculatePoints(double amount)const{
    if(amount<=0){
        return 0.0;
    }
    return static_cast<int>(amount/100);
    //The static_cast<int> converts the result to an integer, discarding the fractional part.
}

void LoyaltyService::awardPoints(Customer& customer,double amount)const{
    int points=calculatePoints(amount);
    customer.addLoyaltyPoints(points);
}