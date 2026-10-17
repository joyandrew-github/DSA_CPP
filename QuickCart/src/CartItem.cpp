#include "models/CartItem.hpp"

CartItem::CartItem(const Product& product,int quantity)
            :product(product),quantity(quantity){}

const Product& CartItem::getProduct() const{
    return product;
}

int CartItem::getQuantity()const{
    return quantity;
}

void CartItem::increaseQuantity(int amount){
    if(amount>0){
        quantity+=amount;
    }
}

double CartItem::getTotalPrice() const{
    return product.getPrice()*quantity;
}