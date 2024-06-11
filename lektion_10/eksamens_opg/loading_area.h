#pragma once

#include <vector>
#include <algorithm>
#include "cargo.h"
#include "truck.h"

class LoadingArea {
    std::vector<Cargo*> availableCargo;

public:
    std::vector<Cargo*> getAvailableCargo(){
        return availableCargo;
    }

    void addCargo(Cargo &c){
        bool duplicate = 0;
        for(Cargo *ca : availableCargo){ // check all elements
            if(ca->getName() == c.getName()){ // if name matches
                duplicate = 1; // set duplicate flag
            }
        }
        if(!duplicate) availableCargo.push_back(&c); // put in availableCargo is not duplicate
    }

    void removeCargo(std::string s){
        int i = 0; // first pos
        for(Cargo *ca : availableCargo){ // check all elements
            if(ca->getName() == s){ // if name matches
                availableCargo.erase(availableCargo.begin()+i); // remove from availableCargo
            }
            i++; // iterate to next pos
        }
    }

    void loadTruckSimple(Truck &t){
        for(Cargo* ac : availableCargo){
            if(t.remainingCapacity() >= ac->getWeight()){ // if there is capacity
                t.addCargo(*ac); // add cargo to truck
            }
        }

        for(Cargo ct : t.getAllCargo()){ // remove all cargo from available that is on the truck
            removeCargo(ct.getName());
        }
    }

    void loadTruckAdvanced(Truck &t){
        std::vector<Cargo*> temp;
        std::vector<Cargo*> sortedAvailableCargo;

        for(int i = 0; i <= 99; ++i){
            for(Cargo* ac : availableCargo){ // select all available cargo with i priority
                if(ac->getDaysToDelivery() == i){
                    temp.push_back(ac);
                }
                // sort by weight in current priority
                std::sort(temp.begin(), temp.end(), [](Cargo* a, Cargo* b){ // lamda expression as comparison function
                        return a->getWeight() > b->getWeight(); // return true is a weight is bigger than b
                    }
                );
            }
            sortedAvailableCargo.insert(sortedAvailableCargo.end(), temp.begin(), temp.end()); // insert current priority list at the end of sorted list
            temp.clear(); // clear current priority and do next
        }

        for(int i = 0; i < 5; i++){ // run through a couple times to ensure that the truck is filled as much as possible

            for(Cargo* sac : sortedAvailableCargo){ // go through all cargo in the sorted order
                if(t.remainingCapacity() >= sac->getWeight()){ // if there is capacity
                    t.addCargo(*sac); // add cargo to truck
                }
            }

            for(Cargo ct : t.getAllCargo()){ // remove all cargo from sorted available that is on the truck
                int i = 0; // first pos
                for(Cargo *sac : sortedAvailableCargo){ // check all elements
                    if(sac->getName() == ct.getName()){ // if name matches
                        sortedAvailableCargo.erase(sortedAvailableCargo.begin()+i); // erase
                    }else{
                    i++; // iterate to next pos
                    }
                };
            }
        }

        for(Cargo ct : t.getAllCargo()){ // remove all cargo from available that is on the truck
            removeCargo(ct.getName());
        }
    }
};
