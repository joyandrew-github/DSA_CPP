# Liskov Substitution Principle (LSP)

## Overview

The **Liskov Substitution Principle (LSP)** is the third principle in the SOLID design principles. It states:

> **Objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program.**

---

## What Does This Mean?

| Aspect | Description |
|--------|-------------|
| **Substitutability** | A derived class must be usable wherever its base class is expected |
| **Behavioral Compatibility** | Subclasses must honor the contract (preconditions, postconditions, invariants) of the base class |
| **No Surprises** | Client code using base class references should work correctly with any derived class |

---

## Why Is LSP Important?

- **Enables Polymorphism**: Safe runtime substitution of implementations
- **Prevents Fragile Hierarchies**: Catches design flaws where inheritance breaks base class contracts
- **Improves Maintainability**: Changes to subclasses don't break existing client code
- **Supports Open-Closed Principle**: New subclasses extend behavior without modifying clients

---

## LSP Rules (Design by Contract)

| Rule | Description |
|------|-------------|
| **Preconditions** | Cannot be strengthened in subclass (must accept *at least* what base accepts) |
| **Postconditions** | Cannot be weakened in subclass (must guarantee *at least* what base guarantees) |
| **Invariants** | Must be preserved in subclass (base class invariants still hold) |
| **History Constraint** | Subclass cannot mutate state in ways base class wouldn't allow |

---

## Violation Example (❌ Bad)

```cpp
class Bird {
public:
    virtual void fly() { cout << "Flying..." << endl; }
    virtual ~Bird() = default;
};

class Penguin : public Bird {
public:
    void fly() override { throw runtime_error("Penguins can't fly!"); }  // ❌ Breaks LSP
};

void makeBirdFly(Bird& bird) {
    bird.fly();  // Crashes when passed a Penguin
}
```

**Problem:** `Penguin` *is-a* `Bird` structurally but not behaviorally. The `fly()` contract is violated.

---

## Correct Implementation (✅ Good)

### Option 1: Restructure Hierarchy
```cpp
class Bird {
public:
    virtual void move() = 0;
    virtual ~Bird() = default;
};

class FlyingBird : public Bird {
public:
    void fly() { cout << "Flying..." << endl; }
    void move() override { fly(); }
};

class Penguin : public Bird {
public:
    void move() override { cout << "Swimming..." << endl; }
};
```

### Option 2: Use Composition / Interfaces
```cpp
class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

class Bird {
public:
    virtual void move() = 0;
    virtual ~Bird() = default;
};

class Sparrow : public Bird, public Flyable { /* ... */ };
class Penguin : public Bird { /* no Flyable */ };
```

---

## Practical Example: Notification Channels (LSP Compliant)

```cpp
class NotificationChannel {
public:
    virtual void send(const string& message, Priority priority) const = 0;
    virtual ~NotificationChannel() = default;
};

// All implementations honor the same contract:
// - Accept any message string
// - Accept any Priority value
// - Never throw for valid inputs
// - Guarantee delivery attempt

class EmailNotification : public NotificationChannel { /* ... */ };
class SMSNotification : public NotificationChannel { /* ... */ };
class WhatsAppNotification : public NotificationChannel { /* ... */ };
class PushNotification : public NotificationChannel { /* ... */ };

// Client code works with ANY channel - LSP satisfied
class NotificationService {
public:
    void send(const NotificationChannel& channel, const string& msg, Priority p) const {
        channel.send(msg, p);  // Safe substitution
    }
};
```

---

## Key Takeaways

| Principle | Application |
|-----------|-------------|
| **IS-A vs HAS-A** | Inheritance = behavioral substitution, not just code reuse |
| **Contract First** | Define base class contracts clearly (pre/post/invariants) |
| **Test Substitutability** | Write tests that accept base class and pass all derived types |
| **Prefer Composition** | When substitution fails, use interfaces or composition |

---

## Related Principles

- **Open-Closed Principle (OCP)** - LSP enables safe extension via polymorphism
- **Interface Segregation Principle (ISP)** - Small interfaces reduce LSP violation risk
- **Dependency Inversion Principle (DIP)** - Depend on abstractions that honor LSP

---

## Summary

> **LSP in one sentence:** *If it looks like a duck and quacks like a duck but crashes when you call `fly()`, it's not a duck — fix your hierarchy.*