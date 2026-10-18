#include "services/Application.hpp"

void Application::run() const
{
    // 1. Create products using named constants
    Product milk(quickcart::PRODUCT_ID_MILK, "Milk", quickcart::MILK_PRICE);
    Product bread(quickcart::PRODUCT_ID_BREAD, "Bread", quickcart::BREAD_PRICE);

    // 2. Add products to cart
    ShoppingCart cart;
    cart.addProduct(milk);
    cart.addProduct(bread);
    cart.addProduct(milk);

    cart.displayCart();

    // 3. Calculate pricing with percentage discount strategy
    PricingService pricingService(
        std::make_unique<PercentageDiscountStrategy>(
            quickcart::DISCOUNT_RATE_HIGH * 100.0));

    double subtotal = cart.getSubTotal();
    double discount = pricingService.calculateDiscount(subtotal);
    double finalAmount = pricingService.calculateFinalAmount(subtotal);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Discount: Rs. " << discount << '\n';
    std::cout << "Final Amount: Rs. " << finalAmount << '\n';

    // 4. Create customer and checkout
    Customer customer(1, "Joyandrew");
    LoyaltyService loyaltyService;
    OrderService orderService;

    Order order = orderService.checkout(
        101,
        customer,
        cart,
        pricingService,
        loyaltyService);

    std::cout << "\n--- Order Details ---\n";
    std::cout << "Order ID     : " << order.getOrderId() << '\n';
    std::cout << "Customer ID  : " << order.getCustomerId() << '\n';
    std::cout << "Total Amount : Rs. " << order.getTotalAmount() << '\n';
    std::cout << "Loyalty Points: " << customer.getLoyaltyPoints() << '\n';

    // 5. Create delivery partner and delivery
    DeliveryPartner partner(10, "Arun", "9876543210");

    Delivery delivery(
        501,
        order.getOrderId(),
        partner.getPartnerId());

    DeliveryService deliveryService;

    std::cout << "\n--- Delivery Partner Details ---\n";
    std::cout << "Partner ID : " << partner.getPartnerId() << '\n';
    std::cout << "Name       : " << partner.getName() << '\n';
    std::cout << "Phone      : " << partner.getPhoneNumber() << '\n';
    std::cout << "Available  : "
              << (partner.isAvailable() ? "Yes" : "No") << '\n';

    // 6. Assign delivery
    std::cout << "\n--- Assign Delivery ---\n";

    if (deliveryService.assignDelivery(delivery, partner))
    {
        std::cout << "Delivery assigned successfully!\n";
    }
    else
    {
        std::cout << "Delivery assignment failed!\n";
    }

    std::cout << "Partner Available: "
              << (partner.isAvailable() ? "Yes" : "No") << '\n';

    // 7. Update status to In Transit
    std::cout << "\n--- Update Delivery Status ---\n";

    if (deliveryService.updateDeliveryStatus(
            delivery, partner, DeliveryStatus::InTransit))
    {
        std::cout << "Status updated to: "
                  << delivery.getStatusString() << '\n';
    }
    else
    {
        std::cout << "Status update failed!\n";
    }

    // Test: Try assigning a second delivery to the same busy partner
    std::cout << "\n--- Test Second Delivery Assignment ---\n";

    Delivery secondDelivery(
        502,
        order.getOrderId(),
        partner.getPartnerId());

    if (deliveryService.assignDelivery(secondDelivery, partner))
    {
        std::cout << "Second delivery assigned successfully!\n";
    }
    else
    {
        std::cout << "Second delivery assignment rejected!\n";
    }

    // Test: Unauthorized partner cannot update the delivery
    std::cout << "\n--- Test Unauthorized Delivery Update ---\n";

    DeliveryPartner anotherPartner(
        20,
        "Kumar",
        "9876543211");

    if (deliveryService.updateDeliveryStatus(
            delivery, anotherPartner, DeliveryStatus::InTransit))
    {
        std::cout << "Status updated to: "
                  << delivery.getStatusString() << '\n';
    }
    else
    {
        std::cout << "Unauthorized delivery update rejected!\n";
    }

    // Test: Complete the delivery
    std::cout << "\n--- Complete Delivery ---\n";

    if (deliveryService.updateDeliveryStatus(
            delivery, partner, DeliveryStatus::Delivered))
    {
        std::cout << "Status updated to: "
                  << delivery.getStatusString() << '\n';
        std::cout << "Partner Available: "
                  << (partner.isAvailable() ? "Yes" : "No") << '\n';
    }
    else
    {
        std::cout << "Delivery completion failed!\n";
    }
}
