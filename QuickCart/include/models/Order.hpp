#pragma once

class Order{
private:
    int orderId;
    int customerId;
    double totalAmount;

public:
    Order(int orderId,int CustomerId,double totalAmount);

    int getOrderId()const;
    int getCustomerId()const;
    double getTotalAmount()const;

};