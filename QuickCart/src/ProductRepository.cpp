
#include "repositories/ProductRepository.hpp"

ProductRepository::ProductRepository() {
    products.emplace_back(101, "Milk", 55.20);
    products.emplace_back(102, "Bread", 35.20);
    products.emplace_back(103, "Eggs", 72.00);
    products.emplace_back(104, "Rice", 120.00);
}

std::vector<Product> ProductRepository::getAllProducts() const {
    return products;
}
