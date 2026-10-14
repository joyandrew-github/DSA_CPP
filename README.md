# DSA & C++ Design Patterns Repository

A comprehensive collection of **Data Structures & Algorithms**, **Object-Oriented Programming concepts**, **SOLID Principles**, and **Design Patterns** implemented in C++.

---

## 📁 Repository Structure

```
DSA/
├── DSA/                          # Data Structures & Algorithms
│   ├── Arrays/                   # Array problems & solutions
│   ├── LinkedList/               # Linked list implementations
│   └── Strings/                  # String manipulation problems
│
├── Design_Patterns/              # Gang of Four Design Patterns
│   ├── Adapter_Pattern/          # Structural: Interface compatibility
│   ├── Decorator_Pattern/        # Structural: Dynamic behavior addition
│   ├── Factory_Pattern/          # Creational: Object creation abstraction
│   ├── Observer_Pattern/         # Behavioral: Event notification
│   ├── Singleton_Pattern/        # Creational: Single instance guarantee
│   └── Strategy_Pattern/         # Behavioral: Algorithm interchangeability
│
├── OOPS/                         # Object-Oriented Programming Concepts
│   ├── Abstraction/              # Abstract classes & interfaces
│   ├── Access Specifiers/        # public, private, protected
│   ├── Constructor/              # Constructor types & initialization
│   ├── Deconstructor/            # Destructors & cleanup
│   ├── Deep_Copy/                # Deep copy implementation
│   ├── Diamond_Ambiguity/        # Virtual inheritance solution
│   ├── Encapsulation/            # Data hiding & access control
│   ├── Inheritance/              # Inheritance types & examples
│   ├── MemoryAllocation_DOCS/    # Stack vs Heap allocation
│   ├── Polymorphism/             # Compile-time & runtime polymorphism
│   ├── ShallowCopy/              # Shallow copy & pitfalls
│   ├── Static/                   # Static members & methods
│   ├── Virtual/                  # Virtual functions & vtables
│   └── WhyOOPS.md                # Why OOP matters
│
├── Solid_Principles/             # SOLID Design Principles
│   ├── Single_Responsibility_Principle/
│   ├── Open_Closed_Principle/
│   ├── Liskov_Substitution_Principle/
│   ├── Dependency_Inversion_Principle/
│   ├── Inversion_Dependency_Principle/
│   └── Task/                     # Practical E-commerce example
│
└── grad-joi-delivery-cpp/        # External project (ignored by git)
```

---

## 🎯 Design Patterns

| Pattern | Category | Description | Documentation |
|---------|----------|-------------|---------------|
| **Factory** | Creational | Centralized object creation, hides instantiation logic | [Factory.md](Design_Patterns/Factory_Pattern/Factory.md) |
| **Singleton** | Creational | Ensures single instance with global access | [Singleton.md](Design_Patterns/Singleton_Pattern/Singleton.md) |
| **Adapter** | Structural | Makes incompatible interfaces work together | [Adapter.md](Design_Patterns/Adapter_Pattern/Adapter.md) |
| **Decorator** | Structural | Adds behavior dynamically without subclassing | [Decorator.md](Design_Patterns/Decorator_Pattern/Decorator.md) |
| **Observer** | Behavioral | One-to-many dependency with automatic notification | [Observer.md](Design_Patterns/Observer_Pattern/Observer.md) |
| **Strategy** | Behavioral | Encapsulates interchangeable algorithms | [Strategy.md](Design_Patterns/Strategy_Pattern/Strategy.md) |

### Pattern Quick Reference

```
Creational Patterns (Object Creation)
├── Factory Method    → "Create objects without specifying exact class"
├── Abstract Factory  → "Create families of related objects"
├── Builder           → "Construct complex objects step by step"
├── Prototype         → "Clone existing objects"
└── Singleton         → "Ensure only one instance exists"

Structural Patterns (Composition)
├── Adapter           → "Bridge incompatible interfaces"
├── Bridge            → "Separate abstraction from implementation"
├── Composite         → "Tree structures of objects"
├── Decorator         → "Add responsibilities dynamically"
├── Facade            → "Simplify complex subsystem interface"
├── Flyweight         → "Share objects to reduce memory"
└── Proxy             → "Control access to object"

Behavioral Patterns (Communication)
├── Chain of Responsibility → "Pass request along handler chain"
├── Command           → "Encapsulate request as object"
├── Interpreter       → "Define grammar & interpreter"
├── Iterator          → "Sequential access without exposing structure"
├── Mediator          → "Centralize object communication"
├── Memento           → "Capture & restore object state"
├── Observer          → "Notify dependents of state changes"
├── State             → "Change behavior with internal state"
├── Strategy          → "Encapsulate interchangeable algorithms"
├── Template Method   → "Define algorithm skeleton"
└── Visitor           → "Add operations without modifying classes"
```

---

## 📚 Data Structures & Algorithms

### Arrays
| Problem | File | Difficulty |
|---------|------|------------|
| Two Sum | `two_sum.cpp` | Easy |
| Best Time to Buy & Sell Stock | `best_time_to_buy_and_sell.cpp` | Easy |
| Maximum Subarray (Kadane) | `maximum_subarray.cpp` | Medium |
| Subarray Sum Equals K | `subarray_sum_equals_k.cpp` | Medium |
| Merge Two Sorted Arrays | `merge_two_sorted_array.cpp` | Easy |
| Rotate Array by K | `rotate_array_by_k.cpp` | Medium |
| Find Duplicates | `find_duplicates.cpp` | Easy |
| Move Zeros | `move_zero.cpp` | Easy |
| Majority Element | `majority_element.cpp` | Easy |
| Binary Search | `binary_search.cpp` | Easy |
| Linear Search | `linear_search.cpp` | Easy |

### Linked Lists
| Problem | File |
|---------|------|
| Remove Duplicates | `remove_duplicate.cpp` |

### Strings
| Problem | File |
|---------|------|
| Valid Palindrome | `valid_palindrome.cpp` |
| Valid Anagram | `valid_anagram.cpp` |
| Group Anagrams | `group_anagram.cpp` |
| Longest Substring Without Repeating | `longest_substring_without_repeating.cpp` |
| First Unique Character | `first_unique_character.cpp` |
| Reverse String | `reverse_string.cpp` |
| Ransom Note | `ransome_note.cpp` |

---

## 🏗️ OOP Concepts (C++)

| Topic | Documentation | Key Concepts |
|-------|---------------|--------------|
| **Abstraction** | [Abstraction.md](OOPS/Abstraction/Abstraction.md) | Abstract classes, pure virtual functions, interfaces |
| **Encapsulation** | [Encapsulation_in_CPP.md](OOPS/Encapsulation/Encapsulation_in_CPP.md) | Data hiding, getters/setters, access specifiers |
| **Inheritance** | [Inheritance.md](OOPS/Inheritance/Inheritance.md) | Single, multiple, multilevel, hierarchical, hybrid |
| **Polymorphism** | [Polymorphism.md](OOPS/Polymorphism/Polymorphism.md) | Compile-time (overloading), runtime (virtual functions) |
| **Constructor** | [Constructor.md](OOPS/Constructor/Constructor.md) | Default, parameterized, copy, move, delegation |
| **Destructor** | [Deconstructor.md](OOPS/Deconstructor/Deconstructor.md) | Cleanup, virtual destructors, RAII |
| **Static** | [Static.md](OOPS/Static/Static.md) | Static members, methods, initialization |
| **Virtual** | [Virtual/](OOPS/Virtual/) | Virtual functions, vtable, override, final |
| **Memory Allocation** | [MemoryAllocation.md](OOPS/MemoryAllocation_DOCS/MemoryAllocation.md) | Stack vs Heap, new/delete, smart pointers |
| **Shallow vs Deep Copy** | [Shallow_vs_Deep_Copy_Comparison.md](OOPS/ShallowCopy/Shallow_vs_Deep_Copy_Comparison.md) | Copy constructor, assignment operator, rule of 3/5 |
| **Diamond Problem** | [Diamond_Ambiguity/](OOPS/Diamond_Ambiguity/) | Virtual inheritance, ambiguity resolution |

---

## ✅ SOLID Principles

| Principle | Acronym | Documentation | Core Idea |
|-----------|---------|---------------|-----------|
| **Single Responsibility** | SRP | [SRP.md](Solid_Principles/Single_Responsibility_Principle/SRP.md) | A class should have one reason to change |
| **Open-Closed** | OCP | [Ocp.md](Solid_Principles/Open_Closed_Principle/Ocp.md) | Open for extension, closed for modification |
| **Liskov Substitution** | LSP | [Lsp.md](Solid_Principles/Liskov_Substitution_Principle/Lsp.md) | Subtypes must be substitutable for base types |
| **Interface Segregation** | ISP | [IDP.md](Solid_Principles/Dependency_Inversion_Principle/Dip.md) | Clients shouldn't depend on unused interfaces |
| **Dependency Inversion** | DIP | [Dip.md](Solid_Principles/Dependency_Inversion_Principle/Dip.md) | Depend on abstractions, not concretions |

### Practical Example
- **E-commerce System** → [Task/Ecommerce.cpp](Solid_Principles/Task/Ecommerce.cpp)
  - Demonstrates all 5 SOLID principles in a real-world scenario

---

## 🚀 Getting Started

### Prerequisites
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 19.1+)
- CMake 3.10+ (for some projects)
- Git

### Compile & Run Examples

```bash
# Compile a single file
g++ -std=c++17 -o output Design_Patterns/Factory_Pattern/Task/main.cpp

# Run
./output

# Or use the provided executables (Windows)
Design_Patterns/Factory_Pattern/Task/main.exe
```

### Build with CMake (where available)
```bash
cd grad-joi-delivery-cpp
mkdir build && cd build
cmake ..
cmake --build .
```

---

## 📖 Learning Path Recommendations

### Beginner → Intermediate
1. **OOP Basics** → `OOPS/` (Encapsulation, Inheritance, Polymorphism)
2. **Memory Management** → `OOPS/MemoryAllocation_DOCS/`
3. **Copy Semantics** → `OOPS/ShallowCopy/`, `OOPS/Deep_Copy/`

### Intermediate → Advanced
4. **SOLID Principles** → `Solid_Principles/` (SRP → OCP → LSP → ISP → DIP)
5. **Design Patterns** → `Design_Patterns/` (Start with Factory, Strategy, Observer)

### Practice
6. **DSA Problems** → `DSA/` (Arrays → Strings → Linked Lists)

---

## 📝 Documentation Standards

Each pattern/concept documentation includes:
- ✅ **Overview** with core idea
- ✅ **Problem/Solution** comparison tables
- ✅ **Structure diagrams** (ASCII)
- ✅ **Complete implementation** with modern C++
- ✅ **Real-world examples** & use cases
- ✅ **Benefits/Drawbacks** analysis
- ✅ **Pattern comparisons**
- ✅ **Key takeaways** & summary

---

## 🛠️ Tech Stack

- **Language**: C++17/20
- **Build**: CMake, Make, g++
- **Patterns**: Gang of Four (GoF)
- **Principles**: SOLID (Robert C. Martin)
- **Documentation**: Markdown with Mermaid diagrams

---

## 📄 License

This repository is for educational purposes. Feel free to use, modify, and learn from the code.

---

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Add your implementation with documentation
4. Submit a pull request

---

## 📌 Quick Links

- [Design Patterns Overview](#-design-patterns)
- [DSA Problems](#-data-structures--algorithms)
- [OOP Concepts](#-oop-concepts-c)
- [SOLID Principles](#-solid-principles)
- [Getting Started](#-getting-started)

---

> **Quote**: *"Good code is its own best documentation."* — Steve McConnell

> **Remember**: Patterns are discovered, not invented. They're proven solutions to recurring problems.