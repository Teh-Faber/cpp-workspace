#pragma once

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Vector3D{
public:
    double x;
    double y;
    double z;

    Vector3D(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}

    Vector3D(vector<double> v): x(v[0]), y(v[1]), z(v[2]) {}

    Vector3D(string s) {
        // initializing variables
        int start = 0, end = 0;
        vector<double> v;

        char sp = ' '; // defining the seperation character

        // find fist sp from end and run the loop until the end variable doesn't reach the end of the string i.e, start = -1
        while ((start = s.find_first_not_of(sp, end))!= string::npos) { // npos is constant static member that returns index of first non-sp char
            // str.find(sp, start) will return thefrom the given starting index of sp from start index
            end = s.find(sp, start);
            // substr returns substring from original string in the given index span
            v.push_back(stod(s.substr(start, end - start))); // stod converts string to double
        }

        // set x y z to corresponding numbers
        x = v[0];
        y = v[1];
        z = v[2];
    }

    Vector3D crossProduct(Vector3D v){
        return Vector3D((y*v.z-z*v.y), (z*v.x-x*v.z), (x*v.y-y*v.x));
    }


    void crossProduct(Vector3D v, Vector3D* output){
        output->x = (y*v.z-z*v.y);
        output->y = (z*v.x-x*v.z);
        output->z = (x*v.y-y*v.x);
    }


    double squareRoot(double n){
        double x0 = n/2, xi = x0, x1 = 0;
        while(!(-0.001<(xi-x1)&&(xi-x1)<0.001)){
            xi = x0;
            x1 = (xi+(n/xi))/2;
            x0 = x1;
        }
        return x0;
    }

    void normalize(){
        double len = squareRoot(x*x+y*y+z*z);
        x = x/len;
        y = y/len;
        z = z/len;
    }
};
