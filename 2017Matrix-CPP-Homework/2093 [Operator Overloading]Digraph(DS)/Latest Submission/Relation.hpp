 //
//  Relation.hpp
//  C++
//
//  Created by Nino on 16/4/8.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef Relation_hpp
#define Relation_hpp

#include "Set.hpp"
#include "Matrix.hpp"
#include "BooleanMatrix.hpp"
#include "ProductSet.hpp"
#include "Relation.hpp"

class Relation :public BooleanMatrix{
public:
	Relation(const BooleanMatrix &temp) ;
	//constructor
};

#endif