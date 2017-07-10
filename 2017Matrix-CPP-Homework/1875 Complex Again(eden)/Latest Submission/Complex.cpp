#include "Complex.hpp"
   
Complex operator+(const Complex& u, const Complex& v) { return Complex(u.real + v.real, u.imag + v.imag); }

Complex operator-(const Complex& u, const Complex& v) { return Complex(u.real - v.real, u.imag - v.imag); }

Complex operator*(const Complex& u, const Complex& v) { return Complex(u.real * v.real - u.imag * v.imag, u.real * v.imag + u.imag * v.real); }

Complex operator/(const Complex& u,const Complex& v) {
  double s = v.real * v.real + v.imag * v.imag;
  return Complex((u.real * v.real + u.imag * v.imag) / s, (u.imag * v.real - u.real * v.imag) / s); 
}
  
Complex& Complex::operator+=(const Complex& plus) {
    *this = *this + plus;
    return *this;
}

Complex& Complex::operator-=(const Complex& minus) {
    *this = *this - minus;
    return *this;
}

Complex& Complex::operator*=(const Complex& multi) {
    *this = *this * multi;
    return *this;
}

Complex& Complex::operator/=(const Complex& div) {
    *this = *this / div;
    return *this;
}

bool Complex::operator==(const Complex& compare) {
    return (compare.real==real && compare.imag==imag)? true : false; }

bool Complex::operator!=(const Complex& compare) {
  return (*this == compare)? false : true;
}
