#include <iostream>
#include <memory>

class rectangle{
    double _width;
    double _height;

public:
    rectangle(double width, double height): _width(width),_height(height){}

    double getArea(){
        return _width*_height;
    }

    virtual std::string toString(){
        std::string s = "Rectanle with area " + std::to_string(_width) + " * " + std::to_string(_height) + " = " + std::to_string(getArea());
        return s;
    }
};

class square : public rectangle{
    double _side;

public:
    square(double side):rectangle(side,side) , _side(side){}

    virtual std::string toString() override{
        std::string s = "Square with area " + std::to_string(_side) + " * " + std::to_string(_side) + " = " + std::to_string(getArea());
        return s;
    }

};


int main(){

    rectangle r(2,3);
    std::cout << r.getArea() << std::endl;
    std::cout << r.toString() << std::endl;

    square s(3);
    std::cout << s.getArea() << std::endl;
    std::cout << s.toString() << std::endl;

    rectangle* p = &s;
    std::cout << p->toString() << std::endl;

}
