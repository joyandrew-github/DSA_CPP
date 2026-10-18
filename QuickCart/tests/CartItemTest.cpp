
#include <gtest/gtest.h>
#include "models/Product.hpp"
#include "models/CartItem.hpp"

TEST(CartItemTest, CalculatesTotalPrice)
{
    Product milk(101, "Milk", 55.20);

    CartItem item(milk);

    item.increaseQuantity();

    EXPECT_EQ(item.getQuantity(), 2);
    EXPECT_DOUBLE_EQ(item.getTotalPrice(), 110.40);
}
