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
│   │   └── Adapter.md            # Documentation
│   ├── Decorator_Pattern/        # Structural: Dynamic behavior addition
│   │   ├── CMakeLists.txt        # CMake build configuration
│   │   ├── Decorator.md          # Documentation
│   │   ├── build/                # Build output
│   │   ├── include/              # Header files (Coffee example)
│   │   ├── src/                  # Source files (Coffee example)
│   │   └── Task/                 # Notification system example
│   │       ├── CMakeLists.txt
│   │       ├── include/          # Headers (Notification, Decorators)
│   │       └── src/main.cpp      # Main implementation
│   ├── Factory_Pattern/          # Creational: Object creation abstraction
│   │   ├── Factory.md            # Documentation
│   │   ├── *.hpp                 # Payment implementations
│   │   ├── main.cpp              # Basic example
│   │   └── Task/                 # Notification factory example
│   │       ├── *.hpp             # Notification creators & factory
│   │       └── main.cpp
│   ├── Observer_Pattern/         # Behavioral: Event notification
│   │   ├── CMakeLists.txt        # CMake build configuration
│   │   ├── Observer.md           # Documentation
│   │   ├── README.md             # Additional docs
│   │   ├── build/                # Build output
│   │   ├── include/              # Header files
│   │   ├── src/                  # Source files
│   │   └── Task/                 # Additional example
│   │       ├── CMakeLists.txt
│   │       ├── include/
│   │       └── src/
│   ├── Singleton_Pattern/        # Creational: Single instance guarantee
│   │   └── Singleton.md          # Documentation
│   └── Strategy_Pattern/         # Behavioral: Algorithm interchangeability
│       ├── Strategy.md           # Documentation
│       ├── *.hpp                 # Payment strategies
│       ├── main.cpp              # Basic example
│       └── Task/                 # Discount strategy example
│           ├── *.hpp             # Discount strategies
│           └── main.cpp
│
├── OOPS/                         # Object-Oriented Programming Concepts
│   ├── Abstraction/              # Abstract classes & interfaces
│   │   └── Abstraction.md
│   ├── Access Specifiers/        # public, private, protected
│   ├── Constructor/              # Constructor types & initialization
│   │   └── Constructor.md
│   ├── Deconstructor/            # Destructors & cleanup
│   │   ├── Deconstructor.md
│   │   └── Constructor_Vs_Destructor.md
│   ├── Deep_Copy/                # Deep copy implementation
│   │   └── Deep_Copy.md
│   ├── Diamond_Ambiguity/        # Virtual inheritance solution
│   │   └── Diamond.md
│   ├── Encapsulation/            # Data hiding & access control
│   │   └── Encapsulation_in_CPP.md
│   ├── Inheritance/              # Inheritance types & examples
│   │   ├── Inheritance.md
│   │   └── Inheritance_Types_Complete_Guide.md
│   ├── MemoryAllocation_DOCS/    # Stack vs Heap allocation
│   │   ├── CompileTimeMemoryAllocation.md
│   │   ├── MemoryAllocation.md
│   │   └── RuntimeMemoryAllocation.md
│   ├── Polymorphism/             # Compile-time & runtime polymorphism
│   │   └── Polymorphism.md
│   ├── ShallowCopy/              # Shallow copy & pitfalls
│   │   ├── Shallow_Copy.md
│   │   └── Shallow_vs_Deep_Copy_Comparison.md
│   ├── Static/                   # Static members & methods
│   │   ├── Static.md
│   │   └── StaticMethod.md
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
│       ├── Ecommerce.cpp         # Full SOLID implementation
│       └── Ecommerce.exe
│
└── grad-joi-delivery-cpp/        # External project (ignored by git)
```

---

## 🎯 Design Patterns

| Pattern | Category | Description | Documentation | Examples |
|---------|----------|-------------|---------------|----------|
| **Factory** | Creational | Centralized object creation, hides instantiation logic | [Factory.md](Design_Patterns/Factory_Pattern/Factory.md) | Basic + Notification Factory (Task/) |
| **Singleton** | Creational | Ensures single instance with global access | [Singleton.md](Design_Patterns/Singleton_Pattern/Singleton.md) | - |
| **Adapter** | Structural | Makes incompatible interfaces work together | [Adapter.md](Design_Patterns/Adapter_Pattern/Adapter.md) | - |
| **Decorator** | Structural | Adds behavior dynamically without subclassing | [Decorator.md](Design_Patterns/Decorator_Pattern/Decorator.md) | Coffee + Notification System (Task/) |
| **Observer** | Behavioral | One-to-many dependency with automatic notification | [Observer.md](Design_Patterns/Observer_Pattern/Observer.md) | Basic + Task example |
| **Strategy** | Behavioral | Encapsulates interchangeable algorithms | [Strategy.md](Design_Patterns/Strategy_Pattern/Strategy.md) | Payment + Discount System (Task/) |

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
| Is Sorted | `is_sorted.cpp` | Easy |
| Left Rotate | `left_rotate.cpp` | Easy |
| Max Consecutive | `max_consecutive.cpp` | Easy |
| Maximum | `maximum.cpp` | Easy |
| Mini and Max | `mini_and_max.cpp` | Easy |
| Minimum in Rotated Sorted Array | `minium_in_rotated_sorted_array.cpp` | Medium |
| Missing Number | `missing_num.cpp` | Easy |
| Movie Star | `movie_star.cpp` | Medium |
| Remove Duplicates | `remove_duplicates.cpp` | Easy |
| Reverse Array | `reverse_array.cpp` | Easy |
| Right Rotate | `right_rotate.cpp` | Easy |
| Right Rotate by K | `right_rotate_by_k.cpp` | Easy |
| Search in Rotated Sorted Array | `search_in_rotated_sorted_array.cpp` | Medium |
| Second Largest | `second_largest.cpp` | Easy |
| Sort Array | `sort_array.cpp` | Easy |
| Subarray Maximum Size K | `subarray_maximum_size_k.cpp` | Medium |
| Union of Sorted Arrays | `union_of_sorted_array.cpp` | Easy |

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
| Longest Common Prefix | `longest_common_prefix.cpp` |

---

## 🏗️ OOP Concepts (C++)

| Topic | Documentation | Key Concepts |
|-------|---------------|--------------|
| **Abstraction** | [Abstraction.md](OOPS/Abstraction/Abstraction.md) | Abstract classes, pure virtual functions, interfaces |
| **Encapsulation** | [Encapsulation_in_CPP.md](OOPS/Encapsulation/Encapsulation_in_CPP.md) | Data hiding, getters/setters, access specifiers |
| **Inheritance** | [Inheritance.md](OOPS/Inheritance/Inheritance.md), [Complete Guide](OOPS/Inheritance/Inheritance_Types_Complete_Guide.md) | Single, multiple, multilevel, hierarchical, hybrid |
| **Polymorphism** | [Polymorphism.md](OOPS/Polymorphism/Polymorphism.md) | Compile-time (overloading), runtime (virtual functions) |
| **Constructor** | [Constructor.md](OOPS/Constructor/Constructor.md) | Default, parameterized, copy, move, delegation |
| **Destructor** | [Deconstructor.md](OOPS/Deconstructor/Deconstructor.md), [Constructor vs Destructor](OOPS/Deconstructor/Constructor_Vs_Destructor.md) | Cleanup, virtual destructors, RAII |
| **Static** | [Static.md](OOPS/Static/Static.md), [StaticMethod.md](OOPS/Static/StaticMethod.md) | Static members, methods, initialization |
| **Virtual** | [Virtual/](OOPS/Virtual/) | Virtual functions, vtable, override, final |
| **Memory Allocation** | [MemoryAllocation.md](OOPS/MemoryAllocation_DOCS/MemoryAllocation.md), [Compile-time](OOPS/MemoryAllocation_DOCS/CompileTimeMemoryAllocation.md), [Runtime](OOPS/MemoryAllocation_DOCS/RuntimeMemoryAllocation.md) | Stack vs Heap, new/delete, smart pointers |
| **Shallow vs Deep Copy** | [Shallow_Copy.md](OOPS/ShallowCopy/Shallow_Copy.md), [Deep_Copy.md](OOPS/Deep_Copy/Deep_Copy.md), [Comparison](OOPS/ShallowCopy/Shallow_vs_Deep_Copy_Comparison.md) | Copy constructor, assignment operator, rule of 3/5 |
| **Diamond Problem** | [Diamond.md](OOPS/Diamond_Ambiguity/Diamond.md) | Virtual inheritance, ambiguity resolution |
| **Why OOP** | [WhyOOPS.md](OOPS/WhyOOPS.md) | Benefits and importance of OOP |

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
  - Includes compiled executable: `Ecommerce.exe`

---

## 🚀 Getting Started

### Prerequisites
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 19.1+)
- CMake 3.10+ (for CMake-based projects)
- Git

### Compile & Run Examples

#### Simple Single-File Examples
```bash
# Compile a single file
g++ -std=c++17 -o output Design_Patterns/Factory_Pattern/Task/main.cpp

# Run
./output

# Or use the provided executables (Windows)
Design_Patterns/Factory_Pattern/Task/main.exe
```

#### CMake-Based Projects (Decorator, Observer)
```bash
# Decorator Pattern
cd Design_Patterns/Decorator_Pattern
mkdir build && cd build
cmake ..
cmake --build . --config Debug
./Debug/ObserverPattern.exe  # Note: executable name from CMakeLists.txt

# Observer Pattern
cd Design_Patterns/Observer_Pattern
mkdir build && cd build
cmake ..
cmake --build . --config Debug
./Debug/ObserverPattern.exe
```

#### Factory Pattern Task (Notification Factory)
```bash
cd Design_Patterns/Factory_Pattern/Task
g++ -std=c++17 -I. -o main.exe main.cpp *.hpp
./main.exe
```

#### Strategy Pattern Task (Discount System)
```bash
cd Design_Patterns/Strategy_Pattern/Task
g++ -std=c++17 -I. -o main.exe main.cpp *.hpp
./main.exe
```

#### SOLID Principles E-commerce Example
```bash
cd Solid_Principles/Task
g++ -std=c++17 -o Ecommerce.exe Ecommerce.cpp
./Ecommerce.exe
```

### Build with CMake (External Project)
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

## 🎯 Pattern Task Examples Summary

Each design pattern includes a practical **Task/** folder with real-world examples:

| Pattern | Task Example | Description |
|---------|--------------|-------------|
| **Factory** | Notification Factory | Email, SMS, Push notification creators with factory |
| **Decorator** | Notification System | Email base + SMS + WhatsApp decorators |
| **Observer** | Event System | Subject/Observer with concrete implementations |
| **Strategy** | Discount System | Regular, Premium, Festival discount strategies |
| **Singleton** | - | Documentation only |
| **Adapter** | - | Documentation only |

### Quick Test Commands
```bash
# Test all pattern tasks
cd Design_Patterns/Factory_Pattern/Task && g++ -std=c++17 -I. -o test.exe main.cpp *.hpp && ./test.exe
cd Design_Patterns/Decorator_Pattern/Task && mkdir -p build && cd build && cmake .. && cmake --build . --config Debug && ./Debug/ObserverPattern.exe
cd Design_Patterns/Strategy_Pattern/Task && g++ -std=c++17 -I. -o test.exe main.cpp *.hpp && ./test.exe
cd Solid_Principles/Task && g++ -std=c++17 -o test.exe Ecommerce.cpp && ./test.exe
```

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

## 📊 Repository Statistics

| Category | Count | Details |
|----------|-------|---------|
| **Design Patterns** | 6 | Factory, Singleton, Adapter, Decorator, Observer, Strategy |
| **Pattern Tasks** | 4 | Factory, Decorator, Observer, Strategy have practical examples |
| **OOP Concepts** | 14 | Abstraction, Encapsulation, Inheritance, Polymorphism, etc. |
| **OOP Documentation** | 18 | Markdown files covering all concepts |
| **SOLID Principles** | 5 | SRP, OCP, LSP, ISP, DIP |
| **DSA Problems** | 30+ | Arrays (25), LinkedList (1), Strings (8) |
| **Total C++ Files** | 50+ | Headers, sources, and executables |

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