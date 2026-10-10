# Object-Oriented Programming System (OOPS)

## What is OOPS?

**OOPS** stands for **Object-Oriented Programming System**. It is a programming paradigm where we design programs using **objects** instead of only functions and logic.

### Object

An **object** is a real-world entity that has:

| Property | Description |
|----------|-------------|
| **Data (Attributes)** | State/characteristics of the object |
| **Behavior (Methods/Functions)** | Actions the object can perform |

**Example: Student Object**

| Data | Behavior |
|------|----------|
| `name` | `study()` |
| `rollNo` | `writeExam()` |
| `marks` | |

> **In short:** OOPS = organizing code around real-world objects.

---

## Why do we need OOPS?

As programs grow bigger:
- Code becomes hard to manage
- Changes in one place break code in many places
- Reusing code becomes difficult

**OOPS solves these problems.**

### Benefits of OOPS

| # | Benefit | Description |
|---|---------|-------------|
| 1 | **Better Code Organization** | Code is divided into classes & objects; easy to understand and maintain |
| 2 | **Reusability** | Write once, use many times (e.g., `Vehicle` class for `Car`, `Bike`, `Bus`) |
| 3 | **Security** | Data can be hidden using access specifiers; prevents accidental misuse |
| 4 | **Easy Maintenance** | Changes in one class don't affect the whole program |
| 5 | **Real-world Modeling** | Maps real-life problems directly into code |

---

## Core Concepts of OOPS

| Concept | Meaning |
|---------|---------|
| **Class** | Blueprint/template of an object |
| **Object** | Instance of a class |
| **Encapsulation** | Wrapping data + methods together; hiding internal details |
| **Abstraction** | Showing only necessary details; hiding implementation complexity |
| **Inheritance** | One class acquiring another class's properties and behaviors |
| **Polymorphism** | One function/interface, many forms (compile-time & runtime) |

---

## OOPS vs Procedural Programming

| Feature | Procedural Programming | OOPS |
|---------|------------------------|------|
| **Approach** | Function-oriented | Object-oriented |
| **Focus** | Logic & procedures | Real-world objects |
| **Data Security** | ❌ Low | ✅ High (encapsulation) |
| **Code Reuse** | ❌ Difficult | ✅ Easy (inheritance) |
| **Maintainability** | ❌ Hard for large code | ✅ Easy |
| **Data & Functions** | Separate | Wrapped together |
| **Examples** | C | C++, Java, Python |

---

## Quick Reference

```
Class (Blueprint)
    │
    ├── Encapsulation (Data + Methods bundled)
    ├── Abstraction (Hide complexity)
    ├── Inheritance (Reuse & extend)
    └── Polymorphism (Many forms)
         ├── Compile-time (Overloading)
         └── Runtime (Overriding)
```

> **Key Takeaway:** OOPS helps build scalable, maintainable, and secure software by modeling real-world entities as objects.