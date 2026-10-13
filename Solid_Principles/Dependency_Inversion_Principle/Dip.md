# Dependency Inversion Principle (DIP)

## Overview

The **Dependency Inversion Principle (DIP)** is the fifth principle in the SOLID design principles. It states:

> **High-level modules should not depend on low-level modules. Both should depend on abstractions.**
>
> **Abstractions should not depend on details. Details should depend on abstractions.**

---

## Key Concepts

| Term | Description |
|------|-------------|
| **High-Level Module** | Contains core business logic, rules, and orchestration (e.g., `OrderService`, `PaymentProcessor`) |
| **Low-Level Module** | Handles implementation details — databases, APIs, file I/O, hardware (e.g., `MySQLRepository`, `StripeGateway`) |
| **Abstraction** | Interface or abstract class defining *what* without *how* (e.g., `IRepository`, `IPaymentGateway`) |
| **Dependency** | A relationship where one class requires another to function |

---

## Why Is DIP Important?

- **Decouples Architecture**: Business logic doesn't know about databases, frameworks, or external services
- **Enables Testing**: Swap real implementations with mocks/stubs for unit tests
- **Supports Flexibility**: Change storage, payment providers, or notification channels without touching business logic
- **Enables Parallel Development**: Teams can work on high-level and low-level modules independently

---

## Violation Example (❌ Bad)

```cpp
// Low-level module
class MySQLDatabase {
public:
    void save(const string& data) { /* SQL INSERT */ }
    string load(int id) { /* SQL SELECT */ }
};

// High-level module DIRECTLY depends on low-level module
class UserService {
    MySQLDatabase db;  // ❌ Concrete dependency
public:
    void createUser(const string& name) {
        db.save(name);
    }
    string getUser(int id) {
        return db.load(id);
    }
};
```

**Problems:**
- Cannot test `UserService` without a real MySQL database
- Cannot switch to PostgreSQL, MongoDB, or in-memory storage
- `UserService` recompiles when `MySQLDatabase` changes

---

## Correct Implementation (✅ Good)

### Step 1: Define Abstraction
```cpp
// Abstraction - owned by high-level module
class IUserRepository {
public:
    virtual void save(const string& data) = 0;
    virtual string load(int id) = 0;
    virtual ~IUserRepository() = default;
};
```

### Step 2: Implement Low-Level Module Against Abstraction
```cpp
// Low-level module DEPENDS on abstraction
class MySQLUserRepository : public IUserRepository {
public:
    void save(const string& data) override { /* SQL INSERT */ }
    string load(int id) override { /* SQL SELECT */ return ""; }
};

class PostgreSQLUserRepository : public IUserRepository {
public:
    void save(const string& data) override { /* PG INSERT */ }
    string load(int id) override { /* PG SELECT */ return ""; }
};

class InMemoryUserRepository : public IUserRepository {  // For testing
    unordered_map<int, string> store;
public:
    void save(const string& data) override { /* ... */ }
    string load(int id) override { /* ... */ return ""; }
};
```

### Step 3: High-Level Module Depends on Abstraction
```cpp
// High-level module depends on ABSTRACTION, not concrete class
class UserService {
    unique_ptr<IUserRepository> repo;  // Dependency injected
public:
    explicit UserService(unique_ptr<IUserRepository> r) : repo(std::move(r)) {}
    
    void createUser(const string& name) { repo->save(name); }
    string getUser(int id) { return repo->load(id); }
};
```

### Step 4: Composition Root (Wiring)
```cpp
int main() {
    // Production: use real database
    auto repo = make_unique<MySQLUserRepository>();
    UserService service(std::move(repo));
    
    // Testing: swap with in-memory
    // auto repo = make_unique<InMemoryUserRepository>();
    // UserService testService(std::move(repo));
}
```

---

## Dependency Flow Comparison

```
❌ VIOLATION (Traditional Layered):
High-Level ──────► Low-Level
(UserService)     (MySQLDatabase)

✅ DIP COMPLIANT (Inverted):
High-Level ◄────── Low-Level
(UserService)     (MySQLRepo)
       ▲
       │
       └── Abstraction (IUserRepository)
```

---

## Practical Example: Payment Processing

```cpp
// Abstraction (owned by high-level)
class IPaymentGateway {
public:
    virtual bool charge(double amount, const string& token) = 0;
    virtual ~IPaymentGateway() = default;
};

// Low-level implementations
class StripeGateway : public IPaymentGateway { /* ... */ };
class PayPalGateway : public IPaymentGateway { /* ... */ };
class MockGateway : public IPaymentGateway { /* ... */ };  // Testing

// High-level business logic
class PaymentService {
    unique_ptr<IPaymentGateway> gateway;
public:
    explicit PaymentService(unique_ptr<IPaymentGateway> g) : gateway(std::move(g)) {}
    
    bool processPayment(double amount, const string& token) {
        // Business rules: validation, logging, retries...
        return gateway->charge(amount, token);
    }
};
```

---

## Key Takeaways

| Principle | Application |
|-----------|-------------|
| **Own the Abstraction** | High-level modules define interfaces they need |
| **Invert Dependencies** | Low-level modules implement high-level interfaces |
| **Inject Dependencies** | Pass abstractions via constructor (DI) |
| **Composition Root** | Wire concrete implementations at app entry point |

---

## Related Principles

- **Open-Closed Principle (OCP)** - DIP enables OCP by allowing new implementations without modifying high-level code
- **Liskov Substitution Principle (LSP)** - Implementations must be substitutable for the abstraction
- **Interface Segregation Principle (ISP)** - Small, focused interfaces reduce coupling further

---

## Summary

> **DIP in one sentence:** *Depend on contracts (interfaces), not concrete tools — so your business logic stays pure while infrastructure changes freely.*