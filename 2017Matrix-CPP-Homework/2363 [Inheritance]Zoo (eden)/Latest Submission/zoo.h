//
//zoo.h
//C++
//
//Created by Nino on 17/04/21
//Copyright ©Nino 2017. All right reserved.
//

#ifndef _ZOO_H_
#define _ZOO_H_

#include "animal.h"
#include <vector>
#include <iterator>
using namespace std;

class Zoo {
private:
//two list to represent animals
//for abstract class cannot have instance
    std::vector<Cat> cv;
    std::vector<Dog> dv;
    int num_cat;
    int num_dog;
public:
	Zoo() ;
	~Zoo() ;
	void addAnimal(Animal* add) ;
	int getDogCount() ;
	int getCatCount() ;
	void deleteAnimalByName(string _name) ;
    void deleteAnimalByAge(int _age) ;
	void print();
};

#endif