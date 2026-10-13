#pragma once

class DiscountStrategy{
public:
    virtual double calculateDiscount(double price) = 0;

    virtual ~DiscountStrategy()=default;
};