#pragma once

#include <iostream>
#include <math.h>

class ComplexNumber{
    double _re;
    double _im;

public:
    ComplexNumber(double re, double im):_re(re), _im(im){}

    void print(){
        std::cout << _re << " + " << _im << "i" << std::endl;
    }

    double magnitude(){
        return sqrt( pow(_re,2) + pow(_im,2) );
    }

    ComplexNumber operator+(ComplexNumber x){
        return ComplexNumber( _re + x._re , _im + x._im );
    }

    ComplexNumber operator*(ComplexNumber x){
        return ComplexNumber( _re*x._re - _im*x._im , _re*x._im + _im*x._re );
    }
};
