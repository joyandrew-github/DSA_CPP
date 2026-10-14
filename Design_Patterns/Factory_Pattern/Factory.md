# Factory Design Pattern in C++

## 1. What is the Factory Pattern?

The **Factory Pattern** is a creational design pattern that creates objects without exposing the object-creation logic to the client. Instead of creating objects directly using constructors, we delegate object creation to a separate factory class or method.

> **Interview Definition:** *"The Factory Pattern provides a centralized way to create objects, hiding the instantiation logic from the client and reducing tight coupling."*

---

## 2. Key Benefits

| Benefit | Description |
|---------|-------------|
| **Encapsulation** | Hides complex object creation logic |
| **Loose Coupling** | Client depends on abstraction, not concrete classes |
| **Single Responsibility** | Creation logic separated from business logic |
| **Extensibility** | Easy to add new product types without modifying client code |
| **Testability** | Easy to mock/stub in unit tests |

---

## 3. Implementation Example: Payment Factory

### 3.1 Product Interface

```cpp
// Payment.hpp
#pragma once
#include <string>

class Payment {
public:
    virtual ~Payment() = default;
    virtual void processPayment(double amount) = 0;
    virtual std::string getPaymentType() const = 0;
};
```

### 3.2 Concrete Products

```cpp
// CashPayment.hpp
#pragma once
#include "Payment.hpp"
#include <iostream>

class CashPayment : public Payment {
public:
    void processPayment(double amount) override {
        std::cout << "Processing cash payment of $" << amount << std::endl;
    }
    std::string getPaymentType() const override { return "CASH"; }
};
```

```cpp
// CardPayment.hpp
#pragma once
#include "Payment.hpp"
#include <iostream>

class CardPayment : public Payment {
public:
    void processPayment(double amount) override {
        std::cout << "Processing card payment of $" << amount << std::endl;
    }
    std::string getPaymentType() const override { return "CARD"; }
};
```

```cpp
// UPIPayment.hpp
#pragma once
#include "Payment.hpp"
#include <iostream>

class UPIPayment : public Payment {
public:
    void processPayment(double amount) override {
        std::cout << "Processing UPI payment of $" << amount << std::endl;
    }
    std::string getPaymentType() const override { return "UPI"; }
};
```

### 3.3 Factory Class

```cpp
// PaymentFactory.hpp
#pragma once

#include "Payment.hpp"
#include "CashPayment.hpp"
#include "CardPayment.hpp"
#include "UPIPayment.hpp"
#include <memory>
#include <string>
#include <stdexcept>

class PaymentFactory {
public:
    enum class PaymentType {
        CASH,
        CARD,
        UPI
    };

    // Factory method using enum (type-safe)
    static std::unique_ptr<Payment> createPayment(PaymentType type) {
        switch (type) {
            case PaymentType::CASH:
                return std::make_unique<CashPayment>();
            case PaymentType::CARD:
                return std::make_unique<CardPayment>();
            case PaymentType::UPI:
                return std::make_unique<UPIPayment>();
            default:
                throw std::invalid_argument("Unknown payment type");
        }
    }

    // Factory method using string (flexible for config/JSON)
    static std::unique_ptr<Payment> createPayment(const std::string& type) {
        if (type == "CASH" || type == "cash") {
            return std::make_unique<CashPayment>();
        } else if (type == "CARD" || type == "card") {
            return std::make_unique<CardPayment>();
        } else if (type == "UPI" || type == "upi") {
            return std::make_unique<UPIPayment>();
        }
        throw std::invalid_argument("Unknown payment type: " + type);
    }

    virtual ~PaymentFactory() = default;
};
```

### 3.4 Client Usage

```cpp
// main.cpp
#include "PaymentFactory.hpp"
#include <iostream>
#include <memory>

int main() {
    // Using enum (compile-time safety)
    auto cashPayment = PaymentFactory::createPayment(PaymentFactory::PaymentType::CASH);
    cashPayment->processPayment(100.0);

    // Using string (runtime flexibility)
    auto cardPayment = PaymentFactory::createPayment("CARD");
    cardPayment->processPayment(250.50);

    auto upiPayment = PaymentFactory::createPayment("upi");  // case-insensitive
    upiPayment->processPayment(75.25);

    // Error handling
    try {
        auto invalid = PaymentFactory::createPayment("BITCOIN");
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

---

## 4. When to Use

| Scenario | Use Factory Pattern? |
|----------|---------------------|
| Object creation logic is complex | ✅ Yes |
| Multiple implementations of an interface | ✅ Yes |
| Need to decouple client from concrete classes | ✅ Yes |
| Object type determined at runtime | ✅ Yes |
| Simple, single-class instantiation | ❌ No (overengineering) |

---

## 5. Variants

| Variant | Description |
|---------|-------------|
| **Simple Factory** | Single factory class with static methods (shown above) |
| **Factory Method** | Abstract factory method in base class, overridden by subclasses |
| **Abstract Factory** | Factory of factories - creates families of related objects |

---

## 6. Summary

The Factory Pattern is essential for:
- **Clean architecture** - separates creation from usage
- **Maintainability** - single place to modify creation logic
- **Flexibility** - swap implementations without changing client code
- **Testing** - inject mock implementations easily