//
//header for StarCraft
//C++
//Created by Nino on 17/04/21
//Copyright © Nino 2017. All rights reserved.
//

#include <iostream>

using namespace std;

class coordinate {
public:
	int x;
	int y;
};

class gameobject {
public:
    coordinate position;
    coordinate speed;
    int hp;
	
  gameobject(int x, int y) {
		position.x = x;
		position.y = y;
		hp = 10;
		speed.x = 0;
		speed.y = 0;
	}
	
  int get_hp(){ return hp; }
	
  virtual void select() = 0;
	
  virtual void move() { }
	
  virtual void attack(gameobject *injury) = 0;
	
  virtual void build(int h) = 0;
	
  virtual void repair(gameobject *recovery) = 0;
};



class worker : public gameobject {
public:
	worker(int x, int y) : gameobject(x,y) {
		speed.x = 1;
		speed.y = 1;
	}
  
	virtual void select() {
		cout << "Scv good to go, sir!" << endl;
	}
  
	virtual void move() {
		position.x += speed.x;
		position.y += speed.y;
		cout << "Worker moves to (" << position.x;
		cout << ", " << position.y << ")" << endl;
	}
  
	virtual void attack(gameobject *injury) { }
  
	virtual void repair(gameobject *recovery) { recovery->hp = 10; }
	
  virtual void build(int h) {
		for(int r = 1; r <= h; r++){
			for(int space = 0; space < h-r; space++)
				cout << " ";
			for(int star = 0; star < 2*r-1 ; star++)
				cout << "*";
            cout << endl;
		}
	}
};



class zealot : public gameobject {
public:
	zealot(int x, int y) : gameobject(x,y) {
		speed.x = 2;
		speed.y = 2;
	}
  
	virtual void select() {
		cout << "My life for Aiur!" << endl;
	}
  
	virtual void move() {
		position.x += speed.x;
		position.y += speed.y;
		cout << "Zealot moves to (" << position.x;
		cout << ", " << position.y << ")" << endl;
	}
  
	virtual void attack(gameobject *injury) {
		injury->hp--;
	}
  
	virtual void repair(gameobject *recovery) { }
  
	virtual void build(int h) { }
};



class tower : public gameobject {
public:
	tower(int x, int y) : gameobject(x,y) { }
  
	virtual void select() {
		cout << "~" << endl;
	}
  
	virtual void move() {
		cout << "Tower cannot move." << endl;
	}
  
	virtual void attack(gameobject *injury) {
		injury->hp--;
	}
  
	virtual void repair(gameobject *recovery) { }
  
	virtual void build(int h) { }
};