#include <iostream>

// Function template to find the maximum of two values
template <typename T>
T getMax(T a, T b)                                                                                  {
    return (a > b) ? a : b                                                                          ;}

int main()                                                                                          {
    std::cout << "Max of 3 and 7: " << getMax(3, 7) << std::endl                                    ;
    std::cout << "Max of 3.5 and 2.1: " << getMax(3.5, 2.1) << std::endl                            ;
    std::cout << "Max of 'a' and 'b': " << getMax('a', 'b') << std::endl                            ;
    return 0                                                                                        ;}

// Explanation:

// template <typename T>: Declares a template. T is a placeholder for the data type.
// T getMax(T a, T b): Defines a function getMax that can accept any data type T.


// ---- ---- ---- ---- ----- ----- ----- Line Break ----- ---- ----- ----- ----- ---- ----- 
#include <iostream>

// Class template for a simple Pair
template <typename T1, typename T2>
class Pair                                                                                          {
private:
    T1 first                                                                                        ;
    T2 second                                                                                       ;
public:
    Pair(T1 a, T2 b) : first(a), second(b)                                                         {}
    T1 getFirst() const { return first;                                                             }
    T2 getSecond() const { return second;                                                           }};

int main()                                                                                          {
    Pair<int, double> p1(3, 7.5)                                                                    ;
    std::cout << "Pair: " << p1.getFirst() << ", " << p1.getSecond() << std::endl                   ;

    Pair<std::string, char> p2("Hello", 'A')                                                        ;
    std::cout << "Pair: " << p2.getFirst() << ", " << p2.getSecond() << std::endl                   ;

    return 0                                                                                        ;}


// Explanation:

// template <typename T1, typename T2>: Declares a template for a class with two types, T1 and T2.
// Pair(T1 a, T2 b): Constructor initializes the members first and second.