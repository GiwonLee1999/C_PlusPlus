### Polymorphism 
- Associating different meanings to one function across an inheritance graph.

### Virtual
- Use virtual functions to achieve polymorphism
- Use pure virtual functions to create abstract classes. 
- Virtual methods allow to declare functions whose runtime behavior uses such a subtype-specific behavior.

E.g:
```
- CSHAPE
    - virtual double getArea() = 0
Inherits:
- Circle
    - double getArea(){}
- Triangle
    - double getArea(){}
- Square
    - double getArea(){}
```

### Object Slicing
- Object Slicing occurs when a derived class object is assigned to a base class object.
- Derived Class Object contains more data and methods than the Base Class Object.
- Base Class Object can only hold the data and methods of the base class, losing the derived class's additional data and methods.
- Slicing happens when you assign a derived class object to a base class variable, resulting in the loss of the derived class's unique features.
- Object Slicing can be avoided by using pointers or references to the base class when dealing with derived class objects.
- Virtual Functions help mitigate the issues caused by slicing by ensuring the correct method is called for the derived class.

### value semantics & reference semantic
- Value semantics: actual objects are manipulated, passed, accessed, copied.
- Reference semantics: references/pointers to objects are manipulated, passed, accessed, copied.

### function pointers
- Function pointers are pointers, i.e. variables that point to an address.
- They point to the starting address of a function’s code.
- Enables the call to different functions, depending on the function pointer value, which can be pointing to different functions’ code in time.