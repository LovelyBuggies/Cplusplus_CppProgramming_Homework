 #ifndef _COMPLEX_
#define _COMPLEX_
#include <iostream>
using namespace std;

class Complex {

public:
   Complex(double r= 0.0, double i= 0.0){real=r;imag=i;}
  //A friend function to print Complex numbers like a+bi where a is the real part and b is the imaginary part
  friend ostream& operator<<(ostream& output,const Complex& c) 
   {   
  if(c.real==0&&c.imag==0) output<<0;
  else if(c.real==0)  output <<c.imag<<"i"<<endl;
  else if(c.imag==0)  output <<c.real;
  else if(c.imag<0)  output <<c.real<<"-"<<-c.imag<<"i"<<endl;
  else  output <<c.real<<"+"<<c.imag<<"i"<<endl;
  return output;
   }
  
   //Some function about operator overloading.
  friend Complex operator+(const Complex&,const Complex&) ;
  friend Complex operator-(const Complex&,const Complex&) ;
  friend Complex operator*(const Complex&,const Complex&) ;
  friend Complex operator/(const Complex&,const Complex&) ;
  
   Complex& operator+=(const Complex&);
   Complex& operator-=(const Complex&);
   Complex& operator*=(const Complex&);
   Complex& operator/=(const Complex&);
   bool operator==(const Complex&);
   bool operator!=(const Complex&);
  
   void SetReal(double re){real = re;}
   void SetImag(double im){imag = im;}
private:
   double real; 
   double imag; 
};

#endif