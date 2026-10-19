
#include <gtest/gtest.h>
#include <stdexcept>

#include "model/Product.hpp"
#include "model/Inventory.hpp"

TEST(ProductTest, RemoveStockReducesQuantity) {
    Product laptop("101", "Laptop", 10, 5, "C001");

    laptop.removeStock(3);

    EXPECT_EQ(laptop.getStockQuantity(), 7);
}

TEST(ProductTest, RemoveStockThrowsWhenInsufficientStock) {
    Product laptop("101", "Laptop", 10, 5, "C001");

    EXPECT_THROW(laptop.removeStock(15), std::invalid_argument);

    EXPECT_EQ(laptop.getStockQuantity(), 10);
}

TEST(ProductTest, RemoveStockThrowsForZeroQuantity) {
    Product laptop("101", "Laptop", 10, 5, "C001");

    EXPECT_THROW(laptop.removeStock(0), std::invalid_argument);

    EXPECT_EQ(laptop.getStockQuantity(), 10);
}

TEST(ProductTest, AddStockIncreasesQuantity) {
    Product laptop("101", "Laptop", 10, 5, "C001");

    laptop.addStock(5);

    EXPECT_EQ(laptop.getStockQuantity(), 15);
}


TEST(ProductTest, ConstructorThrowsWhenIdIsEmpty) {
    EXPECT_THROW(
        Product("", "Laptop", 10, 5, "C001"),
        std::invalid_argument
    );
}

TEST(ProductTest, ConstructorThrowsWhenNameIsEmpty) {
    EXPECT_THROW(
        Product("101", "", 10, 5, "C001"),
        std::invalid_argument
    );
}

TEST(ProductTest, ConstructorThrowsWhenStockIsNegative) {
    EXPECT_THROW(
        Product("101", "Laptop", -1, 5, "C001"),
        std::invalid_argument
    );
}

TEST(ProductTest, ConstructorThrowsWhenMinimumStockIsNegative) {
    EXPECT_THROW(
        Product("101", "Laptop", 10, -1, "C001"),
        std::invalid_argument
    );
}

TEST(ProductTest,GetRequiredStockReturnsDifferenceWhenStockIsLow){
  
    Product mouse("102", "Mouse", 3, 5, "C002");
    EXPECT_EQ(mouse.getRequiredStock(), 2);
}

TEST(ProductTest,GetRequiredStockReturnsZeroWhenStockIsSufficient){

    Product keyboard("103", "Keyboard", 10, 5, "C003");
    EXPECT_EQ(keyboard.getRequiredStock(), 0);
}

TEST(ProductTest,SetMinimumStockLevelUpdatesValue){
    Product monitor("104", "Monitor", 10, 5, "C004");
    monitor.setMinimumStockLevel(8);
    EXPECT_EQ(monitor.getMinimumStockLevel(), 8);
}

//SetMinimumStockLevelThrowsWhenNegative
TEST(ProductTest,SetMinimumStockLevelThrowsWhenNegative){
    Product monitor("104", "Monitor", 10, 5, "C004");
    EXPECT_THROW(monitor.setMinimumStockLevel(-1),std::invalid_argument);
}


//RestockProductThrowsWhenProductNotFound
TEST(InventoryTest,RestockProductThrowsWhenProductNotFound){
    Inventory inventory;
    EXPECT_THROW(inventory.restockProduct("999", 5), std::invalid_argument);

    EXPECT_EQ(inventory.getProductCount(), 0);
}

//SellProductThrowsWhenProductNotFound
TEST(InventoryTest,SellProductThrowsWhenProductNotFound){
    Inventory inventory;
    EXPECT_THROW(inventory.sellProduct("999", 5), std::invalid_argument);
}