# Memory Allocation in OOPS

OOPS languages (like C++, Java) allocate memory based on objects and classes.

## In C++ (OOPS + Manual Control)

### Memory Areas

| Area | What it stores |
|------|----------------|
| **Stack** | Local objects, function calls, local variables |
| **Heap** | Objects created using `new` (dynamic allocation) |
| **Data Segment** | Static members, global variables |
| **Code Segment** | Class methods, function code |

---

### Example (C++)

```cpp
class Student {
public:
    int id;
};

int main() {
    Student s1;              // Stack memory (automatic storage)
    Student* s2 = new Student();  // Heap memory (dynamic storage)
    
    // Don't forget to free heap memory!
    delete s2;
    return 0;
}
```

---

### Key Points

| Aspect | Stack | Heap |
|--------|-------|------|
| **Allocation** | Automatic | Manual (`new`/`delete`) |
| **Lifetime** | Scope-bound | Programmer-controlled |
| **Speed** | Faster | Slower |
| **Size** | Limited (~MB) | Large (limited by RAM) |
| **Fragmentation** | No | Yes |

---

### Memory Layout Visualization

```
┌─────────────────────────────────────┐
│           Code Segment              │  ← Class methods, functions
├─────────────────────────────────────┤
│           Data Segment              │  ← Static members, globals
├─────────────────────────────────────┤
│              Heap                   │  ← Dynamic objects (new)
│           (grows up)                │
├─────────────────────────────────────┤
│              Stack                  │  ← Local objects, calls
│           (grows down)              │
└─────────────────────────────────────┘
```

---

### Best Practices

1. **Prefer stack allocation** for small, short-lived objects
2. **Use smart pointers** (`std::unique_ptr`, `std::shared_ptr`) instead of raw `new`/`delete`
3. **Always pair `new` with `delete`** (or `new[]` with `delete[]`)
4. **Static members** belong to the class, not instances — stored in Data Segment
5. **Methods** are stored once in Code Segment, shared by all instances

> **Note:** C++ gives you manual control over memory, unlike Java/C# which use garbage collection. This enables optimization but requires discipline.