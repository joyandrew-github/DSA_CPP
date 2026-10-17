#pragma once

class PricingService{
public:
    double calculateDiscount(double subtotal)const;
    double calculateFinalAmount(double subtotal)const;
};