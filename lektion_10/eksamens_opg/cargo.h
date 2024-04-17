#pragma once

#include<iostream>
#include<vector>

using namespace std;

class Cargo{
private:
    std::string name;
    double weight;
    int daysToDelivery;
public:
    Cargo(std::string n, double w, int d):name(n), weight(w),daysToDelivery(d){
        /* Ensure daysToDelivery is in the interval [1 day, 99 days] */
        if(daysToDelivery<1){
            daysToDelivery = 1;
        }else if(daysToDelivery>100){
            daysToDelivery = 99;
        }

        /* Ensure weight is in the interval ]0kg, 50kg] */
        if(weight<=0){
            weight = 0.001;
        }else if(weight>50){
            weight = 50;
        }
    }

    std::string getName(){
        return name;
    }

    double getWeight(){
        return weight;
    }

    virtual int getDaysToDelivery(){
        return daysToDelivery;
    }
};

