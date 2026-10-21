#pragma once
#include <string>
#include <vector>
#include "MenuItem.hpp"

class Restaurant{
private:   
    int restaurantId;
    std::string restaurantName;
    std::vector<MenuItem> menuItems;
public:
    Restaurant(int restaurantId, const std::string &restaurantName);

    // Getters
    int getRestaurantId() const;
    std::string getRestaurantName() const;
    const std::vector<MenuItem>& getMenuItems() const;

    // Setters
    void setRestaurantName(const std::string &newRestaurantName);

    //Menu Item Management
    void addMenuItem(const MenuItem &menuItem);
    bool removeMenuItem(int itemId);
    
    // Find a menu item by its ID
    const MenuItem* findMenuItemById(int itemId) const;

};