#pragma once

class DiscountStrategy {
public:
    virtual double calculateDiscount(double subtotal) const = 0;

    virtual ~DiscountStrategy() = default;
};