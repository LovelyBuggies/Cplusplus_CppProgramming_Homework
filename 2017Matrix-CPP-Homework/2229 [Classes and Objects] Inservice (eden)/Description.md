# [Classes and Objects] Inservice (eden)

Please complete the following 4 classes: **Person, Student, Worker, Inservice**.

Note:

1. Person owns data member name and sex, the output format is (For more detail, see the **sample output**):
	```
	// you should add this ouput statement in the constructor
	cout << "Construct Person" << endl;
	// you should add this ouput statement in the destructor
	cout << "Destruct Person" << endl;
	```

2. Student is a derived class of Person, its data member is a string sno(学号), its constructor has to print "Construct Student" and its destructor has to print "Destruct Student"

3. Worker is a derived class of Person, its data member is a string wno(职员号), its constructor has to print "Construct Worker" and its destructor has to print "Destruct Worker"

4. Please think the **relationship between InService and Student/Worker**, and implement InService class by yourself. with its constructor prints "Construct InService" and its destructor prints "Destruct InService"

## Sample Input
```
amblpo
1
13154671
10814061

```
## Sample Output
```
Construct Person
Construct Student
Construct Worker
Construct InService
amblpo
1
amblpo
1
13154671
amblpo
1
10814061
Destruct InService
Destruct Worker
Destruct Student
Destruct Person
```

## Hints
虚继承