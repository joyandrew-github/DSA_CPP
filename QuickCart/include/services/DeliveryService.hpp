#pragma once

#include "models/Delivery.hpp"
#include "models/DeliveryPartner.hpp"

class DeliveryService{
public:
    bool assignDelivery(
        Delivery& delivery,
        DeliveryPartner& partner
    )const;
    bool updateDeliveryStatus(
        Delivery& delivery,
        DeliveryPartner& partner,
        DeliveryStatus newStatus
    )const;
};