#include <iostream>
#include <string>
#include <vector>

#include "model/Inventory.hpp"
#include "model/Product.hpp"
#include "seedData/staticData.hpp"

int main() {
  Inventory inventory;

  Product lap("101", "Laptop", 10, 5, "C001");
  Product mouse("102", "Mouse", 5, 15, "C002");

  inventory.addProduct(lap);
  inventory.addProduct(mouse);

  const Inventory &readOnlyInventory = inventory;

  const Product &readOnlyMouse = readOnlyInventory.getProduct("102");

  std::cout << "Read-only product: " << readOnlyMouse.getName() << '\n';

  std::cout << "Read-only stock: " << readOnlyMouse.getStockQuantity() << '\n';

  std::cout << "Total Products : " << inventory.getProductCount() << '\n';

  Product &foundProduct = inventory.getProduct("102");
  std::cout << " Product Name :" << foundProduct.getName() << '\n';

  std::cout << "Get Stock Quantity :" << foundProduct.getStockQuantity()
            << '\n';

  inventory.restockProduct("102", 15);
  std::cout << "Stock after Restocking : "
            << inventory.getProduct("102").getStockQuantity() << '\n';

  inventory.sellProduct("102", 7);
  std::cout << "Stock after Selling :"
            << inventory.getProduct("102").getStockQuantity() << '\n';

  inventory.getProduct("102").setMinimumStockLevel(20);

  std::cout << "Updated minimum stock level: "
            << inventory.getProduct("102").getMinimumStockLevel() << '\n';

  std::vector<Product> lowStockProducts = inventory.getLowStockProducts();

  std::cout << "\nLow Stock Products:\n";

  for (const auto &product : lowStockProducts) {
    std::cout << "Product Name: " << product.getName()
              << ", Stock: " << product.getStockQuantity()
              << ", Minimum Stock: " << product.getMinimumStockLevel() << '\n';
  }

  try {
    inventory.sellProduct("102", 100);
  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << '\n';
  }

  try {
    Product anotherMouse("102", "Wireless Mouse", 8, 3, "C002");
    inventory.addProduct(anotherMouse);
  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << '\n';
  }

  try {
    inventory.removeProduct("101");

    std::cout << "Product removed successfully\n";
    std::cout << "Total Products after removal: " << inventory.getProductCount()
              << '\n';
  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << '\n';
  }

  try {
    inventory.removeProduct("999");
  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << '\n';
  }

  std::cout << "Total Products: " << inventory.getProductCount() << '\n';

  try {
    inventory.restockProduct("102", -5);
  } catch (const std::invalid_argument &e) {
    std::cout << "Invalid restock: " << e.what() << '\n';
  }

  try {
    inventory.restockProduct("102", 0);
  } catch (const std::invalid_argument &e) {
    std::cout << "Zero quantity rejected: " << e.what() << '\n';
  }

  return 0;
}
