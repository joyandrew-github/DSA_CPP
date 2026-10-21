#include "model/Restaurant.hpp"
#include <stdexcept>
#include <algorithm>

Restaurant::Restaurant(int restaurantId, const std::string &restaurantName) : restaurantId(restaurantId),
                                                                              restaurantName(restaurantName)
{
    if (restaurantId <= 0)
    {
        throw std::invalid_argument("Restaurant ID must be positive");
    }
    if (restaurantName.empty())
    {
        throw std::invalid_argument("Restaurant Name cannot be empty");
    }
}

int Restaurant::getRestaurantId() const
{
    return restaurantId;
}

std::string Restaurant::getRestaurantName() const
{
    return restaurantName;
}

const std::vector<MenuItem> &Restaurant::getMenuItems() const
{
    return menuItems;
}

void Restaurant::setRestaurantName(const std::string &newRestaurantName)
{
    if (newRestaurantName.empty())
    {
        throw std::invalid_argument("New Restaurant Name cannot be empty");
    }
    restaurantName = newRestaurantName;
}
// Menu Item Management
void Restaurant::addMenuItem(const MenuItem &menuItem)
{
    auto it = std::find_if(menuItems.begin(),
                           menuItems.end(),
                           [&menuItem](const MenuItem &item)
                           {
                               return item.getItemId() == menuItem.getItemId();
                           });
    if (it == menuItems.end())
    {
        menuItems.push_back(menuItem);
    }
    else
    {
        throw std::invalid_argument("Menu Item with the same ID already exists");
    }
}

bool Restaurant::removeMenuItem(int itemId)
{
    auto it = std::find_if(menuItems.begin(),
                           menuItems.end(),
                           [&itemId](const MenuItem &item)
                           {
                               return item.getItemId() == itemId;
                           });
    if (it == menuItems.end())
    {
        return false; // Item not found
    }
    else
    {
        menuItems.erase(it);
        return true; // Item removed
    }
}

const MenuItem *Restaurant::findMenuItemById(int itemId) const
{
    auto it = std::find_if(menuItems.begin(),
                           menuItems.end(),
                           [&itemId](const MenuItem &item)
                           {
                               return item.getItemId() == itemId;
                           }

    );
    if (it == menuItems.end())
    {
        return nullptr;
    }
    return &(*it);
}