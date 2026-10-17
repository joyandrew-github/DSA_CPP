#pragma once
#include <string>

class Delivery
{
private:
    int deliveryId;
    int orderId;
    int partnerId;
    std::string status;

public:
    Delivery(int deliveryId, int orderId, int partnerId);

    int getDeliveryId() const;
    int getOrderId() const;
    int getPartnerId() const;
    std::string getStatus() const;

    bool updateStatus(const std::string &newStatus);
};