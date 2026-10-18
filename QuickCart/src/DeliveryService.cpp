#include "services/DeliveryService.hpp"

bool DeliveryService::assignDelivery(
    Delivery &delivery,
    DeliveryPartner &partner) const
{
    if (!partner.isAvailable())
    {
        return false;
    }

    if (delivery.getPartnerId() != partner.getPartnerId())
    {
        return false;
    }
    partner.setAvailability(false);
    return true;
};

bool DeliveryService::updateDeliveryStatus(
    Delivery &delivery,
    DeliveryPartner &partner,
    DeliveryStatus newStatus) const
{
    if (!delivery.updateStatus(newStatus))
    {
        return false;
    }

    if (newStatus == DeliveryStatus::Delivered)
    {
        partner.setAvailability(true);
    }

    return true;
}
