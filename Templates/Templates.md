# C++ Templates

Templates in C++ are a feature that allows the creation of generic and reusable code. They enable functions and classes to operate with generic types, making code more flexible and reducing redundancy. Templates are especially useful when the same logic can be applied to different data types.

## Types of Templates

### 1. Function Templates
Function templates allow the creation of functions that can operate on different data types without changing their definitions.

**Example: Function Template**

```cpp
#include <iostream>

// Template function to find the maximum of two values
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "Max of 3 and 7: " << getMax(3, 7) << std::endl;
    std::cout << "Max of 3.5 and 2.1: " << getMax(3.5, 2.1) << std::endl;
    std::cout << "Max of 'a' and 'b': " << getMax('a', 'b') << std::endl;
    return 0;
}
```

## Explanation

### Function Templates

- `template <typename T>`: Declares a template with `T` as a placeholder for the data type.
- `T getMax(T a, T b)`: Defines a function `getMax` that can accept any data type `T`.

### Class Templates

Class templates enable the creation of classes that can handle different data types, offering a flexible way to implement data structures.

**Example: Class Template**

```cpp
#include <iostream>

// Template class for a simple Pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

int main() {
    Pair<int, double> p1(3, 7.5);
    std::cout << "Pair: " << p1.getFirst() << ", " << p1.getSecond() << std::endl;

    Pair<std::string, char> p2("Hello", 'A');
    std::cout << "Pair: " << p2.getFirst() << ", " << p2.getSecond() << std::endl;

    return 0;
}
```

## Explanation

### Class Templates

- `template <typename T1, typename T2>`: Declares a template for a class with two types, `T1` and `T2`.
- `Pair(T1 a, T2 b)`: Constructor initializes the members `first` and `second`.

## Key Points

- **Generic Programming**: Templates support generic programming by allowing code to be written independently of specific data types.
- **Code Reusability**: They reduce code duplication by enabling a single function or class to work with various types.
- **Type Safety**: Templates ensure type safety, catching type mismatches at compile time.

## Conclusion

Templates are a cornerstone of C++'s generic programming capability. They allow the creation of flexible and reusable code components, such as algorithms and data structures, that work with any data type. By leveraging templates, developers can write more concise, maintainable, and efficient code.
