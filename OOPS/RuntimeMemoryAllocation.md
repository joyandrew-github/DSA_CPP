# Run-Time Memory Allocation (Dynamic Allocation)

## What does it mean?

Memory is allocated **while the program is running**.

- Size can be **decided at runtime**
- Memory is **flexible**

### Simple Analogy

> 🛒 You buy items while shopping, not before entering the shop.

---

## Characteristics

| Characteristic | Description |
|----------------|-------------|
| **Allocation Time** | Runtime |
| **Size Flexibility** | Can grow or shrink |
| **Storage Location** | Heap |
| **Speed** | Slower than compile-time |
| **Management** | Manual (programmer responsibility) |

---

## Example (C++)

```cpp
// Single object
int* p = new int;           // Allocate 1 int on heap
*p = 42;                    // Use the memory
delete p;                   // Free memory (CRITICAL!)

// Array
int n;
std::cin >> n;              // Size decided at runtime
int* arr = new int[n];      // Allocate array of size n
// ... use arr ...
delete[] arr;               // Free array (use delete[] for arrays!)

// Object
class Student {
public:
    int id;
    std::string name;
};

Student* s = new Student(); // Allocate object on heap
s->id = 1;
delete s;                   // Free object
```

---

## Heap Memory

| Aspect | Description |
|--------|-------------|
| **Location** | Heap (free store) |
| **Lifetime** | Until explicitly freed (`delete`) |
| **Scope** | Accessible via pointer from anywhere |
| **Size Limit** | Limited by available RAM |
| **Fragmentation** | Can occur over time |

---

## Pros & Cons

| ✅ Pros | ❌ Cons |
|---------|---------|
| Size decided at runtime | Slower allocation/deallocation |
| Can resize (reallocate) | Manual management required |
| Large memory available | Risk of memory leaks |
| Shared across functions | Risk of dangling pointers |
| Objects can outlive scope | Fragmentation possible |

---

## Common Pitfalls

| Pitfall | Problem | Solution |
|---------|---------|----------|
| **Memory Leak** | Forgot `delete` | Use smart pointers |
| **Double Free** | `delete` twice | Set pointer to `nullptr` after delete |
| **Use After Free** | Access freed memory | Set pointer to `nullptr` after delete |
| **Wrong Delete** | `delete` vs `delete[]` | Match `new` with `delete`, `new[]` with `delete[]` |
| **Uninitialized Pointer** | Wild pointer | Initialize to `nullptr` |

---

## Modern C++ Best Practice: Smart Pointers

```cpp
#include <memory>

// Unique ownership (auto-deletes when out of scope)
std::unique_ptr<int> p = std::make_unique<int>(42);
std::unique_ptr<int[]> arr = std::make_unique<int[]>(n);

// Shared ownership (reference counted)
std::shared_ptr<Student> s = std::make_shared<Student>();

// Weak reference (breaks cycles)
std::weak_ptr<Student> weak = s;
```

> **Rule of Thumb:** Prefer `std::unique_ptr` / `std::shared_ptr` over raw `new`/`delete`. They provide automatic cleanup (RAII) and prevent memory leaks.