#include "models/Order.hpp"

Order::Order(int orderId,int customerId,double totalAmount)
        :orderId(orderId),
        customerId(customerId),
        totalAmount(totalAmount){}

int Order::getOrderId()const{
    return orderId;
}

int Order::getCustomerId()const{
    return customerId;
}

double Order::getTotalAmount()const{
    return totalAmount;
}