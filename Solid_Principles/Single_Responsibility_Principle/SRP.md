# Single Responsibility Principle (SRP) in C++

## Overview

The **Single Responsibility Principle (SRP)** is the first principle of **SOLID** in Object-Oriented Programming (OOP).

> **Definition:** A class should have only **one reason to change**.

In simple terms: **One class should handle one main responsibility.**

---

## Visual: SRP Concept

```
┌─────────────────────────────────────────────────────────────┐
│                    SRP: One Class = One Job                 │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   ❌ BEFORE (Violates SRP)          ✅ AFTER (Follows SRP)  │
│   ┌─────────────────────┐           ┌─────────────────┐    │
│   │    UserManager      │           │  UserRepository │    │
│   ├─────────────────────┤           │  - save()       │    │
│   │ - saveUser()        │           └────────┬────────┘    │
│   │ - sendEmail()       │                    │             │
│   │ - generateReport()  │           ┌────────▼────────┐    │
│   │ - validateUser()    │           │  EmailService   │    │
│   └─────────────────────┘           │  - sendEmail()  │    │
│        │                            └────────┬────────┘    │
│        │ 4 reasons to change                │             │
│        ▼                            ┌────────▼────────┐    │
│   ┌─────────┐                   ┌─────────────────┐    │
│   │ CHANGE  │                   │ ReportGenerator │    │
│   │ SOURCES │                   │ - generate()    │    │
│   └─────────┘                   └────────┬────────┘    │
│                                          │             │
│                                   ┌──────▼──────┐      │
│                                   │UserValidator│      │
│                                   │ - validate()│      │
│                                   └──────┬──────┘      │
│                                          │             │
│                                   ┌──────▼──────┐      │
│                                   │ UserService │      │
│                                   │ (Coordinator)│     │
│                                   └─────────────┘      │
│                                          │             │
│                                   1 reason to change   │
│                                   per class            │
└─────────────────────────────────────────────────────────────┘
```

---

## Why SRP Matters

| Benefit | Description |
|---------|-------------|
| **Maintainability** | Changes to one responsibility don't affect others |
| **Testability** | Easier to unit test focused classes |
| **Reusability** | Classes can be reused in different contexts |
| **Readability** | Clear purpose for each class |
| **Reduced Coupling** | Fewer dependencies between unrelated concerns |

---

## Violation Example (❌ Bad)

```cpp
// BAD: UserManager handles multiple responsibilities
class UserManager {
public:
    void saveUser(User user) { /* DB logic */ }
    void sendEmail(User user) { /* Email logic */ }
    void generateReport(User user) { /* Report logic */ }
    void validateUser(User user) { /* Validation logic */ }
};
// Reasons to change: DB schema, email format, report format, validation rules
```

---

## Correct Implementation (✅ Good)

```cpp
// GOOD: Each class has ONE responsibility
class UserRepository {
public:
    void save(User user) { /* DB logic only */ }
};

class EmailService {
public:
    void sendWelcomeEmail(User user) { /* Email logic only */ }
};

class ReportGenerator {
public:
    void generateUserReport(User user) { /* Report logic only */ }
};

class UserValidator {
public:
    bool validate(User user) { /* Validation logic only */ }
};

// Coordinator (optional) - delegates to specialists
class UserService {
    UserRepository repo;
    EmailService email;
    ReportGenerator report;
    UserValidator validator;
public:
    void registerUser(User user) {
        if (validator.validate(user)) {
            repo.save(user);
            email.sendWelcomeEmail(user);
            report.generateUserReport(user);
        }
    }
};
```

---

## Visual: Class Relationships (Composition)

```
┌─────────────────────────────────────────────────────────────┐
│                    UserService (Coordinator)                │
│  ┌─────────────────────────────────────────────────────┐   │
│  │  registerUser(User user)                            │   │
│  │    1. validator.validate(user)                      │   │
│  │    2. repo.save(user)                               │   │
│  │    3. email.sendWelcomeEmail(user)                  │   │
│  │    4. report.generateUserReport(user)               │   │
│  └─────────────────────────────────────────────────────┘   │
│           │           │           │           │             │
│           ▼           ▼           ▼           ▼             │
│    ┌────────────┐ ┌──────────┐ ┌────────────┐ ┌─────────┐  │
│    │UserReposit-│ │EmailServ-│ │ReportGener-│ │UserVali-│  │
│    │    ory     │ │   ice    │ │   ator     │ │  dator  │  │
│    ├────────────┤ ├──────────┤ ├────────────┤ ├─────────┤  │
│    │ + save()   │ │+sendEmail│ │+ generate()│ │+validate│  │
│    └────────────┘ └──────────┘ └────────────┘ └─────────┘  │
│         │            │            │            │            │
│         ▼            ▼            ▼            ▼            │
│    ┌────────┐  ┌───────────┐ ┌──────────┐ ┌──────────┐    │
│    │Database│  │SMTP Server│ │  PDF/    │ │  Rules   │    │
│    │        │  │           │ │  HTML    │ │  Engine  │    │
│    └────────┘  └───────────┘ └──────────┘ └──────────┘    │
└─────────────────────────────────────────────────────────────┘
```

---

## Key Indicators of SRP Violation

| Sign | Description |
|------|-------------|
| **Large class** | Class has many methods/lines |
| **Multiple "and" in description** | "Class handles X **and** Y **and** Z" |
| **Frequent changes** | Class changes for different reasons |
| **Hard to test** | Requires mocking many dependencies |
| **Unrelated methods** | Methods don't share data/state |

---

## How to Apply SRP

1. **Identify responsibilities** — List what the class does
2. **Separate concerns** — Extract each responsibility into its own class
3. **Use composition** — Combine focused classes via dependency injection
4. **Name clearly** — Class name should reflect its single responsibility

---

## Visual: Refactoring Process

```
┌─────────────────────────────────────────────────────────────┐
│                    REFACTORING TO SRP                       │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   STEP 1: Analyze                                           │
│   ┌─────────────────────────────────────────────────────┐  │
│   │ class UserManager {                                 │  │
│   │   void saveUser()      // DB responsibility         │  │
│   │   void sendEmail()     // Email responsibility      │  │
│   │   void generateReport()// Report responsibility     │  │
│   │   void validateUser()  // Validation responsibility │  │
│   │ }                                                   │  │
│   └─────────────────────────────────────────────────────┘  │
│                          │                                  │
│                          ▼                                  │
│   STEP 2: Extract                                           │
│   ┌─────────────┐ ┌──────────┐ ┌────────────┐ ┌─────────┐  │
│   │UserReposit- │ │EmailServ-│ │ReportGener-│ │UserVali-│  │
│   │    ory     │ │   ice    │ │   ator     │ │  dator  │  │
│   └─────────────┘ └──────────┘ └────────────┘ └─────────┘  │
│                          │                                  │
│                          ▼                                  │
│   STEP 3: Compose                                           │
│   ┌─────────────────────────────────────────────────────┐  │
│   │ class UserService {                                 │  │
│   │   UserRepository repo;                              │  │
│   │   EmailService email;                               │  │
│   │   ReportGenerator report;                           │  │
│   │   UserValidator validator;                          │  │
│   │                                                     │  │
│   │   void registerUser(User user) { ... }              │  │
│   │ }                                                   │  │
│   └─────────────────────────────────────────────────────┘  │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## Summary

| ❌ Violates SRP | ✅ Follows SRP |
|-----------------|----------------|
| One class does everything | Each class does one thing well |
| Hard to maintain | Easy to maintain and extend |
| Tight coupling | Loose coupling |
| Difficult testing | Easy unit testing |

> **Remember:** SRP is about **cohesion** — a class should have high cohesion (related functionality) and low coupling (minimal dependencies).