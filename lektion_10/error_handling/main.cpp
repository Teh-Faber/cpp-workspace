#include <iostream>
#include <array>
#include <vector>
#include <assert.h>

class Math{
private:
    std::array<int,5> _array;
public:
    Math():_array{2,4,6,8,10}{

    }

    int divide(int a, int b){
        assert( b > 0 );
        return a/b;
    }

    int getElement(int idx){
        if(idx < 0 | idx > _array.size()-1) throw std::invalid_argument("Index " + std::to_string(idx) + " is out of bounds");
        return _array[idx];
    }
};

int main(int argc, char**  argv) {
    Math m;
    std::cout << "Test divide" << std::endl;

    std::cout << "4/2 = " << m.divide(1,2) << std::endl;
    //td::cout << "1/0 = " << m.divide(1,0) << std::endl;
    std::cout << "9/3 = " << m.divide(9,3) << std::endl;
    std::cout << std::endl;

    std::cout << "Print array elements" << std::endl;
    std::vector<std::string> error_msgs;
    for(int i=0; i<10; i++){
        try{
        std::cout << m.getElement(i) << std::endl;
        } catch(const std::invalid_argument& e) { // catch all invalid args and add to erro_msgs list
             error_msgs.push_back(e.what());
        }
    }
    std::cout << "The for-loop is done" << std::endl;

    for(const std::string msg : error_msgs){ // print all error msgs
        std::cout << msg << std::endl;
    }
}
