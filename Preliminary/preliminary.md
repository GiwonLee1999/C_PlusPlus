### Literals • 2, 5.75, ‘Z’, "Hello World“
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

### Dynamic variables • Require the use of pointers
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