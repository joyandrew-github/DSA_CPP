# Encapsulation in C++

## 1. Introduction

Encapsulation is one of the four fundamental pillars of Object-Oriented
Programming (OOP).

The four pillars of OOP are:

1.  Encapsulation
2.  Abstraction
3.  Inheritance
4.  Polymorphism

**Encapsulation is the process of bundling data (variables) and the
functions that operate on that data into a single unit called a class,
while controlling access to the data.**

In simple words, encapsulation means keeping data and its related
operations together and controlling how the data can be accessed or
modified.

### Real-world analogy: Bank account

Imagine a bank account with a balance of ₹5,000. You cannot normally
change the bank's balance records directly. Instead, you use permitted
operations such as depositing or withdrawing money. The bank can
validate each operation before changing the balance.

A C++ class can follow the same idea:

-   The balance is private data.
-   Deposit and withdrawal are public operations.
-   The operations validate requests before modifying the balance.

------------------------------------------------------------------------

## 2. Why do we need encapsulation?

Consider a class whose data members are public:

``` cpp
#include <iostream>
using namespace std;

class BankAccount {
public:
    int balance = 1000;
};

int main() {
    BankAccount account;

    cout << account.balance << endl;

    account.balance = -5000;  // Invalid balance is allowed
    cout << account.balance << endl;

    return 0;
}
```

Output:

``` text
1000
-5000
```

### Problems with this design

-   Any code with access to the object can change its balance directly.
-   Invalid values can be stored.
-   The class cannot enforce rules whenever the value changes.
-   If the internal representation changes, code that directly accesses
    the data may need to change too.

Encapsulation helps the class control how its state is used.

------------------------------------------------------------------------

## 3. How encapsulation works in C++

C++ classes use **access specifiers** to control access to their
members.

### Access specifiers

  -----------------------------------------------------------------------
  Access specifier                    Access rule
  ----------------------------------- -----------------------------------
  `private`                           Accessible from member functions of
                                      the class and its friends; not
                                      directly accessible from unrelated
                                      outside code or derived-class
                                      member functions.

  `public`                            Accessible wherever the object or
                                      member itself is accessible.

  `protected`                         Accessible from the class, its
                                      friends, and derived classes,
                                      subject to C++ access rules.
  -----------------------------------------------------------------------

For encapsulation, a common design is:

-   Store internal data members as `private`.
-   Provide selected `public` methods for reading or modifying the data.
-   Validate inputs before changing the object's state.

**Important:** Class members are `private` by default in a C++ `class`.
In a `struct`, members are `public` by default.

``` cpp
class Example {
    int value;  // private by default
};
```

This is equivalent to:

``` cpp
class Example {
private:
    int value;
};
```

------------------------------------------------------------------------

## 4. Getter and setter methods

A **getter** provides a way to read a value. A **setter** provides a way
to request a change to a value.

  Method   Purpose                         Example
  -------- ------------------------------- ----------------
  Getter   Returns a value                 `getMarks()`
  Setter   Validates and updates a value   `setMarks(85)`

Getters and setters are common techniques for encapsulation, but they
are not mandatory. A class should expose only the operations that make
sense for its design.

### Simple example

``` cpp
#include <iostream>
using namespace std;

class Student {
private:
    int marks = 0;

public:
    void setMarks(int m) {
        if (m >= 0 && m <= 100) {
            marks = m;
        } else {
            cout << "Invalid marks!" << endl;
        }
    }

    int getMarks() const {
        return marks;
    }
};

int main() {
    Student s;

    s.setMarks(85);
    cout << s.getMarks() << endl;

    s.setMarks(150);
    cout << s.getMarks() << endl;

    return 0;
}
```

Output:

``` text
85
Invalid marks!
85
```

### Explanation

1.  `marks` is private, so unrelated code cannot directly access
    `s.marks`.
2.  `setMarks(85)` checks whether 85 is between 0 and 100. It is valid,
    so the value is updated.
3.  `getMarks()` returns the current marks.
4.  `setMarks(150)` fails validation, so the existing value remains 85.
5.  The final getter call still returns 85.

The important point is that **validation happens before assignment**. If
we assigned `marks = m` before checking the range, invalid data could
overwrite the previous valid value.

------------------------------------------------------------------------

## 5. Complete practice example: Student Grade Management System

### Scenario

Build a `Student` class that stores a student's name, roll number, and
marks. The class must protect its data and validate inputs.

### Requirements

-   `name`, `rollNumber`, and `marks` must be private.
-   The name must not be empty.
-   The roll number must be positive.
-   Marks must be between 0 and 100, inclusive.
-   Invalid input must not overwrite a previously valid value.
-   Provide getters and a method to display student details.
-   A student passes if their marks are at least 40.

### Complete implementation

``` cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber = 0;
    int marks = 0;

public:
    void setName(const string& n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Name cannot be empty!" << endl;
        }
    }

    string getName() const {
        return name;
    }

    void setRollNumber(int r) {
        if (r > 0) {
            rollNumber = r;
        } else {
            cout << "Roll number must be positive!" << endl;
        }
    }

    int getRollNumber() const {
        return rollNumber;
    }

    void setMarks(int m) {
        if (m >= 0 && m <= 100) {
            marks = m;
        } else {
            cout << "Invalid marks!" << endl;
        }
    }

    int getMarks() const {
        return marks;
    }

    bool hasPassed() const {
        return marks >= 40;
    }

    void displayDetails() const {
        cout << "Student Name : " << getName() << endl;
        cout << "Roll No      : " << getRollNumber() << endl;
        cout << "Marks        : " << getMarks() << endl;
        cout << "Result       : " << (hasPassed() ? "Pass" : "Fail") << endl;
    }
};

int main() {
    Student s;

    s.setName("Joy");
    s.setRollNumber(101);
    s.setMarks(85);

    s.displayDetails();

    cout << "\nTrying invalid values..." << endl;
    s.setName("");
    s.setRollNumber(-1);
    s.setMarks(150);

    cout << "\nStudent details after invalid inputs:" << endl;
    s.displayDetails();

    return 0;
}
```

### Expected output

``` text
Student Name : Joy
Roll No      : 101
Marks        : 85
Result       : Pass

Trying invalid values...
Name cannot be empty!
Roll number must be positive!
Invalid marks!

Student details after invalid inputs:
Student Name : Joy
Roll No      : 101
Marks        : 85
Result       : Pass
```

### How this demonstrates encapsulation

-   **Data hiding:** The three data members are private.
-   **Controlled modification:** The public setter methods are the
    intended way to request updates.
-   **Validation:** Each setter checks its input before assignment.
-   **State preservation:** Invalid inputs leave the existing values
    unchanged.
-   **Public behavior:** `hasPassed()` exposes a meaningful operation
    without exposing internal data.

### Why are some methods marked `const`?

For example:

``` cpp
int getMarks() const {
    return marks;
}
```

The `const` after the parameter list means the method promises not to
modify the object's ordinary member state. It is appropriate for getters
and other read-only operations.

The declaration:

``` cpp
void setName(const string& n)
```

uses `const string&` to accept a string by reference without copying it
and without allowing the method to modify the argument through that
reference.

------------------------------------------------------------------------

## 6. Important correction: encapsulation is more than private variables

Making data members private is a useful part of encapsulation, but good
encapsulation also involves designing an appropriate public interface.

For example, this class technically hides its data but provides
unrestricted setters:

``` cpp
class Temperature {
private:
    double celsius = 0;

public:
    void setCelsius(double value) {
        celsius = value;
    }

    double getCelsius() const {
        return celsius;
    }
};
```

If the application requires a restricted temperature range, this setter
does not enforce that rule. The class hides the field but does not
validate the value.

A better design depends on the application's requirements:

``` cpp
class Temperature {
private:
    double celsius = 0;

public:
    bool setCelsius(double value) {
        if (value < -273.15) {
            return false;  // Below absolute zero
        }

        celsius = value;
        return true;
    }

    double getCelsius() const {
        return celsius;
    }
};
```

This setter returns `true` when the update succeeds and `false` when it
rejects the value. The example uses the physical lower limit of Celsius
temperature; real applications may require additional domain-specific
checks.

**Design principle:** Do not automatically create a getter and setter
for every field. Expose operations that preserve the rules of the class.

------------------------------------------------------------------------

## 7. Encapsulation vs. data hiding

These terms are related, but they are not exactly identical.

  -----------------------------------------------------------------------
  Encapsulation                       Data hiding
  ----------------------------------- -----------------------------------
  Bundles data and related operations Restricts direct access to internal
  into a class.                       data or implementation details.

  Focuses on grouping and controlling Focuses on restricting visibility
  interaction.                        and access.

  Achieved through class design and   Commonly achieved using `private`
  access control.                     and `protected` access control.
  -----------------------------------------------------------------------

Data hiding is one important aspect of encapsulation.

------------------------------------------------------------------------

## 8. Encapsulation vs. abstraction

  -----------------------------------------------------------------------
  Encapsulation                       Abstraction
  ----------------------------------- -----------------------------------
  Controls how internal state is      Exposes essential behavior while
  accessed or modified.               hiding unnecessary implementation
                                      details.

  Commonly uses classes, access       Commonly uses clear interfaces,
  specifiers, and controlled methods. abstract classes, and public
                                      operations.

  Example: validating a student's     Example: using `withdraw()` without
  marks in `setMarks()`.              needing to know the internal
                                      banking implementation.
  -----------------------------------------------------------------------

They often work together. A class can use encapsulation to protect its
internal state and abstraction to offer a simple interface.

------------------------------------------------------------------------

## 9. Advantages of encapsulation

1.  **Data protection:** Prevents unrelated outside code from directly
    modifying private members.
2.  **Validation:** Lets the class reject invalid input.
3.  **Consistency:** Helps keep objects in valid states.
4.  **Maintainability:** Internal implementation can change without
    necessarily changing the public interface.
5.  **Controlled access:** The class author chooses which operations are
    available.
6.  **Reduced coupling:** Other code can depend on the public interface
    instead of the internal representation.
7.  **Improved testing:** Rules can be tested through the public
    methods.

### Limitations and considerations

-   Getters and setters do not automatically make a design good.
-   Excessive getters and setters can expose too much of the
    implementation.
-   Encapsulation does not automatically make a program secure against
    every threat.
-   Validation must reflect the actual rules of the application.

------------------------------------------------------------------------

## 10. Common mistakes in C++

### Mistake 1: Making all data members public

``` cpp
class Student {
public:
    int marks;
};
```

**Problem:** Outside code can assign any value directly.

**Improvement:** Make the member private and expose a validated
operation.

### Mistake 2: Assigning before validation

``` cpp
void setMarks(int m) {
    marks = m;

    if (m < 0 || m > 100) {
        cout << "Invalid marks!" << endl;
    }
}
```

**Problem:** Invalid values have already been stored.

**Correct approach:**

``` cpp
void setMarks(int m) {
    if (m >= 0 && m <= 100) {
        marks = m;
    } else {
        cout << "Invalid marks!" << endl;
    }
}
```

### Mistake 3: Forgetting that zero is valid

``` cpp
if (m > 0 && m <= 100)
```

This rejects 0. If the allowed range is 0 through 100, use:

``` cpp
if (m >= 0 && m <= 100)
```

### Mistake 4: Using `continue` outside a loop

`continue` is used to skip to the next iteration of a loop. It cannot be
used as a replacement for `else` inside a normal setter method.

### Mistake 5: Reading an uninitialized built-in data member

``` cpp
class Student {
private:
    int marks;
};
```

If a `Student` object is created without initializing `marks`, reading
it before assigning a valid value can lead to undefined behavior.

Initialize it:

``` cpp
int marks = 0;
```

The initial value should make sense for the class's design. Another
option is to require a valid value through a constructor.

------------------------------------------------------------------------

## 11. Constructor-based initialization

A constructor can initialize an object when it is created.

``` cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    Student(const string& studentName, int studentMarks)
        : name(studentName), marks(studentMarks) {
        if (marks < 0 || marks > 100) {
            marks = 0;
        }
    }

    string getName() const {
        return name;
    }

    int getMarks() const {
        return marks;
    }
};

int main() {
    Student s("Joy", 85);

    cout << s.getName() << endl;
    cout << s.getMarks() << endl;

    return 0;
}
```

Output:

``` text
Joy
85
```

This example demonstrates initialization through a constructor. In
production code, you might prefer to reject invalid constructor
arguments or report an error rather than silently replacing them with 0.

------------------------------------------------------------------------

## 12. Two-mark interview questions and answers

### Q1. What is encapsulation?

Encapsulation is the bundling of data and related methods into a single
unit, such as a class, while controlling access to the data.

### Q2. How is encapsulation implemented in C++?

It is commonly implemented using classes, access specifiers such as
`private` and `public`, and methods that provide controlled access to
data.

### Q3. What is data hiding?

Data hiding is the restriction of direct access to internal data or
implementation details.

### Q4. What is a getter?

A getter is a method that returns a value from an object without
directly exposing the data member.

### Q5. What is a setter?

A setter is a method that updates a data member and may validate the
requested value before changing it.

### Q6. Can private members be accessed directly from `main()`?

No. Private members cannot be accessed directly from unrelated outside
code. Public methods can provide controlled access.

### Q7. Are getters and setters compulsory for encapsulation?

No. They are common techniques, but a class can expose other meaningful
operations instead.

### Q8. What are the benefits of encapsulation?

It supports data hiding, validation, consistency, maintainability, and
reduced coupling.

### Q9. What is the difference between `private` and `protected`?

`private` members are accessible to the class and its friends, while
`protected` members are also accessible to derived classes under C++
access rules.

### Q10. Is encapsulation the same as abstraction?

No. Encapsulation bundles data and operations and controls access.
Abstraction exposes essential behavior while hiding unnecessary
implementation details.

------------------------------------------------------------------------

## 13. Interview-level questions

1.  Why should a class's data members usually be private?
2.  Is a class encapsulated if every private member has a public getter
    and setter? Explain.
3.  How can a setter preserve an object's previous valid state?
4.  What happens if a setter validates data after assigning it?
5.  Why might a getter be declared `const`?
6.  When would you use a constructor instead of setters?
7.  Can encapsulation be achieved without getters?
8.  How does encapsulation reduce coupling?
9.  What is the difference between an invariant and an input validation
    check?
10. How would you design a `BankAccount` class so that callers cannot
    set its balance arbitrarily?

### Suggested answers to remember

-   Private fields prevent direct access from unrelated outside code.
-   A class can still have a poor interface even if its fields are
    private.
-   Validate first, then assign.
-   A `const` getter promises not to modify the object's ordinary state.
-   Constructors are useful when an object must be initialized at
    creation.
-   A class can expose operations such as `deposit()` or `withdraw()`
    without exposing a balance setter.
-   An invariant is a condition that should remain true for every valid
    object state; input validation helps preserve it.

------------------------------------------------------------------------

## 14. Practice tasks

Complete these in order, without looking at a solution first.

### Practice 1: Student class

Create a `Student` class with private `name`, `rollNumber`, and `marks`.

-   Reject empty names.
-   Accept only positive roll numbers.
-   Accept marks from 0 to 100.
-   Add getters and `displayDetails()`.
-   Add `hasPassed()`, returning true for marks of 40 or more.

### Practice 2: Bank account

Create a `BankAccount` class with:

-   Private account holder name and balance.
-   A deposit method that rejects non-positive amounts.
-   A withdrawal method that rejects non-positive amounts and
    withdrawals exceeding the available balance.
-   A public method to read the balance.
-   No public method that allows arbitrary balance assignment.

### Practice 3: Employee salary

Create an `Employee` class with:

-   Private employee ID and salary.
-   A positive employee ID.
-   A non-negative salary.
-   Validated setter methods and getters.
-   A method to display employee details.

### Practice 4: Product inventory

Create a `Product` class with:

-   Private product name, price, and quantity.
-   A non-empty name.
-   A non-negative price and quantity.
-   A method to update stock safely.
-   A method to calculate the total inventory value
    (`price * quantity`).

### Practice 5: Challenge

Design a `PasswordAccount` class that never returns the stored password
through a getter. Instead, provide an operation to check whether a
supplied password matches. For a real application, passwords should be
stored using a suitable password-hashing approach rather than as plain
text.

------------------------------------------------------------------------

## 15. Quick revision

Remember these key points:

-   Encapsulation is one of the four pillars of OOP.
-   It bundles data and related operations into a class.
-   `private` restricts direct access from unrelated outside code.
-   Public methods provide a controlled interface.
-   Setters can validate inputs before modifying data.
-   Getters are useful for read-only access, but are not mandatory.
-   Encapsulation and data hiding are related, not identical.
-   Abstraction focuses on exposing essential behavior and hiding
    unnecessary implementation details.
-   Good encapsulation preserves the rules and valid state of an object.

### One-line interview answer

**Encapsulation in C++ is the OOP principle of combining data and the
methods that operate on it into a class and controlling access to the
internal state using access specifiers and a well-designed public
interface.**
