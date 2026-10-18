
#include "repositories/ProductRepository.hpp"
#include "constants.hpp"

ProductRepository::ProductRepository() {
    products.emplace_back(quickcart::PRODUCT_ID_MILK, "Milk", quickcart::MILK_PRICE);
    products.emplace_back(quickcart::PRODUCT_ID_BREAD, "Bread", quickcart::BREAD_PRICE);
    products.emplace_back(quickcart::PRODUCT_ID_EGGS, "Eggs", quickcart::EGGS_PRICE);
    products.emplace_back(quickcart::PRODUCT_ID_RICE, "Rice", quickcart::RICE_PRICE);
}

std::vector<Product> ProductRepository::getAllProducts() const {
    return products;
}
