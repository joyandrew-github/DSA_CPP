#include <iostream>
#include <iomanip>
#include "models/Product.hpp"
#include "models/ShoppingCart.hpp"
#include "models/Customer.hpp"
#include "models/Order.hpp"
#include "services/LoyaltyService.hpp"
#include "services/PricingService.hpp"

int main()
{
    Product milk(101, "Milk", 55.2);
    Product bread(102, "Bread", 35.2);

    ShoppingCart cart;

    cart.addProduct(milk);
    cart.addProduct(bread);
    cart.addProduct(milk);

    PricingService pricingservice;

    double subtotal = cart.getSubTotal();

    double discount = pricingservice.calculateDiscount(subtotal);
    double finalAmount = pricingservice.calculateFinalAmount(subtotal);

    std::cout << std::fixed << std::setprecision(2);

    cart.displayCart();

    std::cout << "Subtotal: Rs. " << subtotal << '\n';
    std::cout << "Discount: Rs. " << discount << '\n';
    std::cout << "Final Amount: Rs. " << finalAmount << '\n';

    Order order(101, 1, finalAmount);

    std::cout << "\n--- Order Details ---\n";
    std::cout << "Order ID     : " << order.getOrderId() << '\n';
    std::cout << "Customer ID  : " << order.getCustomerId() << '\n';
    std::cout << "Total Amount : Rs. "
              << order.getTotalAmount() << '\n';

    // Customer cus(1,"Joyandrew");
    // LoyaltyService loy;

    // std::cout<<"Customer : "<<cus.getName()<<'\n';
    // std::cout<<"Initial Points : "<<cus.getLoyaltyPoints()<<'\n';

    // loy.awardPoints(cus,452.00);

    // std::cout<<"Points after Purchase : "<<cus.getLoyaltyPoints()<<'\n';

    //     Product milk(101, "Milk", 55.2);
    //     Product bread(102,"Bread",35.2);

    //     ShoppingCart cart;

    //     cart.addProduct(milk);
    //     cart.addProduct(bread);
    //     cart.addProduct(milk);

    //    cart.displayCart();

    return 0;
}
