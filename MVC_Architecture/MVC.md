## Model:

### Manages the behavior and data of the application domain

## View:

### Renders the model into a form for visualization or interaction. UI

## Controller:

### Receives user input and initiates a response by making calls on appropriate model objects.


Overall:

- The model objects are created.
- The views register as observers on the model objects.
- The controller is bound to a view.
- THe controller is given a reference to the underlying model.


# Abstract Class and Interface Class in C++

## Abstract Class

An abstract class in C++ is a class that cannot be **instantiated** on its own and is meant to be subclassed. It can have both pure virtual methods (without implementation) and regular methods (with implementation).

### Characteristics:
- Cannot be instantiated directly.
- Can have both pure virtual methods and regular methods.
- Can have member variables.
- Can have constructors.
- Subclasses must implement all pure virtual methods of the abstract class.

### Example in C++:
```
#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual method
    void sleep() { // Regular method
        std::cout << "Sleeping" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark" << std::endl;
    }
};

int main() {
    Dog dog;
    dog.makeSound();  // Output: Bark
    dog.sleep();      // Output: Sleeping
    return 0;
}
```



# Interface Class

An interface class defines a contract that other classes must follow. It only contains method declarations without any implementation. All methods in an interface are abstract by default. Interfaces are used to specify what methods a class should implement without dictating how these methods should be implemented. This ensures that different classes can provide different implementations of the same set of methods.

## Characteristics:
- Cannot be **instantiated** directly.
- Cannot have any concrete methods; all methods are abstract.
- Cannot have member variables (in some languages like Java; other languages may vary).
- Multiple interfaces can be implemented by a single class, providing a way to achieve multiple inheritance (or similar behavior).

## Example in Java:
```
#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual method
    virtual void sleep() = 0;     // Pure virtual method
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark" << std::endl;
    }
    void sleep() override {
        std::cout << "Sleeping" << std::endl;
    }
};

int main() {
    Dog dog;
    dog.makeSound();  // Output: Bark
    dog.sleep();      // Output: Sleeping
    return 0;
}
```