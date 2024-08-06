## C++ aggregate data types: array, struct and class
- Array: collection of values of same type
- Struct: collection of values of different types
- Class: conceptually, a structure that can also “contain” functions
- A **struc** or a **class** is a user-defined data type


### stuct
```
struc Rectagle{
    int width;
    int height;
};
```
    - The only difference between class and struct is that the members of a struct are public by default, but private by default for a class.

### class
- A class is an Abstract Data Type, i.e. a data type that defines both the data contained in the data elements it defines, as well as the behavior and/or constraints that applies to elements of this type.
```
// .h file
class DayOfYear{
    public:
        void input();
        void output();
        void set(int newMonth, int newDay);
        int getDay();
    private:
        int month;
        int day;
};

DayOfYear today; // allocated on Stack
DayOfYear *birthday = new DayOfYear(); // allocated on heap

int day1 = today.getDay();
int day2 = *birthday.getDay(); // equivalent
int day3 = birthday->getDay(); // equivalent


// .cpp file
void DayOfYear::input(){
    cout << month << day;
}
void DayOfYear::output(){
    switch(month){
        case 1: cout << 1; break;
        case 2: cout << 2; break;
        case 3: cout << 3; break;
        case 4: cout << 4; break;
        default:
            cout << "Something went wrong" << endl;
    }
}
```
See the example header, cpp file

### inline functions/methods
E.g
```
class A{
public:
    int getMonth(){return month};
}
```
or
```
class A{
    public:
        int getMonth();
};
inline int A::getMonth(){
    return month;
}
- Inline functions have internal linkage. If you want to make an inline function accessible to other compilation units, they must include the definition of the inline function.
- Rule of thumb: Inline your functions that have very short function definitions. Accessor methods are very good candidates for method inlining.
```

### Const Specifier: value cannot be changed after it is set:
- Variable:
    - ```
    const DayOfYear newYearsDay(1,1);
    ```
- Functions parameters: 
    - ```
    int max(const int i1, const int i2){
        return i1 >= i2 ? i1:i2;
    }
    ```
- Methods:
    - ```
    int DayOfYear::getDay() const{ 
        return day; // value cannot be altered;
    }
    ```

### static specifier: Class memner; it belongs to the class as a whole rather than on the objects.
- If a member function is declared as static, it can only use other members that are also declared as static.
- only static const integral data members can be initialized within a class
```
static const in engine = 56; // allowed, static const integral type
```
- non static state members cannot be defined out of class.
- When you declare a variable or function at file scope the static keyword specifies that the variable or function has internal linkage, i.e. it cannot be referred to outside of the compilation unit in which it is declared.
- When you declare a local variable to a function as static, the variable has static duration, i.e. its value is kept even when the execution goes out of the scope of this function. In other words, it is a “global variable that has local scope to this function”.