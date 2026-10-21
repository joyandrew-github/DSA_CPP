#pragma once

#include "model/Customer.hpp"
#include "model/OrderItem.hpp"
#include <vector>
#include <cstdint>

enum class OrderStatus
{
    PENDING,
    CONFIRMED,
    PREPARING,
    OUT_FOR_DELIVERY,
    DELIVERED,
    CANCELLED
};

class Order
{
private:
    int orderId;
    Customer customer;
    std::vector<OrderItem> orderItems;
    OrderStatus status;
public:
    Order(int orderId,const Customer &customer);

    // Getters
    int getOrderId() const;
    const Customer& getCustomer() const;
    const std::vector<OrderItem>& getOrderItems() const;
    OrderStatus getStatus() const;

    // Setters
    void addItem(const OrderItem &orderItem);
    bool removeItem(int itemId);

    //total cost of the order in paise
    std::int64_t getTotalCostInPaise() const;

    //status management
    void setStatus(OrderStatus newStatus);
};