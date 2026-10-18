#include <gtest/gtest.h>
#include <string>
#include "models/Product.hpp"
#include "models/ShoppingCart.hpp"

TEST(ShoppingCartTest,AddProductAndCalculateSubTotal)
{
    Product milk(101,"Milk",132.00);

    ShoppingCart cart;
    cart.addProduct(milk);
    cart.addProduct(milk);

    EXPECT_DOUBLE_EQ(cart.getSubTotal(),264.00);
}


TEST(ShoppingCartTest, AddDifferentProductsAndCalculateSubtotal)
{
    Product milk(101, "Milk", 55.20);
    Product bread(102, "Bread", 40.00);

    ShoppingCart cart;

    cart.addProduct(milk);
    cart.addProduct(bread);

    EXPECT_DOUBLE_EQ(cart.getSubTotal(), 95.20);
}


TEST(ShoppingCartTest, AddingSameProductTwiceUpdatesSubtotal)
{
    Product milk(101, "Milk", 55.20);

    ShoppingCart cart;

    cart.addProduct(milk);
    cart.addProduct(milk);

    // Two units of the same product should cost twice the price.
    EXPECT_DOUBLE_EQ(cart.getSubTotal(), 110.40);
}

TEST(ShoppingCartTest, SameProductIsDisplayedWithQuantityTwo)
{
    Product milk(101, "Milk", 55.20);

    ShoppingCart cart;
    cart.addProduct(milk);
    cart.addProduct(milk);

    testing::internal::CaptureStdout();
    cart.displayCart();

    std::string output=testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Milk x 2"), std::string::npos);
    //The find() method searches the string for the text "Milk x 2".
//- If it finds the text, it returns the position where the text begins.
// // If it cannot find the text, it returns std::string::npos, a special value representing “not found.”
// EXPECT_NE means EXPECT NOT EQUAL.

}


