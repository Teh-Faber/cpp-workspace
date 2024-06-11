#pragma once

#include<vector>

class Function{
    std::vector<double> _x;
    std::vector<double> _y;

public:
    Function() {}

    Function(std::vector<double> x, std::vector<double> y):_x(x),_y(y){}

    Function(std::vector<std::vector<double>> xy){
        for(std::vector<double> v:xy){
            _x.push_back(v.at(0));
            _y.push_back(v.at(1));
        }
    }

    std::vector<double> getX(){
        return _x;
    }

    std::vector<double> getY(){
        return _y;
    }

    void addPoint(double x, double y){
        int it=0;
        for(double xVal:_x){ // go through until x is smaller than the next
            if(x<xVal){
                _x.insert(_x.begin()+it,x); // insert at current position
                break;
            }else{
                it++; // go to next
            }

            if(it >= _x.size()){ // if loop get to the end of vector
                _x.push_back(x);
            }
        }
        _y.insert(_y.begin()+it,y); // insert in matching position
    }

    double interpolate(double x){
        double alpha;
        int xv, xh, yv, yh;

        for(int i=0; i<_x.size(); i++){
            if(_x.at(i)<x<_x.at(i+1)){
                xv = _x.at(i);
                yv = _y.at(i);
                xh = _x.at(i+1);
                yh = _y.at(i+1);

                alpha = (x-xv)/(xh-xv);

                return (1-alpha)*yv+alpha*yh;
            }
        }
        return 0; // for error
    }
};


class Area{
public:
    Area() {}

    double areaTrapez(double x1, double x2, double y1, double y2){
        return (x2-x1)*(y2+y1)/2;
    }

    double areaFunction(std::vector<double> x, std::vector<double> y){
        double area=0;

         for(int i=0; i<(x.size()-1); i++){
            area += areaTrapez(x.at(i), x.at(i+1), y.at(i), y.at(i+1));
        }

        return area;
    }

    double areaFunction(Function *f){
        return areaFunction(f->getX(),f->getY());
    }
};
