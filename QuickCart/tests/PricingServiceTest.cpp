#include <gtest/gtest.h>
#include <memory>
#include "services/PricingService.hpp"
#include "strategies/NoDiscountStrategy.hpp"
#include "strategies/PercentageDiscountStrategy.hpp"
#include "constants.hpp"

TEST(PricingServiceTest, NoDiscountBelow500) //TEST(TestSuiteName, TestName)
{
    PricingService pricingService;
    pricingService.setStrategy(std::make_unique<NoDiscountStrategy>());

    double discount = pricingService.calculateDiscount(quickcart::DISCOUNT_THRESHOLD_LOW - 100.00);

    EXPECT_DOUBLE_EQ(discount, 0.0); //EXPECT_DOUBLE_EQ(actualValue, expectedValue);

}

TEST(PricingServiceTest, FivePercentDiscountAt500)
{
    PricingService pricingService;
    pricingService.setStrategy(std::make_unique<PercentageDiscountStrategy>(
        quickcart::DISCOUNT_RATE_LOW * 100.0));

    double discount = pricingService.calculateDiscount(quickcart::DISCOUNT_THRESHOLD_LOW + 200.00);

    EXPECT_DOUBLE_EQ(discount, 35.0);
} 

TEST(PricingServiceTest, TenPercentDiscountAt1000)
{
    PricingService pricingService;
    pricingService.setStrategy(std::make_unique<PercentageDiscountStrategy>(
        quickcart::DISCOUNT_RATE_HIGH * 100.0));

    double discount = pricingService.calculateDiscount(quickcart::DISCOUNT_THRESHOLD_HIGH + 200.00);

    EXPECT_DOUBLE_EQ(discount, 120.0);
} 

TEST(PricingServiceTest, NoDiscountJustBelow500)
{
    PricingService pricingService;
    pricingService.setStrategy(std::make_unique<NoDiscountStrategy>());

    double discount = pricingService.calculateDiscount(499.99);

    EXPECT_DOUBLE_EQ(discount, 0.0);
}