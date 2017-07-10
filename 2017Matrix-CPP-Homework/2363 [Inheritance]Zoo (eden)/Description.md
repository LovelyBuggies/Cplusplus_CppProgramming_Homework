# [Inheritance]Zoo (eden)

# Description
TA LSC loves keeping animals like Cat and Dog in his own Zoo. 
Class Cat and Dog inherit from Animal Class. Each animal has a name field and an age field. When void Shout() function is called, Cat will print "name: meow~~" while Dog will print "name: bark!!". The Zoo Class is a collection of animals with some operations. LSC can

1. add a new animal to the zoo;

2. remove animals by name;

3. remove animals by age;

4. get the count of cats or dogs in the zoo

5. print all the animals' shouting (print in the order they were added).

refer to main.cpp for all these operations.

 

An enum Type and Class Animal has been given as follow:
```
enum Type {
    CAT,
    DOG
};

class Animal {
 public:
    Animal(std::string _name, int _age) : name(_name), age(_age) {}
    virtual void Shout() const = 0;
    virtual Type getType() const = 0;
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

 private:
    std::string name;
    int age;
};
```
Please implements Cat Class and Dog Class in "animal.h" (The enum Type and Class Animal should also be copied to this file).
Please Design an Zoo Class in "zoo.h" and "zoo.cpp" to meet the above requirements.

Pay Attention:
1. Different animals could have the same name or age.
2. When adding animals, an animal should be added only once!
3. When deleting animals by name, all animals with the specified name should be deleted. The same to deleting by age.


## Sample Test
```
Dog a1("d1", 1);
Dog a2("d2", 1);
Cat a3("c", 2);

Zoo zoo;
zoo.addAnimal(&a1);
zoo.addAnimal(&a2);
zoo.addAnimal(&a2);
zoo.addAnimal(&a3);

std::cout << zoo.getCatCount() << std::endl;
std::cout << zoo.getDogCount() << std::endl;

zoo.deleteAnimalByName("d1");
zoo.deleteAnimalByAge(1);

std::cout << zoo.getCatCount() << std::endl;
std::cout << zoo.getDogCount() << std::endl;

zoo.addAnimal(&a1);
zoo.print();
```

## Sample Output
```
1
2
1
0
c: meow~~
d1: bark!!
```

## Hint
Inheritance and Container,  you can use vector<Animal*> in your zoo class. 

Some of you may haven't used vector yet. Please baidu or google about it.

Also refer to `http://www.cplusplus.com/reference/vector/vector/?kw=vector`

## Further Learning:

To store and manage pointers of Base Class better, you could learn about Handle Class(句柄类).

**Source Author: 陈雄涛（TA）**
