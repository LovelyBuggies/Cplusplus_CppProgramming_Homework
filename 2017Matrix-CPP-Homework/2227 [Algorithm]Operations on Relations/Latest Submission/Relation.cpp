//
//  Relation.hpp
//  C++
//
//  Created by 刘硕 on 16/3/24.
//  Copyright © 2017Y Nino. All rights reserved.
//

#include "Relation.hpp"
    
Relation::Relation(BooleanMatrix const &temp) : matrix(temp) {}

BooleanMatrix Relation::getBooleanMatrix() const
{
  return matrix;
}

// Operations on Relations
Relation Relation::complementary() const
{
  BooleanMatrix temp(this->matrix);
  bool b;
  int r=temp.getRow();
  int c=temp.getColums();
  for(int i=1;i<=r;i++)
    for(int k=1;k<=c;k++){
      b=temp.replace(1-temp.getElement(i,k),i,k);
  }
  Relation re(temp);
  return re;
}
Relation Relation::inverse() const
{
  int c=matrix.getRow();
  int r=matrix.getColums();
  BooleanMatrix temp(r,c);
  for(int i=1;i<=r;i++)
    for(int k=1;k<=c;k++){
      temp.replace(matrix.getElement(k,i),i,k);
    }
    Relation re(temp);
    return re;
}
Relation Relation::operator&(const Relation &temp)
{
  BooleanMatrix parameter(matrix);
  parameter=matrix &(temp.matrix);
  Relation t(parameter);
  return t;
}
Relation Relation::operator|(const Relation &temp)
{
  BooleanMatrix parameter(this->matrix);
  parameter=matrix |temp.matrix;
  Relation t(parameter);
  return t;
}