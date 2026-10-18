#pragma once

#include <string>

namespace quickcart {

// Product prices
constexpr double MILK_PRICE = 55.20;
constexpr double BREAD_PRICE = 35.20;
constexpr double EGGS_PRICE = 72.00;
constexpr double RICE_PRICE = 120.00;
constexpr double OIL_PRICE=189.50;

// Pricing thresholds and discount rates
constexpr double DISCOUNT_THRESHOLD_LOW = 500.0;
constexpr double DISCOUNT_THRESHOLD_HIGH = 1000.0;
constexpr double DISCOUNT_RATE_LOW = 0.05;   // 5%
constexpr double DISCOUNT_RATE_HIGH = 0.10;  // 10%
constexpr double POINTS_PER_100 = 100.0;

// Delivery statuses
constexpr std::string_view STATUS_ASSIGNED = "Assigned";
constexpr std::string_view STATUS_IN_TRANSIT = "In Transit";
constexpr std::string_view STATUS_DELIVERED = "Delivered";

// Product IDs
constexpr int PRODUCT_ID_MILK = 101;
constexpr int PRODUCT_ID_BREAD = 102;
constexpr int PRODUCT_ID_EGGS = 103;
constexpr int PRODUCT_ID_RICE = 104;

} // namespace quickcart
