# [Operator Overloading]Matrix Calculation

 ## Description:

Please complete the class Matrix.

Suppose you have understood the overload operator of C++.

```
Matrix(string, int, int, int**)

Matrix(const Matrix &)

~Matrix()

bool operator ==(const Matrix& matOther)

bool operator !=(const Matrix& matOther)

void operator +=(const Matrix& matOther) // addition

void operator -=(const Matrix& matOther) // substraction

Matrix operator *(const Matrix& matOther) // production, return a new Matrix named "newMat"
```

## Note:

If the caculation is invalid, print like the following:

"invalid addition.\n"

"invalid substraction.\n"

"invalid multiplication.\n" and return an empty matrix   
 
*出题人： 林楚庭*