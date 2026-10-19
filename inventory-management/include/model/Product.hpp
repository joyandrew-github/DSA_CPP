#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <stdexcept>
#include <string>

class Product {
private:
  std::string id;
  std::string name;
  int stockQuantity;
  int minimumStockLevel;
  std::string categoryId; // Added categoryId member variable

public:
  Product(const std::string &id, const std::string &name,
          const int stockQuantity, const int minimumStockLevel,const std::string &categoryId)
      : id(id), name(name), stockQuantity(stockQuantity),
        minimumStockLevel(minimumStockLevel), categoryId(categoryId) {
    if (id.empty()) {
      throw std::invalid_argument("Product ID cannot be empty");
    }
    if (name.empty()) {
      throw std::invalid_argument("Name cannot be empty");
    }
    if (stockQuantity < 0 || minimumStockLevel < 0) {
      throw std::invalid_argument("Stock quantities cannot be negative");
    }
    if(categoryId.empty()) {
      throw std::invalid_argument("Category ID cannot be empty");
    }
  }
  // Getters for the product attributes
  const std::string &getName() const { return name; }
  const std::string &getId() const { return id; }
  const std::string &getCategoryId()const {return categoryId;}
  // Getters for stock quantity and minimum stock level
  int getStockQuantity() const { return stockQuantity; }
  int getMinimumStockLevel() const { return minimumStockLevel; }
  // Check if the product is low in stock
  bool isLowStock() const { return stockQuantity < minimumStockLevel; }
  // Get the required stock to reach the minimum stock level
  int getRequiredStock() const {
    if (isLowStock()) {
      return minimumStockLevel - stockQuantity;
    }
    return 0;
  }
  // Methods to add and remove stock, and set minimum stock level
  void addStock(int quantity) {
    if (quantity <= 0) {
      throw std::invalid_argument("Added Quantity must be positive");
    }
    stockQuantity += quantity;
  }
  void removeStock(int quantity) {
    if (quantity <= 0) {
      throw std::invalid_argument("Removed Quantity must be Positive");
    }
    if (quantity > stockQuantity) {
      throw std::invalid_argument("Insufficient stock");
    }
    stockQuantity -= quantity;
  }
  /// Set the minimum stock level for the product
  void setMinimumStockLevel(int minimumStockLevel) {
    if (minimumStockLevel < 0) {
      throw std::invalid_argument("Minimum stock level cannot be negative");
    }
    this->minimumStockLevel = minimumStockLevel;
  }
};
#endif
