#include "model/Inventory.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(InventoryTest, AddProductIncreasesCount) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");

  inventory.addProduct(laptop);

  EXPECT_EQ(inventory.getProductCount(), 1);
}

TEST(InventoryTest, AddProductThrowsWhenDuplicateId) {
  Inventory inventory;
  Product laptop1("101", "Laptop", 10, 5, "C001");
  Product laptop2("101", "Laptop Pro", 5, 3, "C002");

  inventory.addProduct(laptop1);

  EXPECT_THROW(inventory.addProduct(laptop2), std::invalid_argument);
}

TEST(InventoryTest, GetProductReturnsCorrectProduct) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  Product &retrievedProduct = inventory.getProduct("101");

  EXPECT_EQ(retrievedProduct.getName(), "Laptop");
  EXPECT_EQ(retrievedProduct.getStockQuantity(), 10);
}

TEST(InventoryTest, GetProductThrowsWhenNotFound) {
  Inventory inventory;

  EXPECT_THROW(inventory.getProduct("999"), std::invalid_argument);
}

TEST(InventoryTest, RestockProductIncreasesStock) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  inventory.restockProduct("101", 5);

  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 15);
}

TEST(InventoryTest, SellProductDecreasesStock) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  inventory.sellProduct("101", 3);
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 7);
}

TEST(InventoryTest, GetLowStockProductsReturnsOnlyLowStockItems) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  Product mouse("102", "Mouse", 3, 5, "C002");

  inventory.addProduct(laptop);
  inventory.addProduct(mouse);

  std::vector<Product> lowStockProducts = inventory.getLowStockProducts();

  EXPECT_EQ(lowStockProducts.size(), 1);
  EXPECT_EQ(lowStockProducts[0].getName(), "Mouse");
}

TEST(InventoryTest, GetLowStockProductsReturnsEmptyWhenStockIsAtMinimum) {
  Inventory inventory;
  Product keyboard("103", "Keyboard", 5, 5, "C003");
  inventory.addProduct(keyboard);
  std::vector<Product> lowStockProducts = inventory.getLowStockProducts();

  EXPECT_TRUE(lowStockProducts.empty());
}

TEST(InventoryTest, SellProductThrowsWhenInsufficientStock) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  EXPECT_THROW(inventory.sellProduct("101", 15), std::invalid_argument);

  // Ensure stock quantity remains unchanged after failed sell attempt
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 10);
}

TEST(InventoryTest, RestockProductThrowsWhenQuantityIsZero) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  EXPECT_THROW(inventory.restockProduct("101", 0), std::invalid_argument);

  // Ensure stock quantity remains unchanged after failed restock attempt
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 10);
}

TEST(InventoryTest, RestockProductThrowsWhenQuantityIsNegative) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  EXPECT_THROW(inventory.restockProduct("101", -5), std::invalid_argument);

  // Ensure stock quantity remains unchanged after failed restock attempt
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 10);
}

TEST(InventoryTest, SellProductThrowsWhenQuantityIsZero) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  EXPECT_THROW(inventory.sellProduct("101", 0), std::invalid_argument);

  // Ensure stock quantity remains unchanged after failed sell attempt
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 10);
}

TEST(InventoryTest, SellProductThrowsWhenQuantityIsNegative) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  EXPECT_THROW(inventory.sellProduct("101", -5), std::invalid_argument);

  // Ensure stock quantity remains unchanged after failed sell attempt
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 10);
}

TEST(InventoryTest, RemoveProductDecreasesProductCount) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  inventory.removeProduct("101");

  EXPECT_EQ(inventory.getProductCount(), 0);
}

TEST(InventoryTest, RemoveProductThrowsWhenNotFound) {
  Inventory inventory;

  EXPECT_THROW(inventory.removeProduct("999"), std::invalid_argument);
}

TEST(InventoryTest, RemoveProductKeepsCountUnchangedWhenNotFound) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  EXPECT_THROW(inventory.removeProduct("999"), std::invalid_argument);

  EXPECT_EQ(inventory.getProductCount(), 1);
}

TEST(InventoryTest, SellProductSucceedsWhenSellingExactStock) {
  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  // Attempt to sell exactly the stock quantity
  EXPECT_NO_THROW(inventory.sellProduct("101", 10));

  // Check that the stock quantity is now 0
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 0);
}

TEST(InventoryTest,
     RestockProductThrowsWhenQuantityIsNegativeAndPreservesStock) {

  Inventory inventory;
  Product laptop("101", "Laptop", 10, 5, "C001");
  inventory.addProduct(laptop);

  EXPECT_THROW(inventory.restockProduct("101", -5), std::invalid_argument);

  // Ensure stock quantity remains unchanged after failed restock attempt
  EXPECT_EQ(inventory.getProduct("101").getStockQuantity(), 10);
}

TEST(InventoryTest, GetProductsByCategoryReturnsCorrectCount) {
  Inventory inventory;
  Product product1("101", "Laptop", 10, 5, "C001");
  Product product2("102", "Mouse", 3, 5, "C001");
  Product product3("103", "Keyboard", 5, 5, "C002");

  inventory.addProduct(product1);
  inventory.addProduct(product2);
  inventory.addProduct(product3);

  std::vector<Product> result = inventory.getProductsByCategory("C001");

  for (const auto &product : result) {
    EXPECT_EQ(product.getCategoryId(), "C001");
  }
  EXPECT_EQ(result.size(), 2);
}