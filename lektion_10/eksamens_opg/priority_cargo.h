#pragma once

#include "cargo.h"

class PriorityCargo : public Cargo{

public:
    PriorityCargo(std::string n, double w): Cargo(n, w, 99) {}

    int getDaysToDelivery() override{
        return 0;
    }
};
