
cmake_minimum_required(VERSION 3.23)

project(QuickCart LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GoogleTest dependency
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

# QuickCart application
add_executable(QuickCart
    src/main.cpp
    src/Product.cpp
    src/ShoppingCart.cpp
    src/CartItem.cpp
    src/Customer.cpp
    src/LoyaltyService.cpp
    src/PricingService.cpp
    src/Order.cpp
    src/OrderService.cpp
    src/Delivery.cpp
    src/DeliveryPartner.cpp
    src/DeliveryService.cpp
)

target_include_directories(QuickCart PRIVATE include)

# Unit tests
enable_testing()

add_executable(QuickCartTests
    tests/PricingServiceTest.cpp
    src/PricingService.cpp
)

target_include_directories(QuickCartTests PRIVATE include)

target_link_libraries(QuickCartTests
    PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(QuickCartTests)
