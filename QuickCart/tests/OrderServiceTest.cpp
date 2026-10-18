
#include <gtest/gtest.h>
#include <memory>

#include "models/Product.hpp"
#include "models/ShoppingCart.hpp"
#include "models/Customer.hpp"
#include "models/Order.hpp"
#include "services/OrderService.hpp"
#include "services/PricingService.hpp"
#include "services/LoyaltyService.hpp"
#include "strategies/PercentageDiscountStrategy.hpp"
#include "constants.hpp"

TEST(OrderServiceTest, CheckoutAppliesDiscountAndCreatesOrder)
{
    Product laptop(quickcart::PRODUCT_ID_MILK, "Laptop", 1200.00);

    ShoppingCart cart;
    cart.addProduct(laptop);

    Customer customer(1, "Alex");

    PricingService pricingService(
        std::make_unique<PercentageDiscountStrategy>(
            quickcart::DISCOUNT_RATE_HIGH * 100.0));
    LoyaltyService loyaltyService;
    OrderService orderService;

    Order order = orderService.checkout(
        501,
        customer,
        cart,
        pricingService,
        loyaltyService
    );

    EXPECT_DOUBLE_EQ(order.getTotalAmount(), 1080.00);
}
