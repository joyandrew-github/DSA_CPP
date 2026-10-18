add_executable(QuickCartTests
    ProductTest.cpp
    ShoppingCartTest.cpp
    PricingServiceTest.cpp
    OrderServiceTest.cpp
    DeliveryServiceTest.cpp
    CartItemTest.cpp
    ../src/Product.cpp
    ../src/ShoppingCart.cpp
    ../src/CartItem.cpp
    ../src/Customer.cpp
    ../src/LoyaltyService.cpp
    ../src/PricingService.cpp
    ../src/Order.cpp
    ../src/OrderService.cpp
    ../src/Delivery.cpp
    ../src/DeliveryPartner.cpp
    ../src/DeliveryService.cpp
    ../src/ProductRepository.cpp
)

target_include_directories(QuickCartTests PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR})

target_link_libraries(QuickCartTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(QuickCartTests)