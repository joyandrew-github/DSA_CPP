#include <iostream>
#include <iomanip>
#include "models/ShoppingCart.hpp"

// add Products
void ShoppingCart::addProduct(const Product &product)
{
    // products.push_back(product);
    for (CartItem &item : items)
    {
        if (item.getProduct().getId() == product.getId())
        {
            item.increaseQuantity();
            return;
        }
    }
    items.emplace_back(product);
}

void ShoppingCart::displayCart() const
{
    std::cout << "\n--- Shopping Cart ---\n";
    std::cout << "Items in the cart:\n";
    std::cout << std::fixed << std::setprecision(2);

    for (const CartItem &item : items)
    {
        const Product &product = item.getProduct();
        std::cout << product.getName()
                  << " x " << item.getQuantity()
                  << " - Rs. " << item.getTotalPrice() << '\n';
    }

    std::cout << "SubTotal Rs. " << getSubTotal() << '\n';
}

double ShoppingCart::getSubTotal() const
{
    double subTotal = 0.0;

    for (const CartItem &item : items)
    {
        subTotal += item.getTotalPrice();
    }
    return subTotal;
}