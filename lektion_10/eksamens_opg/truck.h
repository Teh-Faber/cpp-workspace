#pragma once

#include <vector>
#include "cargo.h"

class Truck{
    double capacity;
    std::vector<Cargo> allCargo;

public:
    Truck(double c): capacity(c) {}

    void addCargo(Cargo c){
        allCargo.push_back(c);
    }

    std::vector<Cargo> getAllCargo(){
        return allCargo;
    }

    double remainingCapacity(){
        double usedCap = 0;
        for(Cargo c : allCargo){ // sum all weights of all Cargo
            usedCap += c.getWeight();
        }
        // remaining capacity is total capacity - used capacity
        return capacity - usedCap;
    }
};
