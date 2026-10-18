#include "services/LoyaltyService.hpp"
#include "models/Customer.hpp"
#include "constants.hpp"


int LoyaltyService::calculatePoints(double amount)const{
    if(amount<=0){
        return 0;
    }
    return static_cast<int>(amount/quickcart::POINTS_PER_100);
    //The static_cast<int> converts the result to an integer, discarding the fractional part.
}

void LoyaltyService::awardPoints(Customer& customer,double amount)const{
    int points=calculatePoints(amount);
    customer.addLoyaltyPoints(points);
}