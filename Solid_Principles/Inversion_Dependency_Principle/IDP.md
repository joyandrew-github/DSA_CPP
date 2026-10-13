1. What is ISP?
Definition: Clients should not be forced to depend on interfaces they do not use.
In simple words, don't force a class to implement methods that it doesn't need.
Imagine an interface that contains five methods, but a particular class needs only two. That class shouldn't be forced to implement the remaining three methods with empty bodies or unnecessary exceptions.
Instead, split the large interface into smaller, focused interfaces.