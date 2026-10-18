#pragma once

#include <memory>
#include <iostream>
#include <iomanip>

#include "models/Product.hpp"
#include "models/ShoppingCart.hpp"
#include "models/Customer.hpp"
#include "models/Order.hpp"
#include "models/Delivery.hpp"
#include "models/DeliveryPartner.hpp"

#include "services/LoyaltyService.hpp"
#include "services/PricingService.hpp"
#include "services/OrderService.hpp"
#include "services/DeliveryService.hpp"

#include "strategies/NoDiscountStrategy.hpp"
#include "strategies/PercentageDiscountStrategy.hpp"

#include "constants.hpp"

class Application {
public:
    void run() const;
};
