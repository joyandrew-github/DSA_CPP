cmake_minimum_required(VERSION 3.23)

project(QuickCart LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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
)

target_include_directories(QuickCart PRIVATE include)
