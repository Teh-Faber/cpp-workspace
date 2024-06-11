#include <iostream>
#include <vector>
#include <string>
#include "function_and_area.h"

//If you write each class in a seperate file use:
//#include "function.h"
//#include "area.h"

void testEps(double test, double target, std::string msg, double eps=1e-5){
    std::string equal = (target-test)*(target-test) < eps*eps ? "Success: " : "Failed:  ";
    std::cout << equal << msg << "\t " << test << " " << target << std::endl;
}

void testFunctions(Function test, std::vector<double> xTarget, std::vector<double> yTarget, std::string msg, double eps=1e-5){
    bool equal = true;
    if(test.getX().size() == xTarget.size() && test.getY().size() == yTarget.size()){
        for(int i=0; i<test.getX().size(); i++){
            equal &= (test.getX()[i] == xTarget[i]);
            equal &= (test.getY()[i] == yTarget[i]);
        }
    }else{
        equal = false;
    }

    std::string equalStr = equal ? "Success: " : "Failed: ";
    std::cout << equalStr << msg << "\t " << std::endl;
    std::cout << "\tTest x  : ";
    for(double x : test.getX()){std::cout << x << " ";}
    std::cout << std::endl << "\tTarget x: ";
    for(double x : xTarget){std::cout << x << " ";}
    std::cout << std::endl << "\tTest y  : ";
    for(double y : test.getY()){std::cout << y << " ";}
    std::cout << std::endl << "\tTarget y: ";
    for(double y : yTarget){std::cout << y << " ";}
    std::cout << std::endl;
}

int main(){

    std::cout << "--- FUNCTION ---" << std::endl;
    std::cout << "Constructors" << std::endl;
    Function f1;
    testFunctions(f1,{},{},"f1");

    std::cout << std::endl;

    std::vector<double> x{1,2,3,5,6};
    std::vector<double> y{1,4,9,25,36};
    Function f2(x,y);
    testFunctions(f2,x,y,"Constructor f2");

    std::cout << std::endl;

    std::vector<std::vector<double> > xy{{2,4},{3,6},{4,8}};
    Function f3(xy);
    testFunctions(f3,{2,3,4},{4,6,8},"Constructor f3");

    std::cout << std::endl;

    f3.addPoint(1,2);
    f3.addPoint(5,3);
    f3.addPoint(2.5,5);
    testFunctions(f3,{1, 2, 2.5, 3, 4, 5}, {2,4,5,6,8,3}, "addPoint");

    std::cout << std::endl;

    std::vector<double> x4{1, 2, 2.5, 3, 4, 5};
    std::vector<double> y4{2,4,5,6,8,3};
    Function f4(x4,y4);
    double correctInterpolation = 6.4;
    testEps(f4.interpolate(3.2), correctInterpolation, "Interpolation");

    std::cout << std::endl << std::endl;

    std::cout << "--- AREA ---" << std::endl;

    Area a;
    double correctArea = (3.5-1.5)*(3+4)*0.5;
    testEps(a.areaTrapez(1.5,3.5,3,4),correctArea,"areaTrapez, f(1.5)=3 and f(3.5)=4");

    std::cout << std::endl;

    double correctArea_f4 = 3 + 2.25 + 2.75 + 7 + 5.5;
    testEps(a.areaFunction(x4,y4), correctArea_f4, "areaFunction: x4 y4");
    testEps(a.areaFunction(&f4), correctArea_f4, "areaFunction: f4");

    return 0;
}
