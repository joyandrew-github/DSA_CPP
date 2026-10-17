#include "services/OrderService.hpp"

Order OrderService::checkout(
    int orderId,
    Customer &customer,
    const ShoppingCart &cart,
    const PricingService &pricingService,
    const LoyaltyService &loyaltyService
) const{
    double subTotal=cart.getSubTotal();
    double finalAmount=pricingService.calculateFinalAmount(subTotal);

    Order order(
        orderId,
        customer.getId(),
        finalAmount
    );

    loyaltyService.awardPoints(customer,finalAmount);

    return order;
}