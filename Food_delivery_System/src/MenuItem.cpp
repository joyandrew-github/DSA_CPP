#include "model/MenuItem.hpp"
#include <stdexcept>

MenuItem::MenuItem(int itemId, const std::string &itemName, std::int64_t priceInPaise) : itemId(itemId),
                                                                                         itemName(itemName),
                                                                                         priceInPaise(priceInPaise),
                                                                                         available(true)
{
    if (itemId <= 0 || itemName.empty() || priceInPaise < 0)
    {
        throw std::invalid_argument("Invalid menu item details");
    }
}

// Getters
int MenuItem::getItemId() const
{
    return itemId;
}

std::string MenuItem::getItemName() const
{
    return itemName;
}

std::int64_t MenuItem::getPriceInPaise() const
{
    return priceInPaise;
}

bool MenuItem::isAvailable() const
{
    return available;
}

// Setters
void MenuItem::setItemName(const std::string &newItemName)
{
    if (newItemName.empty())
    {
        throw std::invalid_argument("New Item Name Cannot be empty");
    }
    itemName = newItemName;
}

void MenuItem::setItemPrice(std::int64_t newPriceInPaise)
{
    if (newPriceInPaise < 0)
    {
        throw std::invalid_argument("Price cannot be negative");
    }
    priceInPaise = newPriceInPaise;
}

void MenuItem::setAvailable(bool available)
{
    this->available = available;
    // The purpose of this line is to set the availability status of the menu item. The 'available' parameter passed to the function indicates whether the menu item is available for order or not. By assigning this value to the member variable 'available', we update the state of the MenuItem object to reflect its current availability status.
}