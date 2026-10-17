#include "models/DeliveryPartner.hpp"

DeliveryPartner::DeliveryPartner(
    int partnerId,
    const std::string& name,
    const std::string& phoneNumber
):partnerId(partnerId),
name(name),
phoneNumber(phoneNumber),
available(true){}


int DeliveryPartner::getPartnerId()const{
    return partnerId;
}

std::string DeliveryPartner::getName()const{
    return name;
}

std::string DeliveryPartner::getPhoneNumber()const{
    return phoneNumber;
}

bool DeliveryPartner::isAvailable() const
{
    return available;
}

void DeliveryPartner::setAvailability(bool available){
    this->available=available;
}


//Here, both names refer to available, but they mean different things:
// - this->available refers to the object's member variable.
// - available refers to the function parameter.