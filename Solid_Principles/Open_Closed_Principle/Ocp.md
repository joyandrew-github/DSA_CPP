# Open-Closed Principle (OCP)

## Overview

The **Open-Closed Principle (OCP)** is the second principle in the SOLID design principles. It states:

> **Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.**

---

## What Does This Mean?

| Aspect | Description |
|--------|-------------|
| **Open for Extension** | You can add new functionality without changing existing code |
| **Closed for Modification** | Existing, tested code should not be modified when adding new features |

---

## Why Is OCP Important?

- **Reduces Risk**: Modifying existing code can introduce bugs in working functionality
- **Improves Maintainability**: New features are added via extension, not modification
- **Enables Reusability**: Base classes/modules remain stable and reusable
- **Supports Testing**: Existing tests continue to pass; new tests cover new extensions

---

## How to Apply OCP

### 1. **Abstraction & Polymorphism**
Use abstract base classes or interfaces to define contracts.

```cpp
// Abstract base class - closed for modification
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// Extensions - open for extension
class Circle : public Shape { /* ... */ };
class Rectangle : public Shape { /* ... */ };
class Triangle : public Shape { /* ... */ };
```

### 2. **Strategy Pattern**
Encapsulate varying behavior in separate classes.

```cpp
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};

class CreditCardPayment : public PaymentStrategy { /* ... */ };
class PayPalPayment : public PaymentStrategy { /* ... */ };
class CryptoPayment : public PaymentStrategy { /* ... */ };
```

### 3. **Plugin/Module Architecture**
Design systems where new modules register themselves without modifying core code.

---

## Violation Example (❌ Bad)

```cpp
class AreaCalculator {
public:
    double calculateArea(ShapeType type, double dim1, double dim2 = 0) {
        switch (type) {
            case CIRCLE:    return 3.14 * dim1 * dim1;
            case RECTANGLE: return dim1 * dim2;
            case TRIANGLE:  return 0.5 * dim1 * dim2;
            // Adding new shape = MODIFYING this class
        }
    }
};
```

---

## Correct Implementation (✅ Good)

```cpp
// Closed for modification
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// Open for extension - add new shapes without touching existing code
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

// Client code works with ANY shape - no modification needed
double totalArea(const std::vector<Shape*>& shapes) {
    double sum = 0;
    for (auto* s : shapes) sum += s->area();
    return sum;
}
```

---

## Key Takeaways

| Principle | Application |
|-----------|-------------|
| **Abstraction** | Depend on abstractions, not concretions |
| **Inheritance** | Extend behavior via derived classes |
| **Composition** | Prefer composition over inheritance when possible |
| **Interfaces** | Define clear contracts for extensions |

---

## Related Principles

- **Single Responsibility Principle (SRP)** - Classes should have one reason to change
- **Liskov Substitution Principle (LSP)** - Derived classes must be substitutable for base classes
- **Dependency Inversion Principle (DIP)** - Depend on abstractions, not concretions

---

## Summary

> **OCP in one sentence:** *Design your code so that new functionality is added by writing new code, not by changing old code.*