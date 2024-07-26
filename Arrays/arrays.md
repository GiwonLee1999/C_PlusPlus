# Arrays in C++

## Array: A collection of data elements of the same type

### Types of Arrays

- **Statically allocated**: Fixed size, residing on the stack.
- **Dynamically allocated**: Size can be changed, using pointers to arrays residing on the heap.
- **STL array class**

## Static Array

### Arrays are stored as a block of memory: Managed using pointers

```size of
int score2[4] = {1, 2, 3, 4}; 
cout << sizeof(score2) / sizeof(int) << endl; // Output: 4
```
### Array as parameters:

- Address of array
- Array base type
- Size of array

eg: 
```
int myfunc(int p[])
```
pointer to p is passed as value, functions cannot return static arrays in the same way simple types are returned.

- **Pointer** is required, is much fore efficient
- Without it, the arrays are copied as they are passed around and manipulated, leading to increased memory consumption and execution time.

### Multidimensional static arrays:

``` 
char page[30][100]
```
- The elements of a dimensional array are stored as a contiguous memory block.
```
// multidimensional arrays:
    int table[height][width] = {1,2,3,45,6,77,4,32,1,2,3,3};

    // using indexes
    for(int i = 0 ; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << table[i][j]<<' ';
        }
    }
    cout<<endl;

    //using array to pointer decay
    for(int i = 0;i < height*width; i++){
        cout << *(*(table+0)+i) <<' ';
    }
```
- Watch how pointers work, **(table+i)+j** i refers to rows, j refers to columns

### Dynamic arrays: Can grow and shrink as needed
- Use new operator with a pointer
```
double *d = new double[10]; 
delete [] d; // deallocates all memory
d = NULL; // Set to null to avoid dangling pointer problems. Still points to that memory block.
```
- Stored using the same model as a static array, except that the arrays of elements is stored on the heap instead of the stack
- Each need to be pointed to by a pointer.

Dynamically allocated array of integers:
```
int** a = new int*[3];

for (int i = 0 ; i < 3; i ++)
    a[i] = new int[4];

// Delete
for (int i = 0 ; i < 3; i ++)
    delete [] a[i]
delete [] a;
```
- Array **a** is stored as a stack, but its elements are stored in heap (grow, shrink).
- Requires an additional pointer

### Static array classes:
```
#include <array>

int main(){
    std::array<int,3> arr{1,2,3};~
}
```

## STL Containers: Vector, less error-prone than basic arrays

### Features:
- Bounds checking
- Embed memory allocation/deallocation mechanisms
- STL containers allows automatic resizing of the container if necessary

### Cons:
- Additional data
- More computation time
- Higher access time

### e.g

```
#include <vector>

int main(){
    // single row
    std::vector<int> vec;
    for (int i = 0 ; i < 13; i ++) vec.push_back(i);
    for(std::vector<int>::iterator it = vec.begin() ; it !=vec.end(); ++it)
        std::cout << '' << *it;

    // multidimensional vector:
    std::vector< vector<int> > vec;
    for (int i = 0 ; i < 13; i ++) {
        vector<int> row;
        for (int j = 0; j < 20; j++){
            row.push_back(i*j);
        }
        vec.push_back(row);
    }
```

Use:
at()
front()
back()
size()
capacity()
max_size()

Modifiers:
insert()
erase()
push_back(),push_front()
pop_back(),pop_front()
clear()
swap()


}


