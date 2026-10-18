#include <gtest/gtest.h>
#include "services/PricingService.hpp"

TEST(PricingServiceTest,NoDiscountBelow500) //TEST(TestSuiteName, TestName)
{
    PricingService pricingService;

    double discount=pricingService.calculateDiscount(400.00);

    EXPECT_DOUBLE_EQ(discount,0.0); //EXPECT_DOUBLE_EQ(actualValue, expectedValue);

}

TEST(PricingServiceTest,FivePercentDiscountAt500)
{
    PricingService pricingService;

    double discount=pricingService.calculateDiscount(700.00);

    EXPECT_DOUBLE_EQ(discount,35.0);
} 

TEST(PricingServiceTest,TenPercentDiscountAt1000)
{
    PricingService pricingService;

    double discount=pricingService.calculateDiscount(1200.00);

    EXPECT_DOUBLE_EQ(discount,120.0);
} 

TEST(PricingServiceTest, NoDiscountJustBelow500)
{
    PricingService pricingService;

    double discount = pricingService.calculateDiscount(499.99);

    EXPECT_DOUBLE_EQ(discount, 0.0);
}