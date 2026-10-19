
#include <iostream>
#include <string>
#include <vector>

#include "model/Inventory.hpp"
#include "model/Product.hpp"

void displayMenu() {
    std::cout << "\n===== Inventory Management System =====\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Display All Products\n";
    std::cout << "3. Search Product\n";
    std::cout << "4. Remove Product\n";
    std::cout << "5. Restock Product\n";
    std::cout << "6. Sell Product\n";
    std::cout << "7. Display Low-Stock Products\n";
    std::cout << "8. Search Products by Category\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

void displayProduct(const Product& product) {
    std::cout << "ID: " << product.getId() << '\n';
    std::cout << "Name: " << product.getName() << '\n';
    std::cout << "Stock: " << product.getStockQuantity() << '\n';
    std::cout << "Minimum Stock: "
              << product.getMinimumStockLevel() << '\n';
    std::cout << "Category ID: " << product.getCategoryId() << '\n';
    std::cout << "-------------------------\n";
}

void displayAllProducts(const Inventory& inventory) {
    const auto& products = inventory.getAllProducts();

    if (products.empty()) {
        std::cout << "No products available.\n";
        return;
    }

    std::cout << "\n===== All Products =====\n";

    for (const auto& entry : products) {
        displayProduct(entry.second);
    }
}

void addProduct(Inventory& inventory) {
    std::string id, name, categoryId;
    int stock, minimumStock;

    std::cout << "Enter product ID: ";
    std::cin >> id;

    std::cout << "Enter product name: ";
    std::cin >> name;

    std::cout << "Enter category ID: ";
    std::cin >> categoryId;

    std::cout << "Enter stock quantity: ";
    std::cin >> stock;

    std::cout << "Enter minimum stock level: ";
    std::cin >> minimumStock;

    try {
        Product product(id, name, stock, minimumStock, categoryId);
        inventory.addProduct(product);
        std::cout << "Product added successfully.\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void searchProduct(const Inventory& inventory) {
    std::string id;

    std::cout << "Enter product ID: ";
    std::cin >> id;

    try {
        const Product& product = inventory.getProduct(id);
        displayProduct(product);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void removeProduct(Inventory& inventory) {
    std::string id;

    std::cout << "Enter product ID to remove: ";
    std::cin >> id;

    try {
        inventory.removeProduct(id);
        std::cout << "Product removed successfully.\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void restockProduct(Inventory& inventory) {
    std::string id;
    int quantity;

    std::cout << "Enter product ID: ";
    std::cin >> id;

    std::cout << "Enter quantity to add: ";
    std::cin >> quantity;

    try {
        inventory.restockProduct(id, quantity);
        std::cout << "Product restocked successfully.\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void sellProduct(Inventory& inventory) {
    std::string id;
    int quantity;

    std::cout << "Enter product ID: ";
    std::cin >> id;

    std::cout << "Enter quantity to sell: ";
    std::cin >> quantity;

    try {
        inventory.sellProduct(id, quantity);
        std::cout << "Product sold successfully.\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void displayLowStockProducts(const Inventory& inventory) {
    std::vector<Product> products = inventory.getLowStockProducts();

    if (products.empty()) {
        std::cout << "No low-stock products.\n";
        return;
    }

    std::cout << "\n===== Low-Stock Products =====\n";

    for (const auto& product : products) {
        displayProduct(product);
    }
}

void searchProductsByCategory(const Inventory& inventory) {
    std::string categoryId;

    std::cout << "Enter category ID: ";
    std::cin >> categoryId;

    std::vector<Product> products =
        inventory.getProductsByCategory(categoryId);

    if (products.empty()) {
        std::cout << "No products found in this category.\n";
        return;
    }

    for (const auto& product : products) {
        displayProduct(product);
    }
}

int main() {
    Inventory inventory;

    inventory.addProduct(Product("101", "Laptop", 10, 5, "C001"));
    inventory.addProduct(Product("102", "Mouse", 5, 15, "C002"));

    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addProduct(inventory);
            break;

        case 2:
            displayAllProducts(inventory);
            break;

        case 3:
            searchProduct(inventory);
            break;

        case 4:
            removeProduct(inventory);
            break;

        case 5:
            restockProduct(inventory);
            break;

        case 6:
            sellProduct(inventory);
            break;

        case 7:
            displayLowStockProducts(inventory);
            break;

        case 8:
            searchProductsByCategory(inventory);
            break;

        case 9:
            std::cout << "Exiting Inventory Management System.\n";
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
