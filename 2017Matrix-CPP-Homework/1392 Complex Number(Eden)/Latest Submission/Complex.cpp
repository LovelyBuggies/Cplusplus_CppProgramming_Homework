#include <iostream>
#include "Complex.hpp"

using namespace std;

Complex::Complex(int a,int b) : realPart(a), imaginaryPart(b) {}

void Complex::printComplex()
{
  cout << "(" << realPart << ", " << imaginaryPart << ")";
}

Complex Complex::add(Complex b)
{
  Complex c;
  c.realPart = realPart+b.realPart;
  c.imaginaryPart = imaginaryPart+b.imaginaryPart;
  return c;
}

Complex Complex::subtract(Complex b)
{
  Complex c;
  c.realPart = realPart-b.realPart;
  c.imaginaryPart = imaginaryPart-b.imaginaryPart;
  return c;
}

void Complex::setComplexNumber(int a, int b)
{
  realPart = a;
  imaginaryPart = b;
}