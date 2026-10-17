#include "services/PricingService.hpp"

double PricingService::calculateDiscount(double subtotal)const{
if(subtotal<0){
    return 0.0;
}
if(subtotal>=1000){
    return subtotal*0.10;
}

if(subtotal>=500){
    return subtotal*0.05;
}
return 0.0;
}

double PricingService::calculateFinalAmount(double subtotal)const{
    if(subtotal<0){
        return 0.0;
    }
    double discount=calculateDiscount(subtotal);
    return subtotal-discount;
}