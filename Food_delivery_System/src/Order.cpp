#include "model/Order.hpp"
#include <stdexcept>
#include <cstdint>
#include <vector>
#include <algorithm>

Order::Order(int orderId, const Customer &customer) : orderId(orderId), customer(customer), status(OrderStatus::PENDING)
{
    if (orderId <= 0)
    {
        throw std::invalid_argument("Order ID must be positive");
    }
}

int Order::getOrderId() const
{
    return orderId;
}

const Customer &Order::getCustomer() const
{
    return customer;
}

const std::vector<OrderItem> &Order::getOrderItems() const
{
    return orderItems;
}

void Order::addItem(const OrderItem &orderItem)
{
    int itemId=orderItem.getMenuItem().getItemId();

    auto it=std::find_if(
        orderItems.begin(),
        orderItems.end(),
        [&itemId](const OrderItem& item){
            return item.getMenuItem().getItemId()==itemId;
        }
    );
    if(it!=orderItems.end()){
        throw std::invalid_argument("Item already exists in the order. Use setQuantity to update the quantity.");
    }
    orderItems.push_back(orderItem);
}


//remove item from order by itemId