#pragma once

#include "strategies/DiscountStrategy.hpp"
#include <memory>

class PricingService{
public:
    PricingService();
    explicit PricingService(std::unique_ptr<DiscountStrategy> strategy);

    void setStrategy(std::unique_ptr<DiscountStrategy> strategy);
    double calculateDiscount(double subtotal)const;
    double calculateFinalAmount(double subtotal)const;

private:
    std::unique_ptr<DiscountStrategy> strategy_;
};