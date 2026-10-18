
#include <gtest/gtest.h>
#include "models/Product.hpp"
#include "models/CartItem.hpp"
#include "constants.hpp"

TEST(CartItemTest, CalculatesTotalPrice)
{
    Product milk(quickcart::PRODUCT_ID_MILK, "Milk", quickcart::MILK_PRICE);

    CartItem item(milk);

    item.increaseQuantity();

    EXPECT_EQ(item.getQuantity(), 2);
    EXPECT_DOUBLE_EQ(item.getTotalPrice(), 110.40);
}
