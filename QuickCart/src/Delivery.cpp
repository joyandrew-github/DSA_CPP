#include "models/Delivery.hpp"

Delivery::Delivery(int deliveryId, int orderId, int partnerId)
    : deliveryId(deliveryId), orderId(orderId), partnerId(partnerId),
      status(DeliveryStatus::Assigned) {}

int Delivery::getDeliveryId() const {
    return deliveryId;
}

int Delivery::getOrderId() const {
    return orderId;
}

int Delivery::getPartnerId() const {
    return partnerId;
}

DeliveryStatus Delivery::getStatus() const {
    return status;
}

std::string Delivery::getStatusString() const {
    return deliveryStatusToString(status);
}

bool Delivery::updateStatus(DeliveryStatus newStatus)
{
    if (status == DeliveryStatus::Assigned &&
        newStatus == DeliveryStatus::InTransit)
    {
        status = newStatus;
        return true;
    }

    if (status == DeliveryStatus::InTransit &&
        newStatus == DeliveryStatus::Delivered)
    {
        status = newStatus;
        return true;
    }

    return false;
}