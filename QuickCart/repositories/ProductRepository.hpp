#pragma once
#include <vector>
#include "models/Product.hpp"

class ProductRepository {
private:
    std::vector<Product> products;

public:
    ProductRepository();

    std::vector<Product> getAllProducts() const;
};

