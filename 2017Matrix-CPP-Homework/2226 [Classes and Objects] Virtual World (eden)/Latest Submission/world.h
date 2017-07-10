//
// world.h
// C++
//
// Created by Nino on 2017/07/05.
// Copyright © Nino 2017. All rights reserved.
// 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



typedef struct person
{
  static int ID;
  int id;
  std::vector<int> friends;

  person();
  person(int i);
  person(const person& src);
  ~person();
  bool operator==(const person& src);
} person;

int person::ID = 0;

person::person() { id = ID++; }

person::person(int i) : id(i) { }

person::person(const person& src) { 
  id = src.id;
  friends = src.friends;
}

person::~person() { friends.clear(); }

bool person::operator==(const person& src) { return src.id == this->id ? true : false; }





class group 
{
public:
  //constructor
  group(bool a) : acq(a) { }

  //destructor
  ~group() { members.clear(); }

  //display format
  void displayGroup(){
    for(person &each : members) {
      cout << "Person_" << each.id << ":";
      if(each.friends.empty()) cout << " null";
      for(int &ami : each.friends) {
        cout << " " << ami;
        if(ami != *(each.friends.end() - 1)) 
          cout << ",";
      }
      cout << endl;
    }
  }

  bool addMember(person &p) {
    auto it = find(members.begin(), members.end(), p);
    if(it != members.end())
      return false;
    person fresh(p);
    members.push_back(fresh);
    if(acq == 1)
      for(person &each : members)
        makeFriend(each, fresh);
    return true;
  }

  bool deleteMember(person &p){
    auto it = find(members.begin(), members.end(), p);
    if(it == members.end())
      return false;
    members.erase(it);
    return true;
  }

  bool makeFriend(person &p1, person &p2) {
    if(p1 == p2) return false;
    auto it1 = find(members.begin(), members.end(), p1);
    auto it2 = find(members.begin(), members.end(), p2);
    if(it1 == members.end() || it2 == members.end())
      return false;
    auto it = find(it1->friends.begin(), it1->friends.end(), it2->id);
    if(it != it1->friends.end())
      return false;
    it1->friends.push_back(it2->id);
    it2->friends.push_back(it1->id);
    return true;
  }

  bool breakRelation(person &p1, person &p2) {
    if(p1 == p2) return false;
    auto it1 = find(members.begin(), members.end(), p1);
    auto it2 = find(members.begin(), members.end(), p2);
    if(it1 == members.end() || it2 == members.end())
      return false;
    auto it_fri = find(it1->friends.begin(), it1->friends.end(), it2->id);
    if(it_fri == it1->friends.end())
      return false;
    it1->friends.erase(it_fri);
    it_fri = find(it2->friends.begin(), it2->friends.end(), it1->id);
    it2->friends.erase(it_fri);
    return true;
  }

private:
  bool acq;
  std::vector<person> members;
};