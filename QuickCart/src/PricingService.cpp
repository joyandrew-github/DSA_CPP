#include "services/PricingService.hpp"
#include "strategies/NoDiscountStrategy.hpp"
#include "strategies/PercentageDiscountStrategy.hpp"
#include <memory>

PricingService::PricingService()
    : strategy_(std::make_unique<NoDiscountStrategy>()) {}

PricingService::PricingService(std::unique_ptr<DiscountStrategy> strategy)
    : strategy_(std::move(strategy)) {}

void PricingService::setStrategy(std::unique_ptr<DiscountStrategy> strategy) {
    strategy_ = std::move(strategy);
}

double PricingService::calculateDiscount(double subtotal) const {
    if (subtotal < 0.0) {
        return 0.0;
    }
    return strategy_->calculateDiscount(subtotal);
}

double PricingService::calculateFinalAmount(double subtotal) const {
    if (subtotal < 0.0) {
        return 0.0;
    }
    double discount = calculateDiscount(subtotal);
    return subtotal - discount;
}