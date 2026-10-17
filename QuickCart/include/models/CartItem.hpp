#pragma once
#include "models/Product.hpp"

class CartItem{
private:
    Product product; //Composition: CartItem has a Product object. This is an example of composition, where one class is composed of other classes.
    int quantity; //The quantity of the product in the cart item.
public:
    CartItem(const Product& product,int quantity=1);//if no quantity is provided, it defaults to one.
    
    const Product& getProduct() const;
    int getQuantity() const;

    void increaseQuantity(int amount=1);

    double getTotalPrice()const; //calculates product price × quantity.
};