#pragma once
#include <string>
#include <cstdint>

class MenuItem{
private:
    int itemId;
    std::string itemName;
    std::int64_t priceInPaise;
    bool available;

public:
    MenuItem(int itemId,const std::string&itemName,std::int64_t priceInPaise);

    //getters
    int getItemId()const;
    std::string getItemName()const;
    std::int64_t getPriceInPaise()const;
    bool isAvailable()const;

    //setters
    void setItemName(const std::string& newItemName);
    void setItemPrice(std::int64_t newPriceInPaise);
    void setAvailable(bool available);
};