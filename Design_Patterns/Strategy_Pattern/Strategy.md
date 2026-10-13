# Strategy Pattern

## Overview

The **Strategy Pattern** is a behavioral design pattern that defines a family of algorithms, encapsulates each one, and makes them interchangeable at runtime.

> **Core Idea:** Instead of writing multiple algorithms inside a single class using `if-else` or `switch`, create separate classes for each algorithm and choose which one to use at runtime.

---

## Problem It Solves

| Without Strategy | With Strategy |
|------------------|---------------|
| Large `if-else` / `switch` blocks | Clean delegation to strategy objects |
| Hard to add new algorithms | Add new strategies without modifying existing code |
| Violates Open-Closed Principle | Follows OCP — open for extension, closed for modification |
| Difficult to test individual algorithms | Each strategy testable in isolation |
| Runtime algorithm switching impossible | Switch strategies dynamically at runtime |

---

## Structure

```
┌─────────────────┐
│   Context       │ ──────► Uses strategy interface
└─────────────────┘
        │
        ▼
┌─────────────────┐
│  Strategy       │ ◄──── Abstract interface (defines algorithm contract)
│  (Interface)    │
└─────────────────┘
        ▲
        │
    ┌───┴───┬─────────┬─────────┐
    ▼       ▼         ▼         ▼
┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐
│Concrete│ │Concrete│ │Concrete│ │Concrete│
│Strategy│ │Strategy│ │Strategy│ │Strategy│
│   A    │ │   B    │ │   C    │ │   D    │
└──────┘ └──────┘ └──────┘ └──────┘
```

---

## When to Use

- Multiple algorithms for the same task (sorting, compression, payment, routing)
- Algorithm selection at runtime based on conditions
- Need to avoid conditional logic for algorithm selection
- Want to isolate algorithm implementations for testing
- Following Open-Closed Principle for algorithm variations

---

## Implementation Example: Payment Processing

### 1. Strategy Interface
```cpp
class PaymentStrategy {
public:
    virtual bool pay(double amount) = 0;
    virtual string getName() const = 0;
    virtual ~PaymentStrategy() = default;
};
```

### 2. Concrete Strategies
```cpp
class UPIPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Paid " << amount << " via UPI" << endl;
        return true;
    }
    string getName() const override { return "UPI"; }
};

class CardPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Paid " << amount << " via Credit Card" << endl;
        return true;
    }
    string getName() const override { return "Credit Card"; }
};

class CryptoPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Paid " << amount << " via Cryptocurrency" << endl;
        return true;
    }
    string getName() const override { return "Crypto"; }
};
```

### 3. Context
```cpp
class PaymentContext {
    unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(unique_ptr<PaymentStrategy> s) {
        strategy = std::move(s);
    }
    
    bool executePayment(double amount) {
        if (!strategy) {
            cout << "No payment strategy selected!" << endl;
            return false;
        }
        cout << "Processing payment via " << strategy->getName() << "..." << endl;
        return strategy->pay(amount);
    }
};
```

### 4. Usage
```cpp
int main() {
    PaymentContext context;
    
    // Switch strategies at runtime
    context.setStrategy(make_unique<UPIPayment>());
    context.executePayment(1000);
    
    context.setStrategy(make_unique<CardPayment>());
    context.executePayment(2500);
    
    context.setStrategy(make_unique<CryptoPayment>());
    context.executePayment(5000);
}
```

---

## Real-World Examples

| Domain | Strategies |
|--------|------------|
| **Sorting** | QuickSort, MergeSort, BubbleSort, HeapSort |
| **Compression** | ZIP, GZIP, LZ4, ZSTD |
| **Routing** | ShortestPath, FastestRoute, AvoidTolls, ScenicRoute |
| **Authentication** | OAuth, JWT, API Key, Session |
| **Export** | PDF, CSV, JSON, XML |
| **Caching** | LRU, LFU, FIFO, Random |

---

## Benefits

| Benefit | Description |
|---------|-------------|
| **Open-Closed Principle** | Add new strategies without modifying context |
| **Single Responsibility** | Each strategy has one reason to change |
| **Testability** | Test each algorithm independently |
| **Runtime Flexibility** | Switch behavior without restart |
| **Eliminates Conditionals** | Replaces `if-else` chains with polymorphism |
| **Reusability** | Strategies reusable across contexts |

---

## Drawbacks

| Drawback | Mitigation |
|----------|------------|
| **More Classes** | Increases class count — use when variation is genuine |
| **Client Awareness** | Client must know available strategies — consider Factory |
| **Overhead** | Slight indirection cost — negligible in most cases |

---

## Strategy vs Other Patterns

| Pattern | Purpose | Key Difference |
|---------|---------|----------------|
| **Strategy** | Encapsulate interchangeable algorithms | Focus: *behavior* variation |
| **State** | Change behavior based on internal state | Focus: *state-dependent* behavior |
| **Template Method** | Define algorithm skeleton, defer steps | Focus: *algorithm structure* fixed |
| **Command** | Encapsulate request as object | Focus: *action* encapsulation |

---

## Key Takeaways

| Principle | Application |
|-----------|-------------|
| **Encapsulate What Varies** | Algorithms that change independently |
| **Program to Interface** | Context depends on abstraction, not concretions |
| **Composition Over Inheritance** | Context *has-a* strategy, not *is-a* |
| **Runtime Binding** | Strategy chosen at runtime, not compile-time |

---

## Summary

> **Strategy Pattern in one sentence:** *Define a family of algorithms, put each in a separate class, and make them interchangeable — so the context can switch behaviors dynamically without knowing the details.*