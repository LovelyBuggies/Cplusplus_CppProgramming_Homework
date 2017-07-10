#ifndef COMPLEX_H
#define COMPLEX_H

/* Write class definition for Complex */
class Complex {
    public:
        Complex(double = 0.0, double = 0.0);  // default constructor
        Complex add(const Complex &);  // function add
        Complex subtract(const Complex &);  // function subtract
        void printComplex();  // print complex number format
        void setComplexNumber(double, double);  // set complex number
    private:
        double realPart;
        double imaginaryPart;
};
#endif