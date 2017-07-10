# Complex Again(eden)

**I know you have learned operator overloading. Your task is to finish this easy class Complex according to the function main.**
```
class Complex {

      //A friend function to print Complex numbers like a+bi where a is the real part and b is the imaginary part
      
public:
   Complex(double = 0.0, double = 0.0);
   
   //Some function about operator overloading.

   void SetReal(double re){real = re;}
   void SetImag(double im){imag = im;}
private:
   double real; 
   double imag; 
};
```
### tip:
* You should first enter the real part and then the imaginary part.
* That is , cin >> x1 >> y1; Complex C(x1,y1);  x1 is the real part and y1 is the imaginary part.

### Sample Input
 ```
 1 1 1 1 1 1 
 ```
 ### Sample Output
 ```
 1+1i

1+1i

1+1i

2+2i

0
2i

1
2+2i

1+1i

2i

1+1i

1
0

 ```

*Source Author : 黄嘉敏*