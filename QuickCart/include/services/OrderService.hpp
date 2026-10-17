#pragma once

#include "models/Order.hpp"
#include "models/Customer.hpp"
#include "models/ShoppingCart.hpp"
#include "services/PricingService.hpp"
#include "services/LoyaltyService.hpp"

class OrderService{
public:
    OrderService checkout(
        int orderId,
        Customer& customer,
        const ShoppingCart& cart,
        const PricingService& pricingservice,
        const LoyaltyService& loyaltyService
    )const;
};