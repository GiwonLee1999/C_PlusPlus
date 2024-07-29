## Exception Handling:

- To prevent unforeseen circumstances that are outside of its specifications.

```
try{
    
}catch (Exception e){
    
}

throw value;

// Unlike Java, C++ can use any value as an exception, and classes used to instantiate exceptions do not need to be subclasses of the standard exception class.
throw new ExceptionClassName(PossibleArguments);

// Catch block has at most one parameter
catch(Exception e) {
ExceptionHandlingCode
}
```

### Its possible to have multiple catch blocks.

```
int main() {
 … piece of code 1
 calls f1
 … piece of code 2
}
void f1() {
 … piece of code 3
 try {
 … piece of code 4
 calls f2
 … piece of code 5
 }
 catch (int e) {
 … piece of code 6
 }
 … piece of code 7
}
void f2() {
… piece of code 8
if (condition1)
 throw 1 (or calls a function that throws an exception)
 … piece of code 9
if (condition2)
 throw “oops” (or calls a function that throws an exception)
… piece of code 10
}
```

### Exception handling: standard exceptions
- std::exception Parent class of all the standard C++ exceptions.
- std::bad_alloc Thrown by new if out of memory.
- std::bad_cast Thrown by dynamic_cast if target of cast outside of hierarchy of parameter.
- std::bad_exception To handle unexpected exceptions.
- std::bad_typeid Thrown by typeid if parameter is NULL.
- std::logic_error A logical error is detected, i.e. errors that can be detected at compile time.
- std::domain_error A call is made with values outside of acceptable range.
- std::invalid_argument Invalid arguments used (when “range” is not applicable.
- std::length_error The size limit of an object have been exceeded e.g. vector’s max_size
- std::out_of_range An indexed container is used out of range of its valid index range, e.g. the at method of std::vector
- std::runtime_error A runtime error is detected, i.e. errors that can only be detected at runtime.
- std::overflow_error Numeric type overflow was calculated.
- std::range_error A value out of range was calculated
- std::underflow_error Numeric type overflow was calculated

## Why Exception ?

- The exception handling mechanism has a very minimal performance cost if no exception is thrown.
- If an exception is thrown, the cost of the stack unwinding is roughly comparable to the cost of the normal function call/resolution mechanism.
- The cost of searching for the appropriate catch is what is the most costly when an exception is thrown.