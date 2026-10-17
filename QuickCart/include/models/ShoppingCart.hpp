#pragma once

#include <vector>
#include "models/CartItem.hpp"

class ShoppingCart{
private:
    std::vector<CartItem>items;
    // std::vector<Product>products;//stores multiple Product objects. //Composition is a design principle where one class contains objects of another class as member variables. In this case, the ShoppingCart class contains a vector of Product objects, indicating that a shopping cart can hold multiple products.
    //Has-a relationship: ShoppingCart has a vector of Product objects. This is an example of composition, where one class is composed of other classes.
public:
    void addProduct(const Product& product); //stores multiple Product objects.

    void displayCart() const;
    double getSubTotal() const;
};