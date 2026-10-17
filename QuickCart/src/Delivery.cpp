#include "models/Delivery.hpp"

Delivery::Delivery(int deliveryId,int orderId,int partnerId)
:deliveryId(deliveryId),orderId(orderId),partnerId(partnerId),status("Assigned"){}

int Delivery::getDeliveryId()const{
    return deliveryId;
}

int Delivery::getOrderId()const{
    return orderId;
}

int Delivery::getPartnerId()const{
    return partnerId;
}

std::string Delivery::getStatus()const{
    return status;
}

bool Delivery::updateStatus(const std::string& newStatus)
{
    if (status == "Assigned" &&
        newStatus == "In Transit")
    {
        status = newStatus;
        return true;
    }

    if (status == "In Transit" &&
        newStatus == "Delivered")
    {
        status = newStatus;
        return true;
    }

    return false;
}