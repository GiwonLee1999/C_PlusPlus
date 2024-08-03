### Literals - 2, 5.75, ‘Z’, "Hello World“
- Considered "constants": can’t change in program
- All literals have an inherent type that can be determined during lexical analysis
- Like many other languages, C++ uses escape sequences for string literals:
- \n new line
- \r carriage return
- \t tab
- \' single quote

### Variable declartion:
- int x;
- double y;
- myClass mc;
- int x,y,z;

#### Declarations can include an optional initialization, which can use
- different syntactical forms:
- Type a1 {v};
- Type a2 = {v};
- Type a3 = v;
- Type a4(v);

### Type mismatches:
```
int var = 2.90; // 2 is assigned to var
```
### Cast:
```
doubleVar = static_cast<double>(intVar1)/intVar2;
const_cast<Type>
dynamic_cast<Type> // Runtime checked conversion of pointers and references within a single class hierarchy.
reinterpret_cast<Type>
```
## Pointers
- A pointer variable contains the memory address of a portion of memory that in turn contains a specific value.

```
int i = 1;
int* p = &i; // p refers to memory address of i variable
cout << *p << endl;
```

### Dynamic variables - Require the use of pointers
- Allocated with **new operator**, deallocated with the delete operator
- Need to be allocated and destroyed explicitly while program runs
- C++ does not have a **garbage collector**
- The operator new creates dynamically allocated values that can then be pointed to by pointer variables
- Allocated on the heap through the runtime system's interaction with the operating system.
```
int* p1, p2;
p1 = new int; // Allocated on the heap, freestore
```
- Constructor can be invoked with pointers.

Potential problem if heap runs out of memory.
```
// Test if null returned by call to new:
int *p;
p = new int;
if (p == NULL){
    cout << "Error: Insufficient memory.\n";
    exit(1);
}

// You can do this:
try { 
    int * myarray= new int[1000]; 
} 
    catch (bad_alloc&) { 
    cout << "Error allocating memory." << endl; 
}
```
### Use **Delete** operator to deallocate dynamic memory.
```
int *p;
p = new int(5);
... // some work
delete p; // Deallocation
p = NULL; // Must set P to NULL, otherwise is **dangling pointer** - still points to its previously allocated value.
```
Dangling pointer can potentially create a **memory leak**.

### Pointer arithmetic:
You can perform artihmetic operations on pointers.
```
int *d;
d = new int[10];
// d refers to address of new int[10];
d + 1 refers to: addres of new int[10] + 1*sizeof(int)
```

### pointers and const
```
int x;
int * p1 = &x; // non-const pointer to non-const int
const int * p2 = &x; // non-const pointer to const int
int * const p3 = &x; // const pointer to non-const int
const int * const p4 = &x; // const pointer to const int
```

### void pointer: a pointer that is allowed to be pointing to a value of any type
- void* data;
### wild pointer: a pointer that points to an arbitrary memory location.
- int* x;
### null pointer: a pointer that points nowhere
- int* x = nullptr;


## References:
### Pointers are very powerful, as they allow:
- A variable to refer a value held by another variable.
- A variable to refer to different values held by different variables in time.
- Pass information around without having to copy it.
### However, due to their power, pointers bring additional complexities:
- Must use a special syntax (*, &, ->)
- Possibility of dangling pointers, wild pointers, null pointers.
- Pointers are unsafe, as their use may easily result in undefined behavior.

### Smart pointers: Reduce bugs, Retain similar efficiency and syntax
```
template <class T> class auto_ptr {
T* ptr;
public:
explicit auto_ptr(T* p = 0) : ptr(p) {}
~auto_ptr() {delete ptr;}
T& operator*() {return *ptr;}
T* operator->() {return ptr;}
};

void foo(){
auto_ptr<MyClass> p(new MyClass);
p->DoSomething();
} 
// Delete p automatically;
```
- Good for danling pointer where two same pointers pointing at the same address space.


### Parameters can be passed to a function:
- By value
    - A copy of the value is made, then the copied value is passed to the function.
    - For objects, the copy constructor is called by the runtime system to make the copy.
    - Thus, the value used in the function is local to the function.
    - Changing it in the function does not change the value passed from the calling function.
    - Pass by value cannot accept a parameter that is an expression.
- By pointer
    - A copy of the pointer value is made, then passed to the function.
    - Thus, both functions are pointing to the same value; no copy of the value pointed to is made.
    - Changing the pointed value in the called function will change the value in the calling function.
- By reference
    - Conceptually same as pass by pointer, except that the called function cannot change where the received pointer is pointing.
    - Drawback: cannot pass NULL , as a reference cannot be NULL
    - Advantage: can accept unnamed values resulting from the evaluation of expressions as parameters: void f(const T& t); called as f(T(a, b, c)), or f(a+b)
    - Call by constant reference is very often used to save memory consumption to pass parameters that are not to be changed locally.

```
class C {
public:
C() {cout << "C::C();" << endl;};
C(int) { cout << "C::C(int);" << endl; };
C(C&) { cout << "C::C(C);" << endl; }
};

int main() {
cout << "= = = = = = = = = = = = = = = = =" << endl;
C c;
cout << "= = = = = = = = = = = = = = = = =" << endl;
cout << "address where c is stored : " << &c << endl;

cout << "passing by value" << endl;
pass_by_value(c);
cout << "passing by reference" << endl;
pass_by_reference(c);
cout << "passing by pointer" << endl;
pass_by_pointer(&c);

cout << "passing/returning by value" << endl;
c = pass_and_return_by_value(c);
cout << "passing/returning by reference" << endl;
c = pass_and_return_by_reference(c);
cout << "passing/returning by pointer" << endl;
c = *pass_and_return_by_pointer(&c);

return 0;
}

void pass_by_value(C val_c) {
cout << "= = = = = = = = = = = = = = = = =" << endl;
cout << "= pass_by_value " << endl;
cout << "= address where val_c is stored: " << &val_c << endl << endl;
cout << "= = = = = = = = = = = = = = = = =" << endl;
}

void pass_by_reference(C& ref_c) {
cout << "= = = = = = = = = = = = = = = = =" << endl;
cout << "= pass_by_reference " << endl;
cout << "= address of object that ref_c refers to: " << &ref_c << endl << endl;
cout << "= = = = = = = = = = = = = = = = =" << endl;
}

void pass_by_pointer(C* ptr_c) {
cout << "= = = = = = = = = = = = = = = = =" << endl;
cout << "= pass_by_pointer " << endl;
cout << "= address of object pointed to by ptr_c: " << ptr_c << endl << endl;
cout << "= = = = = = = = = = = = = = = = =" << endl;
}

```