


string whichToFail;

class MyClass {
    public:
        string name;
        MyClass(const string newName) : name(newName) {
        cout << "in MyClass constructor: " << name << endl;
    };
        ~MyClass() {
        cout << "In MyClass destructor: " << name << endl;
    }
}
void g() {
    // to be deleted first during stack unwinding
    // including parameters passed as value
    MyClass mc4("mc4");
    if (whichToFail == "g") throw std::exception();
    MyClass mc5("mc5");
}
void f() {
    // to be deleted second during stack unwinding
    // including parameters passed as value
    MyClass mc2("mc2");
    if (whichToFail == "f") throw std::exception();
    g();
    MyClass mc3("mc3");
}
int main() {
    cin >> whichToFail;
    // not to be deleted during stack unwinding
    MyClass mc1("mc1");
    try {
    // to be deleted third during stack unwinding
    MyClass mc6("mc6");
    if (whichToFail == "main") throw std::exception();
    f();
    MyClass mc7("mc7");
    }catch (...) {
    MyClass mc8("mc8");
    }
    // resume here after handling the exception
    MyClass mc9("mc9");
}

// Example: 
Constructor C
Destructor D
// When the exception is thrown -> catch, stack unwiding
input: g
C 1
C 6
C 2
C 4
D 4
D 2
D 6
C 8
D 8
C 9
D 9
D 1