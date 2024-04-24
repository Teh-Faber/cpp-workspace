#pragma once

class ComplexNumber{
private:
    double _re;
    double _im;
public:
    ComplexNumber(double re, double im);
    void print();
    double magnitude();
    ComplexNumber operator+(ComplexNumber x);
    ComplexNumber operator*(ComplexNumber x);
};
