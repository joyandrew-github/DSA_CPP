# Adapter Pattern

## Overview

The **Adapter Pattern** is a structural design pattern that allows incompatible interfaces to work together. It acts as a bridge between two incompatible interfaces by wrapping one interface and exposing another that the client expects.

> **Core Idea:** Convert the interface of a class into another interface that clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.

---

## Problem It Solves

| Without Adapter | With Adapter |
|-----------------|--------------|
| Client code tightly coupled to specific interface | Client works with target interface |
| Cannot reuse existing classes with incompatible interfaces | Legacy/third-party code reusable without modification |
| Duplicate code to support multiple interfaces | Single adapter translates between interfaces |
| Violates Open-Closed Principle when adding new integrations | New adapters added without changing client code |

---

## Structure

```
┌──────────────┐
│   Client     │ ──────► Expects Target interface
└──────────────┘
       │
       ▼
┌──────────────┐
│   Target     │ ◄──── Interface client expects
│  (Interface) │
└──────────────┘
       ▲
       │ implements
┌──────────────┐
│   Adapter    │ ◄──── Wraps Adaptee, implements Target
└──────────────┘
       │
       │ wraps/contains
       ▼
┌──────────────┐
│   Adaptee    │ ◄──── Existing incompatible interface
│  (Legacy/    │
│  3rd Party)  │
└──────────────┘
```

---

## Types of Adapters

| Type | Description | Implementation |
|------|-------------|----------------|
| **Object Adapter** | Uses composition to wrap adaptee | Adapter *has-a* Adaptee (preferred) |
| **Class Adapter** | Uses multiple inheritance | Adapter *is-a* Adaptee (C++ only) |

---

## When to Use

- Integrating legacy code with new systems
- Using third-party libraries with incompatible interfaces
- Creating a common interface for multiple similar services
- Refactoring without modifying existing code
- Unit testing with mock adapters

---

## Implementation Example: Payment Gateway Integration

### 1. Target Interface (What Client Expects)
```cpp
// IPaymentProcessor.hpp
#pragma once
#include <string>

class IPaymentProcessor {
public:
    virtual ~IPaymentProcessor() = default;
    virtual bool processPayment(double amount, const std::string& currency) = 0;
    virtual std::string getProcessorName() const = 0;
};
```

### 2. Adaptee (Existing Incompatible Interface)
```cpp
// StripeGateway.hpp (Third-party library - cannot modify)
#pragma once
#include <string>

class StripeGateway {
public:
    // Different method names and parameters!
    bool chargeCustomer(int amountInCents, const std::string& currencyCode) {
        // Stripe-specific implementation
        return true;
    }
    
    std::string getGatewayName() const { return "Stripe"; }
};
```

```cpp
// PayPalGateway.hpp (Another third-party library)
#pragma once
#include <string>

class PayPalGateway {
public:
    // Completely different interface!
    bool makePayment(double amount, const std::string& currency) {
        // PayPal-specific implementation
        return true;
    }
    
    std::string getProviderName() const { return "PayPal"; }
};
```

### 3. Object Adapters (Composition-based)
```cpp
// StripeAdapter.hpp
#pragma once
#include "IPaymentProcessor.hpp"
#include "StripeGateway.hpp"
#include <memory>

class StripeAdapter : public IPaymentProcessor {
    std::unique_ptr<StripeGateway> stripeGateway;
public:
    StripeAdapter() : stripeGateway(std::make_unique<StripeGateway>()) {}
    
    bool processPayment(double amount, const std::string& currency) override {
        // Convert dollars to cents for Stripe
        int amountInCents = static_cast<int>(amount * 100);
        return stripeGateway->chargeCustomer(amountInCents, currency);
    }
    
    std::string getProcessorName() const override {
        return "Stripe Adapter";
    }
};
```

```cpp
// PayPalAdapter.hpp
#pragma once
#include "IPaymentProcessor.hpp"
#include "PayPalGateway.hpp"
#include <memory>

class PayPalAdapter : public IPaymentProcessor {
    std::unique_ptr<PayPalGateway> paypalGateway;
public:
    PayPalAdapter() : paypalGateway(std::make_unique<PayPalGateway>()) {}
    
    bool processPayment(double amount, const std::string& currency) override {
        // PayPal already uses dollars - direct mapping
        return paypalGateway->makePayment(amount, currency);
    }
    
    std::string getProcessorName() const override {
        return "PayPal Adapter";
    }
};
```

### 4. Client Usage
```cpp
// main.cpp
#include <iostream>
#include <memory>
#include "IPaymentProcessor.hpp"
#include "StripeAdapter.hpp"
#include "PayPalAdapter.hpp"

void processOrder(IPaymentProcessor& processor, double amount) {
    std::cout << "Processing $" << amount << " via " 
              << processor.getProcessorName() << std::endl;
    
    if (processor.processPayment(amount, "USD")) {
        std::cout << "Payment successful!" << std::endl;
    } else {
        std::cout << "Payment failed!" << std::endl;
    }
}

int main() {
    // Client works with unified interface
    StripeAdapter stripeAdapter;
    PayPalAdapter paypalAdapter;
    
    processOrder(stripeAdapter, 99.99);
    processOrder(paypalAdapter, 149.50);
    
    // Easy to add new payment providers
    // Just create new Adapter implementing IPaymentProcessor
    
    return 0;
}
```

---

## Class Adapter (C++ Multiple Inheritance)

```cpp
// LegacyPrinter.hpp (Cannot modify)
class LegacyPrinter {
public:
    void printLegacy(const char* text) {
        std::cout << "[Legacy] " << text << std::endl;
    }
};

// ModernPrinter.hpp (Target interface)
class ModernPrinter {
public:
    virtual void print(const std::string& text) = 0;
    virtual ~ModernPrinter() = default;
};

// Class Adapter - inherits from both
class PrinterAdapter : public ModernPrinter, private LegacyPrinter {
public:
    void print(const std::string& text) override {
        printLegacy(text.c_str());  // Access private base
    }
};
```

---

## Real-World Examples

| Domain | Adaptee | Target | Adapter |
|--------|---------|--------|---------|
| **Database** | MySQL, PostgreSQL, MongoDB drivers | Common `IDatabase` interface | Database adapters |
| **Cloud Storage** | AWS S3, Google Cloud, Azure Blob | Unified `IStorage` interface | Storage adapters |
| **Logging** | log4j, spdlog, Boost.Log | Common `ILogger` interface | Logger adapters |
| **Graphics** | OpenGL, DirectX, Vulkan | Abstract `IRenderer` | Renderer adapters |
| **API Clients** | REST, GraphQL, gRPC clients | Unified `IApiClient` | API adapters |

---

## Benefits

| Benefit | Description |
|---------|-------------|
| **Single Responsibility** | Interface conversion separated from business logic |
| **Open-Closed Principle** | Add new adapters without modifying client |
| **Decoupling** | Client depends on abstraction, not concrete implementations |
| **Reusability** | Legacy/third-party code reused without changes |
| **Testability** | Easy to mock adapters for unit testing |

---

## Drawbacks

| Drawback | Mitigation |
|----------|------------|
| **Complexity** | More classes — use only when interfaces truly incompatible |
| **Performance** | Slight overhead from indirection — usually negligible |
| **Maintenance** | Adapters need updates when adaptee changes |

---

## Adapter vs Other Patterns

| Pattern | Purpose | Key Difference |
|---------|---------|----------------|
| **Adapter** | Make incompatible interfaces compatible | Focus: *interface conversion* |
| **Decorator** | Add behavior dynamically | Focus: *enhancement*, same interface |
| **Facade** | Simplify complex subsystem | Focus: *simplification*, new interface |
| **Bridge** | Separate abstraction from implementation | Focus: *structural separation* |
| **Proxy** | Control access to object | Focus: *access control*, same interface |

---

## Key Takeaways

| Principle | Application |
|-----------|-------------|
| **Encapsulate What Varies** | Interface differences isolated in adapters |
| **Program to Interface** | Client uses Target interface, not Adaptee |
| **Composition Over Inheritance** | Object Adapter preferred (has-a relationship) |
| **Adapter as Translator** | Converts requests from Target to Adaptee format |

---

## Summary

> **Adapter Pattern in one sentence:** *Wrap an incompatible interface with a compatible one so clients can use it without knowing the underlying implementation details.*