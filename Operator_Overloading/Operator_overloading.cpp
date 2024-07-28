class Rational{
    public: 
        Rational(int = 0, int = 1 ); // default constructor
        Rational(const Rational & r); // copy constructor
        int numerator;
        int denominator;
}

// Addtion of two Rational objects
const Rational Rational::add(const Rational& r) const{
    int n = numerator * r.denominator + denominator * r.numerator;
    int d = denominator * r.denominator;
    return Rational(n,d);
}

Rational a(5,6);
Rational b(2,3);
Rational c(1,2);
Rational d = a.add(b.add(c));

// Addtion of two Rational objects
const Rational Rational::+(const Rational& r) const{
    int n = numerator * r.denominator + denominator * r.numerator;
    int d = denominator * r.denominator;
    return Rational(n,d);
}

Rational d = a + b + c;

Opeartors that cannot be overloaded:
- +
- -
- *
- /
- %
- ^
- &
- &&
- =
- <
 etc


// Stream input/output operators overloading
ostream& operator<<(ostream &output, const Rational &r){
    output << r.numerator << "/" << r.denominator;
    return output;
}

// Input
istream& operator<<(istream &input, const Rational &r){
    input >> r.numerator >> r.denominator;
    return input;
}

cout << ++a << endl << b++ << endl << b << endl;

// Casting operator:
Rational::operator double(){
    return numerator / (double)denominator;
}
Rational b(2,3);
double f = b;
