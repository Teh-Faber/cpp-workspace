#include <iostream>
#include <vector>
#include <string>
#include "vector3d.h"

using namespace std;

void testEps(double test, double target, std::string msg, double eps=1e-5){
    std::string equal = (target-test)*(target-test) < eps*eps ? "Success: " : "Failed:  ";
    std::cout << equal << msg << "\t " << test << " " << target << std::endl;
}

int main(){

    cout << "Constructors" << endl;
    Vector3D v(1.1,2.2,3.3);
    testEps(v.x,1.1,"x");
    testEps(v.y,2.2,"y");
    testEps(v.z,3.3,"z");

    cout << endl;

    std::vector<double> stdv{4,5.5,6.6};
    Vector3D v2(stdv);
    testEps(v2.x,4,"x");
    testEps(v2.y,5.5,"y");
    testEps(v2.z,6.6,"z");

    cout << endl;

    std::string s = "7 8.88 9.9";
    Vector3D v3(s);
    testEps(v3.x,7,"x");
    testEps(v3.y,8.88,"y");
    testEps(v3.z,9.9,"z");

    cout << endl;

    cout << "Cross products" << endl;

    Vector3D cross1 = v.crossProduct(v2);
    testEps(cross1.x,-3.63,"x");
    testEps(cross1.y,5.94,"y");
    testEps(cross1.z,-2.75,"z");

    cout << endl;

    Vector3D cross2;
    v.crossProduct(v2,&cross2);
    testEps(cross2.x,-3.63,"x");
    testEps(cross2.y,5.94,"y");
    testEps(cross2.z,-2.75,"z");

    cout << endl;

    cout << "Squareroot and normalize" << endl;

    testEps(v.squareRoot(15),3.87298,"squareroot");

    v.normalize();
    testEps(v.x,0.267261,"x");
    testEps(v.y,0.534522,"y");
    testEps(v.z,0.801784,"z");

    return 0;
}
