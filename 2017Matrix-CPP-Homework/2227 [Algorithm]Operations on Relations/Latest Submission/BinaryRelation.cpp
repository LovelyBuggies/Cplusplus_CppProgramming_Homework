//
//  BinaryRelation.hpp
//  C++
//
//  Created by liushuo on 16/3/24.
//  Copyright © 2017 Nino. All rights reserved.
//

#include "BinaryRelation.hpp"

int BinaryRelation::getSetElePos(int ele){
   for (int i = 0; i < set.getSize(); i++) {
    if (set.getMembers()[i] == ele) {
      return i;
      }
    }
    return (-1);
}
     
BinaryRelation::BinaryRelation(BooleanMatrix const &m, Set const &s) : Relation(m){
  set=s;
}
    
int BinaryRelation::inDegree(int num)
{
    int p=-1;
    for(int i=1;i<=set.getSize();i++)
      if(num==set.get(i)) p=i;
      if(p==-1) return p;
    int in_degree=0;
    for(int i = 1; i <= (matrix.getRow()); i++) 
      if(matrix.getElement(i,p) == 1) 
        in_degree++;
    return in_degree;
}
    
int BinaryRelation::outDegree(int num){
    int p=-1;
    for(int i=1;i<=set.getSize();i++){
      if(num==set.get(i)) p=i;
    }
  if(p==-1) return p;
  int out_degree=0;
  for(int j=1;j<=(matrix.getColums());j++){
    if(matrix.getElement(p,j) ==1) out_degree++;
  }
  return out_degree;
}
    
BinaryRelation BinaryRelation::pathOfLength(int len){
  int count=1;
  BooleanMatrix m(this->matrix);
  while(count<len)
  {
    m=m.BooleanProduct(m);
   count++;
  }
  BinaryRelation temp(m,set);
  return temp;
}

    
// Properties of Relations.    
bool BinaryRelation::isReflexive() const{
  for(int i = 1; i <= (matrix.getRow()); i++)
  if(matrix.getElement(i,i) == 0)
  return false;
  return true;
}
    
bool BinaryRelation::isIrreflexive() const{
  for(int i=1;i<=matrix.getColums();i++){
    if(matrix.getElement(i,i) ==1)
      return false;
  }
  return true;
}
    
bool BinaryRelation::isSymmetric() const{
  for(int i = 1; i <= (matrix.getRow()); i++)
  for(int j = 1; j <= (matrix.getColums()); j++)
  if(matrix.getElement(i,j) != matrix.getElement(j,i) )
  return false;
  return true;
}
    
bool BinaryRelation::isAsymmetric() const{
  for(int i = 1; i <= (matrix.getRow()); i++)
  for(int j=1; j <= (matrix.getColums()); j++)
  if(matrix.getElement(i,j) +matrix.getElement(j,i) ==2)
  return false;
  return true;
}
    
bool BinaryRelation::isAntisymmetric() const{
  for(int i = 1; i <= (matrix.getRow()); i++)
  for(int j=1; j <= (matrix.getColums()); j++)
  if(i!=j)
  if(matrix.getElement(i,j) +matrix.getElement(j,i) ==2)
  return false;
  return true; 
}
    
bool BinaryRelation::isTransitive() const{
    for(int i = 1; i <= (matrix.getRow()); i++)
    for(int j=1; j <= (matrix.getColums()); j++)
    for(int k = 1; k <= (matrix.getRow()); k++)
    if(matrix.getElement(i,k)+matrix.getElement(k,j)==2)
    if(matrix.getElement(i,j)==0)
    return false;
    return true;
}

    
bool BinaryRelation::isEquivalence() const{
  bool r=false;
  if(isSymmetric()&&isReflexive()&&isTransitive()) r=true;
  return r;
}
    
    
BinaryRelation BinaryRelation::composition(const BinaryRelation &other){
  BooleanMatrix m(this->matrix);
  m=m.BooleanProduct(other.matrix);
  BinaryRelation temp(m,set);
  return temp;
}

    
BinaryRelation BinaryRelation::reflexiveClosure() const{
  BooleanMatrix m(matrix);
  int n=matrix.getRow();
  BooleanMatrix temp(n,n);
  for (int i = 1; i <= n*n; i++) {
    temp.replace(1,i,i);
    }
  m=m|temp;
  BinaryRelation t(m,set);
  return t;
}
    
BinaryRelation BinaryRelation::symmetricClosure() const{
  BooleanMatrix m(matrix);
  m=m|m.transpose();
  BinaryRelation temp(m,set);
  return temp;
}
    
BinaryRelation BinaryRelation::transitiveClosure() const{
  BooleanMatrix m(matrix);
  int n=matrix.getRow();
  for(int times=1;times<=n;times++){
    int r[n],c[n];
    int ccount=0,rcount=0;
    for(int i=1;i<=n;i++)
      if(m.getElement(i,times)==1){
        c[ccount]=i;
        ccount++;
      }
    for(int j=1;j<=n;j++)
      if(m.getElement(times,j)==1){
        r[rcount]=j;
        rcount++;
      }
    for(int i=0;i<ccount;i++){
    for(int j=0;j<rcount;j++){
      m.replace(1,c[i],r[j]);
    }
    }
  }
  BinaryRelation temp(m,set);
  return temp;
}