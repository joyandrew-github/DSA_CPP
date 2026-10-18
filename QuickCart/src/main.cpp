// #include <iostream>
// #include <iomanip>
// #include "models/Product.hpp"
// #include "models/ShoppingCart.hpp"
// #include "models/Customer.hpp"
// #include "models/Order.hpp"
// #include "models/Delivery.hpp"
// #include "models/DeliveryPartner.hpp"
// #include "services/LoyaltyService.hpp"
// #include "services/PricingService.hpp"
// #include "services/OrderService.hpp"

// int main()
// {
//     Product milk(101, "Milk", 55.2);
//     Product bread(102, "Bread", 35.2);

//     ShoppingCart cart;

//     cart.addProduct(milk);
//     cart.addProduct(bread);
//     cart.addProduct(milk);

//     PricingService pricingservice;

//     double subtotal = cart.getSubTotal();

//     double discount = pricingservice.calculateDiscount(subtotal);
//     double finalAmount = pricingservice.calculateFinalAmount(subtotal);

//     std::cout << std::fixed << std::setprecision(2);

//     cart.displayCart();

//     std::cout << "Discount: Rs. " << discount << '\n';
//     std::cout << "Final Amount: Rs. " << finalAmount << '\n';

//     Customer customer(1, "Joyandrew");
//     LoyaltyService loyaltyService;
//     OrderService orderService;

//     Order order = orderService.checkout(
//         101,
//         customer,
//         cart,
//         pricingservice,
//         loyaltyService);

//     std::cout << "\n--- Order Details ---\n";
//     std::cout << "Order ID     : " << order.getOrderId() << '\n';
//     std::cout << "Customer ID  : " << order.getCustomerId() << '\n';
//     std::cout << "Total Amount : Rs. "
//               << order.getTotalAmount() << '\n';

//     // Customer cus(1,"Joyandrew");
//     // LoyaltyService loy;

//     // std::cout<<"Customer : "<<cus.getName()<<'\n';
//     // std::cout<<"Initial Points : "<<cus.getLoyaltyPoints()<<'\n';

//     // loy.awardPoints(cus,452.00);

//     // std::cout<<"Points after Purchase : "<<cus.getLoyaltyPoints()<<'\n';

//     //     Product milk(101, "Milk", 55.2);
//     //     Product bread(102,"Bread",35.2);

//     //     ShoppingCart cart;

//     //     cart.addProduct(milk);
//     //     cart.addProduct(bread);
//     //     cart.addProduct(milk);

//     //    cart.displayCart();
//     // Create a delivery for the order

//     // Create a delivery partner
//     DeliveryPartner partner(
//         10,
//         "Arun",
//         "9876543210");

//     std::cout << "\n--- Delivery Partner Details ---\n";

//     std::cout << "Partner ID   : "
//               << partner.getPartnerId() << '\n';

//     std::cout << "Name         : "
//               << partner.getName() << '\n';

//     std::cout << "Phone Number : "
//               << partner.getPhoneNumber() << '\n';

//     std::cout << "Available    : "
//               << (partner.isAvailable() ? "Yes" : "No") << '\n';

//     // Change availability
//     partner.setAvailability(false);

//     std::cout << "Availability after update: "
//               << (partner.isAvailable() ? "Yes" : "No") << '\n';

//     Delivery delivery(501, order.getOrderId(), 10);

//     std::cout << "\n--- Delivery Details ---\n";

//     std::cout << "Delivery ID : "
//               << delivery.getDeliveryId() << '\n';

//     std::cout << "Order ID    : "
//               << delivery.getOrderId() << '\n';

//     std::cout << "Partner ID  : "
//               << delivery.getPartnerId() << '\n';

//     std::cout << "Status      : "
//               << delivery.getStatus() << '\n';

//     // Update delivery status
//     if (delivery.updateStatus("In Transit"))
//     {
//         std::cout << "Updated Status: "
//                   << delivery.getStatus() << '\n';
//     }
//     else
//     {
//         std::cout << "Invalid status transition!\n";
//     }

//     // Test an invalid transition
//     if (delivery.updateStatus("Assigned"))
//     {
//         std::cout << "Updated Status: "
//                   << delivery.getStatus() << '\n';
//     }
//     else
//     {
//         std::cout << "Invalid status transition rejected!\n";
//     }

//     return 0;
// }

#include <iostream>
#include <iomanip>

#include "models/Product.hpp"
#include "models/ShoppingCart.hpp"
#include "models/Customer.hpp"
#include "models/Order.hpp"
#include "models/Delivery.hpp"
#include "models/DeliveryPartner.hpp"

#include "services/LoyaltyService.hpp"
#include "services/PricingService.hpp"
#include "services/OrderService.hpp"
#include "services/DeliveryService.hpp"


#include "services/PricingService.hpp"
#include "strategies/NoDiscountStrategy.hpp"
#include "strategies/PercentageDiscountStrategy.hpp"

int main()
{
    // 1. Create products
    Product milk(1, "Milk", 55.20);
    Product bread(2, "Bread", 35.20);

    // 2. Add products to cart
    ShoppingCart cart;
    cart.addProduct(milk);
    cart.addProduct(bread);
    cart.addProduct(milk);

    cart.displayCart();

    // 3. Calculate pricing
        PricingService pricingService;
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
    std::cout << "Total Amount : Rs. "
              << order.getTotalAmount() << '\n';

    std::cout << "Loyalty Points: "
              << customer.getLoyaltyPoints() << '\n';

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
            delivery, partner, "In Transit"))
    {
        std::cout << "Status updated to: "
                  << delivery.getStatus() << '\n';
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
            delivery, anotherPartner, "In Transit"))
    {
        std::cout << "Unauthorized update succeeded!\n";
    }
    else
    {
        std::cout << "Unauthorized update rejected!\n";
    }

    std::cout << "Delivery Status: "
              << delivery.getStatus() << '\n';

    // 8. Try an invalid status transition
    if (deliveryService.updateDeliveryStatus(
            delivery, partner, "Assigned"))
    {
        std::cout << "Status updated to: "
                  << delivery.getStatus() << '\n';
    }
    else
    {
        std::cout << "Invalid status transition rejected!\n";
    }

    // 9. Complete delivery
    if (deliveryService.updateDeliveryStatus(
            delivery, partner, "Delivered"))
    {
        std::cout << "Status updated to: "
                  << delivery.getStatus() << '\n';
    }
    else
    {
        std::cout << "Delivery completion failed!\n";
    }

    std::cout << "Partner Available After Delivery: "
              << (partner.isAvailable() ? "Yes" : "No") << '\n';

    return 0;
}
