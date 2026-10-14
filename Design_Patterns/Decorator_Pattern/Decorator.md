# Decorator Pattern

## Overview

The **Decorator Pattern** is a structural design pattern that allows behavior to be added to individual objects dynamically, without affecting the behavior of other objects from the same class. It provides a flexible alternative to subclassing for extending functionality.

> **Core Idea:** Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

---

## Problem It Solves

| Without Decorator | With Decorator |
|-------------------|----------------|
| Explosion of subclasses for each feature combination | Compose features at runtime |
| Static inheritance hierarchy | Dynamic behavior composition |
| Violates Open-Closed Principle | Follows OCP — open for extension |
| Rigid compile-time decisions | Flexible runtime decisions |
| Code duplication across subclasses | Shared base, reusable decorators |

---

## Structure

```
┌─────────────────┐
│    Client       │
└─────────────────┘
        │
        ▼
┌─────────────────┐
│   Component     │ ◄──── Common interface
│  (Interface)    │
└─────────────────┘
        ▲           ▲
        │           │
    ┌───┴───┐   ┌───┴────────────┐
    ▼       ▼   ▼                ▼
┌────────┐ ┌─────────┐    ┌──────────────┐
│Concrete│ │Decorator│    │Concrete      │
│Component│ │(Base)   │    │Decorator A   │
└────────┘ └─────────┘    └──────────────┘
                    ▲                ▲
                    │                │
              ┌─────┴─────┐    ┌─────┴─────┐
              ▼           ▼    ▼           ▼
        ┌──────────┐ ┌──────────┐ ┌──────────┐
        │Concrete  │ │Concrete  │ │Concrete  │
        │Decorator B│ │Decorator C│ │Decorator D│
        └──────────┘ └──────────┘ └──────────┘
```

---

## Key Components

| Component | Role |
|-----------|------|
| **Component** | Abstract interface defining operations |
| **ConcreteComponent** | Base object to be decorated |
| **Decorator** | Abstract class implementing Component, holds reference to Component |
| **ConcreteDecorator** | Adds specific behavior before/after delegating to wrapped component |

---

## When to Use

- Add responsibilities to objects dynamically and transparently
- Extend functionality when subclassing is impractical (too many combinations)
- Responsibilities that can be withdrawn
- When you need to add behavior to individual objects, not entire classes

---

## Implementation Example: Coffee Shop

### 1. Component Interface
```cpp
// Beverage.hpp
#pragma once
#include <string>

class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};
```

### 2. Concrete Component
```cpp
// Espresso.hpp
#pragma once
#include "Beverage.hpp"

class Espresso : public Beverage {
public:
    std::string getDescription() const override {
        return "Espresso";
    }
    
    double cost() const override {
        return 2.00;
    }
};
```

```cpp
// DarkRoast.hpp
#pragma once
#include "Beverage.hpp"

class DarkRoast : public Beverage {
public:
    std::string getDescription() const override {
        return "Dark Roast Coffee";
    }
    
    double cost() const override {
        return 1.50;
    }
};
```

### 3. Base Decorator
```cpp
// CondimentDecorator.hpp
#pragma once
#include "Beverage.hpp"
#include <memory>

class CondimentDecorator : public Beverage {
protected:
    std::unique_ptr<Beverage> beverage;
public:
    explicit CondimentDecorator(std::unique_ptr<Beverage> b) 
        : beverage(std::move(b)) {}
    
    // Must be implemented by concrete decorators
    std::string getDescription() const override = 0;
    double cost() const override = 0;
};
```

### 4. Concrete Decorators
```cpp
// Milk.hpp
#pragma once
#include "CondimentDecorator.hpp"

class Milk : public CondimentDecorator {
public:
    explicit Milk(std::unique_ptr<Beverage> b) 
        : CondimentDecorator(std::move(b)) {}
    
    std::string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }
    
    double cost() const override {
        return beverage->cost() + 0.50;
    }
};
```

```cpp
// Mocha.hpp
#pragma once
#include "CondimentDecorator.hpp"

class Mocha : public CondimentDecorator {
public:
    explicit Mocha(std::unique_ptr<Beverage> b) 
        : CondimentDecorator(std::move(b)) {}
    
    std::string getDescription() const override {
        return beverage->getDescription() + ", Mocha";
    }
    
    double cost() const override {
        return beverage->cost() + 0.75;
    }
};
```

```cpp
// Whip.hpp
#pragma once
#include "CondimentDecorator.hpp"

class Whip : public CondimentDecorator {
public:
    explicit Whip(std::unique_ptr<Beverage> b) 
        : CondimentDecorator(std::move(b)) {}
    
    std::string getDescription() const override {
        return beverage->getDescription() + ", Whip";
    }
    
    double cost() const override {
        return beverage->cost() + 0.30;
    }
};
```

```cpp
// Soy.hpp
#pragma once
#include "CondimentDecorator.hpp"

class Soy : public CondimentDecorator {
public:
    explicit Soy(std::unique_ptr<Beverage> b) 
        : CondimentDecorator(std::move(b)) {}
    
    std::string getDescription() const override {
        return beverage->getDescription() + ", Soy";
    }
    
    double cost() const override {
        return beverage->cost() + 0.40;
    }
};
```

### 5. Client Usage
```cpp
// main.cpp
#include <iostream>
#include <memory>
#include "Espresso.hpp"
#include "DarkRoast.hpp"
#include "Milk.hpp"
#include "Mocha.hpp"
#include "Whip.hpp"
#include "Soy.hpp"

int main() {
    // Order 1: Espresso with double mocha and whip
    std::unique_ptr<Beverage> beverage1 = std::make_unique<Espresso>();
    beverage1 = std::make_unique<Mocha>(std::move(beverage1));
    beverage1 = std::make_unique<Mocha>(std::move(beverage1));
    beverage1 = std::make_unique<Whip>(std::move(beverage1));
    
    std::cout << beverage1->getDescription() 
              << " $" << beverage1->cost() << std::endl;
    // Output: Espresso, Mocha, Mocha, Whip $3.80
    
    // Order 2: Dark Roast with soy, milk, and mocha
    std::unique_ptr<Beverage> beverage2 = std::make_unique<DarkRoast>();
    beverage2 = std::make_unique<Soy>(std::move(beverage2));
    beverage2 = std::make_unique<Milk>(std::move(beverage2));
    beverage2 = std::make_unique<Mocha>(std::move(beverage2));
    
    std::cout << beverage2->getDescription() 
              << " $" << beverage2->cost() << std::endl;
    // Output: Dark Roast Coffee, Soy, Milk, Mocha $3.15
    
    // Order 3: Simple Espresso (no decorators)
    std::unique_ptr<Beverage> beverage3 = std::make_unique<Espresso>();
    std::cout << beverage3->getDescription() 
              << " $" << beverage3->cost() << std::endl;
    // Output: Espresso $2.00
    
    return 0;
}
```

---

## Alternative: Functional Decorator (C++17+)

```cpp
// Using std::function for lighter-weight decorators
#include <functional>
#include <string>

class SimpleBeverage {
    std::string description;
    double baseCost;
    std::function<double(double)> costModifier;
    std::function<std::string(std::string)> descModifier;
    
public:
    SimpleBeverage(std::string desc, double cost)
        : description(std::move(desc)), baseCost(cost),
          costModifier([](double c) { return c; }),
          descModifier([](std::string d) { return d; }) {}
    
    void addDecorator(
        std::function<double(double)> costMod,
        std::function<std::string(std::string)> descMod
    ) {
        auto prevCost = costModifier;
        auto prevDesc = descModifier;
        costModifier = [prevCost, costMod](double c) { return costMod(prevCost(c)); };
        descModifier = [prevDesc, descMod](std::string d) { return descMod(prevDesc(d)); };
    }
    
    double cost() const { return costModifier(baseCost); }
    std::string getDescription() const { return descModifier(description); }
};

// Usage
SimpleBeverage coffee("Coffee", 1.50);
coffee.addDecorator(
    [](double c) { return c + 0.50; },  // Milk
    [](std::string d) { return d + ", Milk"; }
);
coffee.addDecorator(
    [](double c) { return c + 0.75; },  // Mocha
    [](std::string d) { return d + ", Mocha"; }
);
```

---

## Real-World Examples

| Domain | Component | Decorators |
|--------|-----------|------------|
| **I/O Streams** | `std::streambuf` | `std::buffered`, `std::compressed`, `std::encrypted` |
| **GUI** | `Widget` | `BorderDecorator`, `ScrollDecorator`, `ShadowDecorator` |
| **Logging** | `Logger` | `TimestampDecorator`, `LevelDecorator`, `FormatDecorator` |
| **HTTP** | `Request` | `AuthDecorator`, `RetryDecorator`, `CacheDecorator` |
| **Text Processing** | `Text` | `BoldDecorator`, `ItalicDecorator`, `ColorDecorator` |
| **Caching** | `Cache` | `LRUDecorator`, `TTLDecorator`, `MetricsDecorator` |

---

## Benefits

| Benefit | Description |
|---------|-------------|
| **Open-Closed Principle** | Add new decorators without modifying existing code |
| **Single Responsibility** | Each decorator has one reason to change |
| **Flexible Composition** | Mix and match decorators at runtime |
| **Avoids Subclass Explosion** | No need for `EspressoWithMilkAndMochaAndWhip` classes |
| **Transparent to Client** | Client works with Component interface |

---

## Drawbacks

| Drawback | Mitigation |
|----------|------------|
| **Many Small Classes** | Can increase class count — group related decorators |
| **Identity Issues** | Decorated object != original — use `dynamic_cast` if needed |
| **Order Dependency** | Decorator order matters — document expected sequences |
| **Complexity** | Overuse leads to hard-to-debug chains |

---

## Decorator vs Other Patterns

| Pattern | Purpose | Key Difference |
|---------|---------|----------------|
| **Decorator** | Add behavior dynamically | Focus: *enhancement*, same interface |
| **Adapter** | Convert interface | Focus: *interface conversion* |
| **Composite** | Tree structures | Focus: *part-whole hierarchy* |
| **Strategy** | Swap algorithms | Focus: *algorithm variation* |
| **Proxy** | Control access | Focus: *access control*, same interface |

---

## Key Takeaways

| Principle | Application |
|-----------|-------------|
| **Encapsulate What Varies** | Optional behaviors in separate decorators |
| **Program to Interface** | Client uses Component, not ConcreteComponent |
| **Composition Over Inheritance** | Decorator *has-a* Component, not *is-a* |
| **Dynamic Binding** | Behavior composed at runtime |

---

## Summary

> **Decorator Pattern in one sentence:** *Wrap objects with decorators to add behavior dynamically — like adding toppings to a coffee — without changing the original object or using inheritance.*