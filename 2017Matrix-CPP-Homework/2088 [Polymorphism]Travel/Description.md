# [Polymorphism]Travel

We all know TA LSC is rich and he loves to traveling all over the world. There are three kinds of vehicles —— bicycle, train, and airplane to choose from. As a Tourist, he wants to know how long he should spend to travel from city to city when he chooses a vehicle strategy above.

BicycleStrategy, TrainStrategy and AirplaneStrategy iherits from Vehicle Class. void doTravel(...) function will print the time spent (refer to the sample output). 
When choosing BicycleStrategy, the distance between two citys (x1, y1)、(x2, y2) is defined as Manhattan Distance: dis = |x1-x2|+|y1-y2|;
When choosing TrainStrategy, the distance between two citys (x1, y1)、(x2, y2) is defined as Euclidean distance: dis = sqrt((x1-x2)^2+(y1-y2)^2);
When choosing AirplaneStrategy, the distance between two citys (x1, y1)、(x2, y2) is defined as Chebyshev distance: dis = max(|x2-x1|,|y2-y1|);

The Tourist Class would choose a strategy and void travel() function would print the time spent according to the strategy.

The City struct, Vehicle class and Tourist have been given to you. Please implements City, Vehicle, BicycleStrategy, TrainStrategy and AirplaneStrategy in "vehicle.h", and implements Tourist Class in "tourist.h"
```
struct City {
    double x, y;          // position of the city
    std::string name;  // name of city
};

class Vehicle {
 public:
    explicit Vehicle(double _speed) : speed(_speed) {}
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const {
        return speed;
    }
    virtual ~Vehicle() {}

 private:
    double speed;
};

class Tourist {
 public:


    explicit Tourist(Vehicle* strategy_);

    void setStrategy(Vehicle* strategy_);

    void travel(const City& src, const City& dest);

 private:
    Vehicle* strategy;
};
```
================================================

Sample Test:
```

City src = {0.0, 0.0, std::string("Beijing")};

City dest = {2.0, 2.0, std::string("Guangzhou")};

BicycleStrategy bicycle(15); 
TrainStrategy train(120);
AirplaneStrategy air(500); 

Tourist lsc(&bicycle);
lsc.travel(src, dest);

lsc.setStrategy(&train);
lsc.travel(src, dest);

lsc.setStrategy(&air);
lsc.travel(src, dest);
```

## Sample Output:
```
It takes 0.266667 hours to Travel from Beijing to Guangzhou by Bicycle.
It takes 0.0235702 hours to Travel from Beijing to Guangzhou by Train.
It takes 0.004 hours to Travel from Beijing to Guangzhou by Airplane.
```
## Hint
Polymorphism,  Strategy.

Source Author: *陈雄涛*