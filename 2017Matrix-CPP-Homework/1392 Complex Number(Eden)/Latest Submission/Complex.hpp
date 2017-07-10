#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

class Complex
{
 public:
  Complex(int a=0,int b=0);
  void printComplex();
  Complex add(Complex );
  Complex subtract(Complex );
  void setComplexNumber(int, int );
 private:
  int realPart;
  int imaginaryPart;
};

#endif