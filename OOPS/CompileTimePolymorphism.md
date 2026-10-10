# Compile-Time Memory Allocation (Static Allocation)

## What does it mean?

Memory is decided and reserved **before the program starts running** (during compilation).

- Size is **fixed**
- Memory **cannot change** at runtime

### Simple Analogy

> 📦 You book fixed seats before a movie starts — no changes later.

---

## Characteristics

| Characteristic | Description |
|----------------|-------------|
| **Allocation Time** | Compile time |
| **Size Requirement** | Must be known in advance |
| **Storage Location** | Stack or Data Segment |
| **Speed** | Faster |
| **Flexibility** | Less flexible |

---

## Example (C/C++)

```cpp
int a = 10;        // Fixed size (4 bytes typically)
int arr[5];        // Size known at compile time (5 * 4 = 20 bytes)
int arr2[10] = {1, 2, 3};  // Remaining elements zero-initialized
```

---

## Where Memory Goes

| Type | Memory Area |
|------|-------------|
| **Local variables** | Stack |
| **Global/static variables** | Data Segment |

---

## Stack vs Data Segment (Static Allocation)

| Aspect | Stack (Local) | Data Segment (Global/Static) |
|--------|---------------|------------------------------|
| **Lifetime** | Function scope | Program lifetime |
| **Initialization** | Uninitialized (garbage) | Zero-initialized by default |
| **Access** | Only within function | Accessible globally (if global) |
| **Thread Safety** | Thread-local | Shared across threads |

---

## Pros & Cons

| ✅ Pros | ❌ Cons |
|---------|---------|
| Fast allocation/deallocation | Size must be known at compile time |
| No memory leaks (auto cleanup) | Cannot resize at runtime |
| Predictable memory usage | Limited stack size (~1-8 MB) |
| Cache-friendly (contiguous) | Risk of stack overflow for large arrays |

---

## When to Use

- Small, fixed-size data
- Performance-critical code
- When size is known at compile time
- Local variables in functions

> **Note:** This is also called **Static Allocation** because the memory size is static (fixed) at compile time.