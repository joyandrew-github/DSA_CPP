#ifndef PERCENTAGE_DISCOUNT_STRATEGY_HPP
#define PERCENTAGE_DISCOUNT_STRATEGY_HPP

#include "strategies/DiscountStrategy.hpp"
#include <stdexcept>

class PercentageDiscountStrategy : public DiscountStrategy {
private:
    double percentage;

public:
    explicit PercentageDiscountStrategy(double percentage)
        : percentage(percentage) {
        if (percentage < 0.0 || percentage > 100.0) {
            throw std::invalid_argument(
                "Discount percentage must be between 0 and 100"
            );
        }
    }

    double calculateDiscount(double subtotal) const override {
        if (subtotal <= 0.0) {
            return 0.0;
        }

        return subtotal * percentage / 100.0;
    }
};

#endif
