## Operating Overloading

- To implement a custom arithmetic-style operations which is more convenient.

### Examples can be found in the **Operator_overloading.cpp** file.

```
const Rational Rational::add(const Rational& r) const{
    int n = numerator * r.denominator + denominator * r.numerator;
    int d = denominator * r.denominator;
    return Rational(n,d);
}

Rational a(5,6);
Rational b(2,3);
Rational c(1,2);
Rational d = a.add(b.add(c));
```
- 'add' is the custom operator
- Param, is referenced to keep the existing memory block.
- Const after the param to signify that the operation does not alter the calling **object**.


### Opeartors that cannot be overloaded:
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
- combination of some operators, etc ...


