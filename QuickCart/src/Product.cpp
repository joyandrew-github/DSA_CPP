#pragma once
#include "models/Product.hpp"

// The constructor uses a member initializer list:
// The values on the left are the object's member variables; the values on the right are the constructor parameters.
Product::Product(int id, const std::string &name, double price)
    : id(id), name(name), price(price) {}

int Product::getId() const
{
    return id;
}

std::string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}
