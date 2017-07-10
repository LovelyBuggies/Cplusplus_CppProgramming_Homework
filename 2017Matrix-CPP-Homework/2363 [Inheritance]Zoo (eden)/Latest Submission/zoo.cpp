#include "zoo.h"

Zoo::Zoo() {
	num_cat = 0;
	num_dog = 0;
}

Zoo::~Zoo() {
	cv.clear();
  dv.clear();
	num_dog = 0;
	num_cat = 0;
}

void Zoo::addAnimal(Animal* add) {
    if(add->getType() == CAT){
        Cat lovelycat(add->getName(), add->getAge());
        cv.push_back(lovelycat);
    		num_cat++;
    }
    if(add->getType() == DOG){
        Dog lovelydog(add->getName(), add->getAge());
        dv.push_back(lovelydog);
    		num_dog++;
    }
}

int Zoo::getDogCount() { return num_dog; }

int Zoo::getCatCount() { return num_cat; }

void Zoo::deleteAnimalByName(string _name) {
    for(auto cat_it_pos = cv.begin(); cat_it_pos != cv.end(); cat_it_pos++) {
    	if(cat_it_pos->getName() == _name){
    				cv.erase(cat_it_pos);
            num_cat--;
            cat_it_pos--;
        }
    }
    for(auto dog_it_pos = dv.begin(); dog_it_pos != dv.end(); dog_it_pos++) {
        if(dog_it_pos->getName() == _name){
            dv.erase(dog_it_pos);
            num_dog--;
            dog_it_pos--;
        }
    }
}

void Zoo::deleteAnimalByAge(int _age) {
    for(auto cat_it_pos = cv.begin(); cat_it_pos != cv.end(); cat_it_pos++) {
        if(cat_it_pos->getAge() == _age){
            cv.erase(cat_it_pos);
            cat_it_pos--;
            num_cat--;
        }
    }
    for(auto dog_it_pos = dv.begin(); dog_it_pos != dv.end(); dog_it_pos++) {
        if(dog_it_pos->getAge() == _age){
            dv.erase(dog_it_pos);
            num_dog--;
            dog_it_pos--;
        }
    }
}

void Zoo::print(){
    if(dv.size() == 0 && cv.size() == 0) return ;
    for(auto dog_it_pos = dv.begin(); dog_it_pos != dv.end(); dog_it_pos++)
        dog_it_pos->Shout();
    for(auto cat_it_pos = cv.begin(); cat_it_pos != cv.end(); cat_it_pos++)
        cat_it_pos->Shout();

}

//
//private:
//std::vector<Dog> dv;
//std::vector<Cat> cv;
//int num_cat;
//int num_dog;
//