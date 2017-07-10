#ifndef  VEHICLE_H
#define VEHICLE_H


#include <cmath>
#include <iostream>
using namespace std;


struct City {
    double x, y;          // position of the city
    std::string name;  // name of city
};


class Vehicle {
 public:
    explicit Vehicle(double _speed) : speed(_speed) {}
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const 
    {
        return speed;
    }
    virtual ~Vehicle() {}
    double speed;
};



class BicycleStrategy :public Vehicle
{
 public:
    explicit BicycleStrategy(double _speed) : Vehicle(_speed) {}
    virtual void doTravel(const City& src, const City& dest) 
    {
    	double distance;
    	distance=fabs(src.x-dest.x)+ fabs(src.y-dest.y);
         cout<<"It takes "<<distance/speed<<" hours to Travel from "<<src.name<<" to "<<dest.name<<" by Bicycle."<<endl;
    }
    double getSpeed() const 
    {
    double temp=Vehicle::getSpeed();
    return temp;
    }
    virtual ~BicycleStrategy() {}

 };


class TrainStrategy :public Vehicle
{
 public:
    explicit TrainStrategy(double _speed) : Vehicle(_speed) {}
    virtual void doTravel(const City& src, const City& dest) 
    {
    	double distance;
        distance= sqrt(pow((src.x-dest.x),2)+pow((src.y-dest.y),2)); 
         cout<<"It takes "<<distance/speed<<" hours to Travel from "<<src.name<<" to "<<dest.name<<" by Train."<<endl;
    }
    double getSpeed() const 
    {
    double temp=Vehicle::getSpeed();
    return temp;
    }
    virtual ~TrainStrategy() {}

 };



class AirplaneStrategy :public Vehicle
{
 public:
    explicit AirplaneStrategy(double _speed) : Vehicle(_speed) {}
    virtual void doTravel(const City& src, const City& dest) 
    {
    	double distance;
        if(fabs(src.x-dest.x)>fabs(src.y-dest.y)) 
        	distance=fabs(src.x-dest.x);
        else distance=fabs(src.y-dest.y);
         cout<<"It takes "<<distance/speed<<" hours to Travel from "<<src.name<<" to "<<dest.name<<" by Airplane."<<endl;
    }
    double getSpeed() const 
    {
    double temp=Vehicle::getSpeed();
    return temp;
    }
    virtual ~AirplaneStrategy() {}

 };

 #endif