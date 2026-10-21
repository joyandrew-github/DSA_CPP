#include "model/OrderItem.hpp"
#include <stdexcept>
#include <cstdint>

OrderItem::OrderItem(const MenuItem &menuItem,int quantity): menuItem(menuItem),quantity(quantity){
    if(quantity <= 0){
        throw std::invalid_argument("Quantity must be positive");
    }
}

const MenuItem& OrderItem::getMenuItem()const{
    return menuItem;
}

int OrderItem::getQuantity()const{
    return quantity;
}

void OrderItem::setQuantity(int newQuantity){
    if(newQuantity <= 0){
        throw std::invalid_argument("Quantity must be positive");
    }
    quantity = newQuantity;
}

std::int64_t OrderItem::getSubTotalInPaise()const{
    return menuItem.getPriceInPaise()*quantity;
}


