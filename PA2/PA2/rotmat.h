#pragma once

#include <iostream>
#include <cmath>
#include "matrix.h"

using namespace std;

class RotMat2D : public Matrix{
    double _angle;

public:
    RotMat2D():Matrix(2,2,0),_angle(0){ // set values to identity
        set(0,0,1);
        set(1,1,1);
    }

    RotMat2D(double angle):Matrix(2,2,0),_angle(angle){ // set values according to rotation matrix
        set(0, 0, cos(_angle));
        set(0, 1, -sin(_angle));
        set(1, 0, sin(_angle));
        set(1, 1, cos(_angle));
    }

    virtual void print() override{ // print angle with matrix
        cout << "Rotation angle: " << _angle*(180.0/M_PI) << " degrees" << endl;
        Matrix::print();
    }

    virtual void transpose() override{ // invert angle with matrix
        _angle = -_angle;
        Matrix::transpose();
    }

};
