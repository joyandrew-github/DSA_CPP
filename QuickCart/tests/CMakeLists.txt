add_executable(QuickCartTests
    ProductTest.cpp
    ShoppingCartTest.cpp
    PricingServiceTest.cpp
    OrderServiceTest.cpp
    DeliveryServiceTest.cpp
    CartItemTest.cpp
)

target_link_libraries(QuickCartTests
    PRIVATE QuickCartCommon GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(QuickCartTests)