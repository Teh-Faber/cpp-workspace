#include <stdio.h>
#include <iostream>
#include <math.h>

class Func{
public:
    virtual double getf(double x) = 0;
    virtual double getdfdx(double x) = 0;
};

class NumFunc: public Func{
public:
     virtual double getdfdx(double x){
        return ( getf(x+0.5*_dx) - getf(x-0.5*_dx) ) / _dx;
    }
    virtual void setDx(double dx){_dx=dx;}
    virtual double getDx(){return _dx;}
private:
    double _dx=1;
};


class Parabola: public Func{
public:
    Parabola(double a, double b, double c): _a(a),_b(b),_c(c){}
    virtual double getf(double x) override{
        return _a*x*x + _b*x + _c;
    }

    virtual double getdfdx(double x){
        return 2*_a*x + _b;
    }
private:
    double _a;
    double _b;
    double _c;
};

class Parabola_num: public NumFunc{
public:
    Parabola_num(double a, double b, double c): _a(a),_b(b),_c(c){}
    virtual double getf(double x) override{
        return _a*x*x + _b*x + _c;
    }

private:
    double _a;
    double _b;
    double _c;
};

class SolverEq : public NumFunc{
public:
    virtual double getf(double x) override{
        /* solve e^(-x) = x^2 */
        double error = std::exp(-x) - std::pow(x,2.0);
        return error*error;
    }
};

double findMinimum(Func * f, double init, double lr, int iterations){
    double x = init;
    for(int i=0; i<iterations; i++){
        double dfdx = f->getdfdx(x);
        x = x - lr*dfdx;
        std::cout << "iteration " << i << ": " << x << " " << f->getf(x) << std::endl;
    }
    return x;
}

int main(int argc, char**  argv) {

    Parabola p_an(1,2,3);
    Parabola_num p_num(1,2,3);
    p_num.setDx(0.1);

    std::cout << "Minimizing (Analytic gradient)" << std::endl;
    double result = findMinimum(&p_an, 4,0.3, 20);
    std::cout << std::endl;

    std::cout << "Minimizing (Numerical gradient)" << std::endl;
    double result_num = findMinimum(&p_num, 4,0.3, 20);
    std::cout << std::endl;

    std::cout << "Results of the minimization" << std::endl;
    std::cout << "(Analytic) f(" << result << ") = " << p_an.getf(result) << std::endl;
    std::cout << "(Numeric)  f(" << result_num << ") = " << p_num.getf(result) << std::endl;

    std::cout << "Solving e^(-x) = x^2 (Numerical gradient)" << std::endl;
    SolverEq eq;
    eq.setDx(0.01);
    double result_eq = findMinimum(&eq, 0.5,0.1, 30);
    std::cout << "e^(-x) = x^2   == " << std::exp(-result_eq) << " = " << std::pow(result_eq,2.0) << std::endl;
    std::cout << std::endl;
}
