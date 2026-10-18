# QuickCart

QuickCart is a C++17 e-commerce shopping cart application demonstrating SOLID principles, clean architecture, and modern C++ practices. It includes a command-line application and a comprehensive GoogleTest suite.

## Project Structure

```
QuickCart/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── models/
│   │   ├── CartItem.hpp
│   │   ├── Customer.hpp
│   │   ├── Delivery.hpp
│   │   ├── DeliveryPartner.hpp
│   │   ├── Order.hpp
│   │   ├── Product.hpp
│   │   └── ShoppingCart.hpp
│   ├── repositories/
│   │   └── ProductRepository.hpp
│   ├── services/
│   │   ├── DeliveryService.hpp
│   │   ├── LoyaltyService.hpp
│   │   ├── OrderService.hpp
│   │   └── PricingService.hpp
│   └── strategies/
│       ├── DiscountStrategy.hpp
│       ├── NoDiscountStrategy.hpp
│       └── PercentageDiscountStrategy.hpp
├── repositories/
│   └── ProductRepository.cpp
├── src/
│   ├── CartItem.cpp
│   ├── Customer.cpp
│   ├── Delivery.cpp
│   ├── DeliveryPartner.cpp
│   ├── DeliveryService.cpp
│   ├── LoyaltyService.cpp
│   ├── Order.cpp
│   ├── OrderService.cpp
│   ├── PricingService.cpp
│   ├── Product.cpp
│   ├── ProductRepository.cpp
│   ├── ShoppingCart.cpp
│   └── main.cpp
└── tests/
    ├── CartItemTest.cpp
    ├── DeliveryServiceTest.cpp
    ├── OrderServiceTest.cpp
    ├── PricingServiceTest.cpp
    ├── ProductTest.cpp
    └── ShoppingCartTest.cpp
```

## Features

- **Product Catalog**: Manage products with ID, name, and price
- **Shopping Cart**: Add products, view cart contents, calculate subtotal
- **Pricing Service**: Calculate discounts and final amounts using strategy pattern
- **Discount Strategies**: Percentage-based discounts and no-discount strategy
- **Customer Management**: Customer accounts with loyalty points
- **Order Service**: Checkout process with order creation
- **Loyalty Service**: Award loyalty points based on purchases
- **Delivery Service**: Assign deliveries to partners and track status
- **Product Repository**: Data access layer for products
- **Unit Tests**: GoogleTest-based test suite covering all major components

## Design Patterns

- **Strategy Pattern**: Discount strategies (`PercentageDiscountStrategy`, `NoDiscountStrategy`) implement the `DiscountStrategy` interface
- **Repository Pattern**: `ProductRepository` abstracts product data access
- **Service Layer**: Business logic organized into services (`PricingService`, `OrderService`, `DeliveryService`, `LoyaltyService`)

## Requirements

- CMake 3.23 or higher
- C++17 compatible compiler
- Internet connection (for fetching GoogleTest dependency)

## Build Instructions

### Using CMake

```bash
# Create build directory
mkdir build && cd build

# Configure and build the application
cmake ..
cmake --build .

# Run the application
./QuickCart

# Build and run tests
cmake --build . --target QuickCartTests
ctest
```

### Build Targets

| Target | Description |
|--------|-------------|
| `QuickCart` | Main application executable |
| `QuickCartTests` | Unit test executable |

## Usage

Run the application:

```bash
./QuickCart
```

The application demonstrates:
1. Creating products and adding them to a shopping cart
2. Calculating discounts based on subtotal thresholds
3. Processing checkout with customer and loyalty services
4. Managing deliveries and delivery partners

## Testing

The project uses GoogleTest for unit testing. Tests cover:

- `ProductTest` - Product model behavior
- `ShoppingCartTest` - Cart operations and subtotal calculation
- `PricingServiceTest` - Discount and final amount calculation
- `OrderServiceTest` - Order checkout process
- `DeliveryServiceTest` - Delivery assignment and status updates
- `CartItemTest` - Cart item management

Run tests with:

```bash
cd build
ctest --output-on-failure
```

## C++ Standard

The project targets **C++17** and requires a compliant compiler.

## License

This project is part of the DSA_CPP repository.