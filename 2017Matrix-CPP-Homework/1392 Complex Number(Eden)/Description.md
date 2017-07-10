# Complex Number(Eden)

#### Create a class called Complex for performing arithmetic with complex numbers.
#### Complex numbers have the form
        realPart + imaginaryPart * i
            where i is √-1
### Use double variables to represent the private data of the class. Provide a constructor that enables an object of this class to be initialized when it is declared. The constructor should contain default values in case no initializers are provided. 
### Provide public member functions that perform the following tasks:
*    a) Adding two Complex numbers: The real parts are added together and the imaginary parts are added together.

*    b) Subtracting two Complex numbers: The real part of the right operand is subtracted from the real part of
        the left operand and the imaginary part of the right operand is subtracted from the imaginary part of the left operand.
*    c) Printing Complex numbers in the form (a, b) where a is the real part and b is the imaginary part.




### Hint:
```
Complex::Complex( double real, double imaginary ) {
 setComplexNumber( real, imaginary );
 } // end Complex constructor

Complex Complex::add( const Complex &right ) {
 /* Write a statement to return a Complex object. Add
  the realPart of right to the realPart of this Complex
  object and add the imaginaryPart of right to the
  imaginaryPart of this Complex object */
} // end function add

Complex Complex::subtract( const Complex &right ) {
 /* Write a statement to return a Complex object. Subtract
  the realPart of right from the realPart of this Complex
  object and subtract the imaginaryPart of right from
  the imaginaryPart of this Complex object */
} // end function subtract

void Complex::printComplex() {
 cout << '(' << realPart << ", " << imaginaryPart << ')';
} // end function printComplex

void Complex::setComplexNumber( double rp, double ip ) {
 realPart = rp;
 imaginaryPart = ip;
} // end function setComplexNumber
```
### Sample input:
```
1 2 3 4 5 6 7 8
```
### Sample output:
```
(1, 2) + (3, 4) = (4, 6)
(5, 6) - (7, 8) = (-2, -2)
```
 

 *Source Author：马桂洪*

 