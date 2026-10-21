#pragma once
#include "model/MenuItem.hpp"

class OrderItem{
private:
    MenuItem menuItem;
    int quantity;

public:
    OrderItem(const MenuItem &menuItem,int quantity);

    //Getters
    const MenuItem& getMenuItem()const;
    int getQuantity()const;

    //Setters
    void setQuantity(int newQuantity);

    std::int64_t getSubTotalInPaise()const;

};