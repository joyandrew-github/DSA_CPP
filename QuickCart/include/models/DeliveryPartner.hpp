#pragma once

#include <string>

class DeliveryPartner{
private:
    int partnerId;
    std::string name;
    std::string phoneNumber;
    bool available;

public:
    DeliveryPartner(
        int partnerId,
        const std::string& name,
        const std::string& phoneNumber
    );

    int getPartnerId()const;
    std::string getName() const;
    std::string getPhoneNumber() const;
    bool isAvailable() const;


    void setAvailability(bool available);
};