add_executable(QuickCart
    main.cpp
    Application.cpp
    Product.cpp
    ShoppingCart.cpp
    CartItem.cpp
    Customer.cpp
    LoyaltyService.cpp
    PricingService.cpp
    Order.cpp
    OrderService.cpp
    Delivery.cpp
    DeliveryPartner.cpp
    DeliveryService.cpp
    ProductRepository.cpp
)

target_include_directories(QuickCart PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR})