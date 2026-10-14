# Observer Pattern

## Overview

The **Observer Pattern** is a behavioral design pattern that defines a one-to-many dependency between objects so that when one object (subject) changes state, all its dependents (observers) are notified and updated automatically.

> **Core Idea:** Define a subscription mechanism to notify multiple objects about any events that happen to the object they're observing.

---

## Problem It Solves

| Without Observer | With Observer |
|------------------|---------------|
| Tight coupling between subject and observers | Loose coupling via abstraction |
| Subject must know concrete observer classes | Subject only knows observer interface |
| Hard to add/remove observers at runtime | Dynamic subscription/unsubscription |
| Violates Single Responsibility Principle | Separates notification logic from business logic |
| Polling required for updates | Push-based notifications |

---

## Structure

```
┌─────────────────┐
│    Subject      │ ◄──── Maintains list of observers
│  (Interface)    │
└─────────────────┘
        ▲
        │ implements
┌─────────────────┐
│ ConcreteSubject │ ◄──── State changes trigger notifications
│   (Publisher)   │
└─────────────────┘
        │
        │ notifies
        ▼
┌─────────────────┐
│   Observer      │ ◄──── Interface for all observers
│  (Interface)    │
└─────────────────┘
        ▲           ▲           ▲
        │           │           │
    ┌───┴───┐   ┌───┴───┐   ┌───┴───┐
    ▼       ▼   ▼       ▼   ▼       ▼
┌────────┐ ┌────────┐ ┌────────┐ ┌────────┐
│Concrete│ │Concrete│ │Concrete│ │Concrete│
│Observer│ │Observer│ │Observer│ │Observer│
│   A    │ │   B    │ │   C    │ │   D    │
└────────┘ └────────┘ └────────┘ └────────┘
```

---

## Key Components

| Component | Role |
|-----------|------|
| **Subject** | Interface for attaching/detaching/notifying observers |
| **ConcreteSubject** | Maintains state, notifies observers on change |
| **Observer** | Interface defining update method |
| **ConcreteObserver** | Implements update, maintains reference to subject |

---

## When to Use

- One object's changes require updating multiple other objects
- Number of observers varies dynamically
- Subject shouldn't know concrete observer classes
- Need to broadcast events to multiple listeners
- Implementing event-driven architectures

---

## Implementation Example: Stock Market

### 1. Observer Interface
```cpp
// IObserver.hpp
#pragma once
#include <string>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::string& symbol, double price) = 0;
};
```

### 2. Subject Interface
```cpp
// ISubject.hpp
#pragma once
#include "IObserver.hpp"
#include <vector>
#include <memory>

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
};
```

### 3. Concrete Subject
```cpp
// Stock.hpp
#pragma once
#include "ISubject.hpp"
#include "IObserver.hpp"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Stock : public ISubject {
    std::string symbol;
    double price;
    std::vector<std::shared_ptr<IObserver>> observers;
    
public:
    explicit Stock(const std::string& sym, double initialPrice)
        : symbol(sym), price(initialPrice) {}
    
    void attach(std::shared_ptr<IObserver> observer) override {
        observers.push_back(observer);
    }
    
    void detach(std::shared_ptr<IObserver> observer) override {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
    
    void notify() override {
        for (auto& observer : observers) {
            observer->update(symbol, price);
        }
    }
    
    void setPrice(double newPrice) {
        price = newPrice;
        notify();  // Automatic notification on change
    }
    
    double getPrice() const { return price; }
    const std::string& getSymbol() const { return symbol; }
};
```

### 4. Concrete Observers
```cpp
// MobileApp.hpp
#pragma once
#include "IObserver.hpp"
#include <iostream>
#include <string>

class MobileApp : public IObserver {
    std::string appName;
public:
    explicit MobileApp(const std::string& name) : appName(name) {}
    
    void update(const std::string& symbol, double price) override {
        std::cout << "[Mobile App: " << appName << "] "
                  << symbol << " price updated: $" << price << std::endl;
    }
};
```

```cpp
// WebDashboard.hpp
#pragma once
#include "IObserver.hpp"
#include <iostream>
#include <string>

class WebDashboard : public IObserver {
    std::string dashboardName;
public:
    explicit WebDashboard(const std::string& name) : dashboardName(name) {}
    
    void update(const std::string& symbol, double price) override {
        std::cout << "[Web Dashboard: " << dashboardName << "] "
                  << "Real-time update: " << symbol << " = $" << price << std::endl;
    }
};
```

```cpp
// AlertSystem.hpp
#pragma once
#include "IObserver.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

class AlertSystem : public IObserver {
    std::unordered_map<std::string, double> thresholds;
public:
    void setThreshold(const std::string& symbol, double threshold) {
        thresholds[symbol] = threshold;
    }
    
    void update(const std::string& symbol, double price) override {
        auto it = thresholds.find(symbol);
        if (it != thresholds.end() && price >= it->second) {
            std::cout << "[ALERT] " << symbol << " hit $" << price 
                      << " (threshold: $" << it->second << ")" << std::endl;
        }
    }
};
```

```cpp
// Logger.hpp
#pragma once
#include "IObserver.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

class Logger : public IObserver {
    std::ofstream logFile;
public:
    explicit Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);
    }
    
    ~Logger() { if (logFile.is_open()) logFile.close(); }
    
    void update(const std::string& symbol, double price) override {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        
        logFile << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
                << " | " << symbol << " | $" << price << std::endl;
        
        std::cout << "[Logger] Recorded: " << symbol << " = $" << price << std::endl;
    }
};
```

### 5. Client Usage
```cpp
// main.cpp
#include <iostream>
#include <memory>
#include "Stock.hpp"
#include "MobileApp.hpp"
#include "WebDashboard.hpp"
#include "AlertSystem.hpp"
#include "Logger.hpp"

int main() {
    // Create subject (stock)
    auto appleStock = std::make_shared<Stock>("AAPL", 150.00);
    auto googleStock = std::make_shared<Stock>("GOOGL", 2800.00);
    
    // Create observers
    auto mobileApp = std::make_shared<MobileApp>("InvestorApp");
    auto webDashboard = std::make_shared<WebDashboard>("TradingView");
    auto alertSystem = std::make_shared<AlertSystem>();
    auto logger = std::make_shared<Logger>("stock_log.txt");
    
    // Configure alert thresholds
    alertSystem->setThreshold("AAPL", 155.00);
    alertSystem->setThreshold("GOOGL", 2850.00);
    
    // Subscribe observers to stocks
    appleStock->attach(mobileApp);
    appleStock->attach(webDashboard);
    appleStock->attach(alertSystem);
    appleStock->attach(logger);
    
    googleStock->attach(mobileApp);
    googleStock->attach(alertSystem);
    googleStock->attach(logger);
    
    std::cout << "=== Stock Price Updates ===" << std::endl;
    
    // Price changes trigger automatic notifications
    appleStock->setPrice(152.50);
    appleStock->setPrice(155.75);  // Triggers alert!
    appleStock->setPrice(153.20);
    
    std::cout << "\n---" << std::endl;
    
    googleStock->setPrice(2820.00);
    googleStock->setPrice(2855.00);  // Triggers alert!
    
    // Unsubscribe
    std::cout << "\n--- Unsubscribing Mobile App ---" << std::endl;
    appleStock->detach(mobileApp);
    appleStock->setPrice(156.00);  // Mobile app won't receive this
    
    return 0;
}
```

---

## Alternative: Modern C++ with std::function

```cpp
// EventEmitter.hpp - Lightweight observer using std::function
#pragma once
#include <functional>
#include <vector>
#include <string>
#include <algorithm>

template<typename... Args>
class EventEmitter {
    using Callback = std::function<void(Args...)>;
    std::vector<Callback> callbacks;
    
public:
    // Subscribe - returns token for unsubscribing
    size_t subscribe(Callback cb) {
        callbacks.push_back(cb);
        return callbacks.size() - 1;
    }
    
    // Unsubscribe by token
    void unsubscribe(size_t token) {
        if (token < callbacks.size()) {
            callbacks[token] = nullptr;
        }
    }
    
    // Notify all subscribers
    void emit(Args... args) {
        for (auto& cb : callbacks) {
            if (cb) cb(args...);
        }
    }
};

// Usage
EventEmitter<std::string, double> stockEvents;

auto token1 = stockEvents.subscribe([](const std::string& sym, double price) {
    std::cout << "Observer 1: " << sym << " = $" << price << std::endl;
});

auto token2 = stockEvents.subscribe([](const std::string& sym, double price) {
    std::cout << "Observer 2: " << sym << " = $" << price << std::endl;
});

stockEvents.emit("AAPL", 150.00);
stockEvents.unsubscribe(token1);
stockEvents.emit("GOOGL", 2800.00);  // Only observer 2 receives
```

---

## Push vs Pull Models

| Model | Description | Pros | Cons |
|-------|-------------|------|------|
| **Push** | Subject sends data to observers | Simple, less coupling | Observers may receive unwanted data |
| **Pull** | Observers query subject for data | Observers control what they need | More coupling, observers need subject reference |

```cpp
// Pull model example
class PullObserver {
public:
    virtual void update(ISubject* subject) = 0;  // Observer pulls data
};

class PullSubject {
    std::vector<PullObserver*> observers;
public:
    void notify() {
        for (auto obs : observers) {
            obs->update(this);  // Pass self for pulling
        }
    }
};
```

---

## Real-World Examples

| Domain | Subject | Observers |
|--------|---------|-----------|
| **GUI** | Button, TextField | Click handlers, validation, logging |
| **MVC** | Model | Views, Controllers |
| **Event Systems** | EventEmitter | Event listeners |
| **Stock Market** | Stock | Traders, dashboards, alerts |
| **Social Media** | User | Followers, notifications |
| **File System** | Directory | Watchers, indexers |
| **Game Engine** | Entity | Systems (render, physics, AI) |

---

## Benefits

| Benefit | Description |
|---------|-------------|
| **Loose Coupling** | Subject knows only Observer interface |
| **Open-Closed Principle** | Add new observers without modifying subject |
| **Dynamic Relationships** | Subscribe/unsubscribe at runtime |
| **Broadcast Communication** | One-to-many notification |
| **Separation of Concerns** | Subject manages state, observers handle reactions |

---

## Drawbacks

| Drawback | Mitigation |
|----------|------------|
| **Unexpected Updates** | Observers may not expect frequency — document behavior |
| **Memory Leaks** | Forgotten detach — use weak_ptr or auto-unsubscribe |
| **Performance** | Many observers + frequent updates = overhead — batch notifications |
| **Order Dependency** | Notification order may matter — document or use priority |
| **Circular References** | Subject ↔ Observer — use weak_ptr for back-references |

---

## Observer vs Other Patterns

| Pattern | Purpose | Key Difference |
|---------|---------|----------------|
| **Observer** | One-to-many notification | Focus: *state change propagation* |
| **Mediator** | Centralized communication | Focus: *reducing direct connections* |
| **Pub/Sub** | Message-based decoupling | Focus: *asynchronous, topic-based* |
| **Event Bus** | Global event distribution | Focus: *application-wide events* |
| **Callback** | Single notification | Focus: *one-to-one, synchronous* |

---

## Key Takeaways

| Principle | Application |
|-----------|-------------|
| **Encapsulate What Varies** | Notification logic in subject, reaction logic in observers |
| **Program to Interface** | Subject depends on Observer abstraction |
| **Loose Coupling** | Subject doesn't know concrete observers |
| **Dynamic Binding** | Observers attached/detached at runtime |

---

## Summary

> **Observer Pattern in one sentence:** *Define a subscription mechanism where a subject automatically notifies multiple observers of state changes — like a newspaper publisher notifying subscribers of new editions.*