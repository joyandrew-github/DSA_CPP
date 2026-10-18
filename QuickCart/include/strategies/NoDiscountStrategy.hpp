#ifndef NO_DISCOUNT_STRATEGY_HPP
#define NO_DISCOUNT_STRATEGY_HPP

#include "strategies/DiscountStrategy.hpp"

class NoDiscountStrategy : public DiscountStrategy {
public:
    double calculateDiscount(double subtotal) const override {
        return 0.0;
    }
};

#endif
