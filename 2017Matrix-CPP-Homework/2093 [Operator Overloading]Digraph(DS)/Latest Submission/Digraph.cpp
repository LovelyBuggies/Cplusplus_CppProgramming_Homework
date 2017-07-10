#include <stdio.h>
#include "BooleanMatrix.hpp"
#include "Set.hpp"
#include "ProductSet.hpp"
#include "Relation.hpp"
#include "Digraph.hpp"


    int Digraph::getSetElePos(int ele)
    {
    for (int i = 0; i < set.getSize(); i++) {
        if (set.getMembers()[i] == ele) {
            return i;
        }
    }
    return (-1);
    }
    //return the element position in the set property

    Digraph::Digraph(BooleanMatrix const &m, Set const &s) : Relation(m)
    {
        set=s;
    }

    int Digraph::inDegree(int num)
    {
        int p=-1;
        for(int i=1;i<=set.getSize();i++)
            if(num==set.get(i)) p=i;
        if(p==-1) return p;
        int in_degree=0;
        for(int i = 1; i <= (this->getRow()); i++) 
            if(matrix[ELEMENT_POS(i, p)] == 1) 
                in_degree++;
        return in_degree;
    }
    int Digraph::outDegree(int num)
    {
        int p=-1;
        for(int i=1;i<=set.getSize();i++)
            if(num==set.get(i)) p=i;
        if(p==-1) return p;
        int out_degree=0;
        for(int i = 1; i <= (this->getColums()); i++) 
            if(matrix[ELEMENT_POS(p,i)] == 1) 
                out_degree++;
        return out_degree;
    }
    
    Digraph Digraph::pathOfLength(int len)
    {
    	int count=1;
        BooleanMatrix m(*this);
    	while(count<len)
    	{
            m=BooleanProduct(m);
            count++;
    	}
        Digraph temp(m,set);
    	return temp;
        //it is not available to return the bottom class
    }
    
    // Properties of Relations.    
    bool Digraph::isReflexive() const
    {
    	bool r=true;
        for(int i = 1; i <= (this->getRow()); i++)
        if(matrix[ELEMENT_POS(i,i)] == 0)
        r=false;
        return r;
    }

    bool Digraph::isIrreflexive() const
    {
        bool r=true;
        for(int i = 1; i <= (this->getRow()); i++)
        if(matrix[ELEMENT_POS(i,i)] == 1)
        r=false;
        return r;
    }

    bool Digraph::isSymmetric() const
    {
    	bool r=true;
    	for(int i = 1; i <= (this->getRow()); i++)
        for(int j = 1; j <= (this->getColums()); j++)
        if(matrix[ELEMENT_POS(i,j)] != matrix[ELEMENT_POS(j,i)])
    		r=false;
    	return r;
    }

    bool Digraph::isAsymmetric() const
    {
    	bool r=true;
        for(int i = 1; i <= (this->getRow()); i++)
        	for(int j=1; j <= (this->getColums()); j++)
                if(matrix[ELEMENT_POS(i,j)]+ matrix[ELEMENT_POS(j,i)]== 2)
                r=false;
        return r;
    }

    bool Digraph::isAntisymmetric() const
    {
    	bool r=true;
        for(int i = 1; i <= (this->getRow()); i++)
        	for(int j=1; j <= (this->getColums()); j++)
                if(i!=j)
                if(matrix[ELEMENT_POS(i,j)]+ matrix[ELEMENT_POS(j,i)]== 2)
                r=false;
        return r;   	
    }
    
    bool Digraph::isTransitive() const
    {
    	bool r=true;
         for(int i = 1; i <= (this->getRow()); i++)
        	for(int j=1; j <= (this->getColums()); j++)
        		for(int k = 1; k <= (this->getRow()); k++)
                  if(matrix[ELEMENT_POS(i,k)]+matrix[ELEMENT_POS(k,j)]==2)
                  	if(matrix[ELEMENT_POS(i,j)]==0)
                  		r=false;
        return r;
    } 
    
    BooleanMatrix Digraph::getBooleanMatrix() const
    {
        BooleanMatrix temp(*this);
    	return temp;
    }
