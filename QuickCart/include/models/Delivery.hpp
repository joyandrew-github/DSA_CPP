#pragma once
#include <string>

enum class DeliveryStatus {
    Assigned,
    InTransit,
    Delivered
};

inline std::string deliveryStatusToString(DeliveryStatus status) {
    switch (status) {
        case DeliveryStatus::Assigned:    return "Assigned";
        case DeliveryStatus::InTransit:   return "In Transit";
        case DeliveryStatus::Delivered:   return "Delivered";
        default:                          return "Unknown";
    }
}

class Delivery
{
private:
    int deliveryId;
    int orderId;
    int partnerId;
    DeliveryStatus status;

public:
    Delivery(int deliveryId, int orderId, int partnerId);

    int getDeliveryId() const;
    int getOrderId() const;
    int getPartnerId() const;
    DeliveryStatus getStatus() const;
    std::string getStatusString() const;

    bool updateStatus(DeliveryStatus newStatus);
};