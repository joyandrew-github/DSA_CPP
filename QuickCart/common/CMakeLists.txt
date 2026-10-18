add_library(QuickCartCommon OBJECT
    ${CMAKE_SOURCE_DIR}/src/Product.cpp
    ${CMAKE_SOURCE_DIR}/src/ShoppingCart.cpp
    ${CMAKE_SOURCE_DIR}/src/CartItem.cpp
    ${CMAKE_SOURCE_DIR}/src/Customer.cpp
    ${CMAKE_SOURCE_DIR}/src/LoyaltyService.cpp
    ${CMAKE_SOURCE_DIR}/src/PricingService.cpp
    ${CMAKE_SOURCE_DIR}/src/Order.cpp
    ${CMAKE_SOURCE_DIR}/src/OrderService.cpp
    ${CMAKE_SOURCE_DIR}/src/Delivery.cpp
    ${CMAKE_SOURCE_DIR}/src/DeliveryPartner.cpp
    ${CMAKE_SOURCE_DIR}/src/DeliveryService.cpp
    ${CMAKE_SOURCE_DIR}/src/ProductRepository.cpp
)

target_include_directories(QuickCartCommon PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR})