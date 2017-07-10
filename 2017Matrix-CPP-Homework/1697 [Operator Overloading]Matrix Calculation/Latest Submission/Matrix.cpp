#include "Matrix.h"
#include <iostream>
using namespace std;

//constructor
Matrix::Matrix(string n, int h, int w, int**p)
 {
   name=n;
   height=h;
   width=w;
   param=new int* [height];
   for(int i=0;i<height;i++)
   {
   param[i]=new int [width];
   for (int j = 0; j < width; j++) 
   param[i][j]=p[i][j];
   }
 }

//copy constructor
Matrix::Matrix(const Matrix &source)
{
  name=source.name;
  height=source.height;
  width=source.width;
  param=new int*[height];
  for(int i=0;i<height;i++)
  {
   param[i]=new int [width];
   for(int j=0;j<width;j++)
   param[i][j]=source.param[i][j];
  }
}

//destructor
Matrix::~Matrix()
{
  for(int i=0;i<height;i++)
     delete [] param[i];
  delete [] param;
}

//operator overloading
bool Matrix::operator ==(const Matrix&source)
{
  bool equal=true;
  for(int i=0;i<height;i++)
  for(int j=0;j<width;j++)
  if(param[i][j]!=source.param[i][j])
  {
   equal=false;
   break;
  }
  return equal;
}

bool Matrix::operator !=(const Matrix&source)
{
  bool notequal=false;
  for(int i=0;i<height;i++)
  for(int j=0;j<width;j++)
  if(param[i][j]!=source.param[i][j])
  {
   notequal=true;
   break;
  }
  return notequal;
}
        
void Matrix::operator +=(const Matrix&source)
{
  if((height==source.height)&&(width==source.width))
  {
  for(int i=0;i<height;i++)
  for(int j=0;j<width;j++)
  param[i][j]=param[i][j]+source.param[i][j];
  }
  else
  cout << "invalid addition." << endl;
}
        
void Matrix::operator -=(const Matrix&source)
{
  if((height==source.height)&&(width==source.width))
  {
  for(int i=0;i<height;i++)
  for(int j=0;j<width;j++)
  param[i][j]=param[i][j]-source.param[i][j];
  }
  else
  cout << "invalid substraction." << endl;
}
        
Matrix Matrix::operator *(const Matrix&source)
{
  Matrix matPro;
  string str="newMat";
  matPro.name=str;
  matPro.height=height;
  matPro.width=source.width;
  matPro.param=new int* [height];
  for(int i=0;i<height;i++)
  {
   matPro.param[i]=new int [width];
   for (int j = 0; j < width; j++) 
   matPro.param[i][j]=0;
   }
  if(width==source.height)
  {
  for(int i=0;i<height;i++)
  for(int k=0;k<source.width;k++)
  for(int j=0;j<width;j++)
  matPro.param[i][k]+=param[i][j]*(source.param[j][k]);
  }
  else {
  cout << "invalid multiplication." << endl;
    Matrix temp;
    return temp;
  }
  return matPro;
}