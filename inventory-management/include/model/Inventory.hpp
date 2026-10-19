#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <unordered_map> // for std::unordered_map
#include "Product.hpp"
#include <string>   // for std::string
#include <stdexcept> // for std::invalid_argument
#include <cstddef> // for std::size_t
#include <vector>  // for std::vector

class Inventory{
private:
    std::unordered_map<std::string, Product> products;
public:
// Add a product to the inventory. Throws an exception if a product with the same ID already exists.
    void addProduct(const Product& product){
        auto res=products.emplace(product.getId(), product);
        if(!res.second){
            throw std::invalid_argument("Product with ID "+product.getId()+" already exists in inventory");
        }
    }
// Get a product by its ID. Throws an exception if the product is not found.
    Product& getProduct(const std::string& id){
        auto it=products.find(id);
        if(it==products.end()){
            throw std::invalid_argument("Product not found: "+id);
        }
        return it->second;
    }
// Get a const reference to a product by its ID. Throws an exception if the product is not found.
    const Product& getProduct(const std::string& id) const{
        auto it=products.find(id);
        if(it==products.end()){
            throw std::invalid_argument("Product not found: "+id);
        }
        return it->second;
    }

// Remove a product from the inventory by its ID. Throws an exception if the product is not found.
    void removeProduct(const std::string& id){
        auto it=products.find(id);
        if(it==products.end()){
            throw std::invalid_argument("Product not found: "+id);
        }
        products.erase(it);
    }
// Get the total number of products in the inventory.
    std::size_t getProductCount() const{
        return products.size();
    }
// Get all products in the inventory as a const reference to the unordered_map.
    const std::unordered_map<std::string, Product>& getAllProducts() const{
        return products;
    }
// Get a list of products that are low in stock.
    std::vector<Product> getLowStockProducts()const{
        std::vector<Product> lowStockProducts;
        //this loop visits each product without making an unnecessary copy of every map entry.
        for(const auto& entry:products){
            if(entry.second.isLowStock()){
                lowStockProducts.push_back(entry.second);
            }
        }
        return lowStockProducts;
    }
// Get a list of products that belong to a specific category.
    std::vector<Product> getProductsByCategory(const std::string& categoryId)const{
        // Create a vector to hold products that match the specified category ID
        std::vector<Product> categoryProducts;
        //this loop visits each product without making an unnecessary copy of every map entry.
        for(const auto& entry:products){
            if(entry.second.getCategoryId()==categoryId){
                categoryProducts.push_back(entry.second);
            }
        }
        return categoryProducts;
    }
// Restock a product by its ID. Throws an exception if the product is not found.
    void restockProduct(const std::string& id,int quantity) {
        getProduct(id).addStock(quantity);
    }
// Sell a product by its ID. Throws an exception if the product is not found or if there is insufficient stock.
    void sellProduct(const std::string& id,int quantity){
        getProduct(id).removeStock(quantity);
    }
};

#endif