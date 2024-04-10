#include <stdio.h>
#include <iostream>
#include <vector>

class Log{ // interface for all logs
public:
    virtual void add(std::string str) = 0;
    virtual void print() = 0;
};

class SimpleLog : public Log{ // simple log derived from Log
private:
        std::string _s;
public:
    virtual void add(std::string str) override{ // add strings seperated by spaces
        _s += " " + str;
    }
    virtual void print() override{  // print string
        std::cout << _s << std::endl;
    }
};

class ExtentedLog: public Log{ // extented log derived from Log
private:
    std::vector<std::string> _sVec;
public:
    virtual void add(std::string str) override{ //
        _sVec.push_back(str);
    }
    virtual void print() override{
        std::cout << "----------------" << std::endl;
        std::cout << "Debug statistics: " << std::endl;
        std::cout << "Number of messages: " << _sVec.size() << std::endl;
        std::cout << "All messages: " << std::endl;
        for(std::string s: _sVec){
            std::cout << "   " << s << std::endl;
        }
        std::cout << "----------------" << std::endl;
    }
};

int main(int argc, char**  argv) {

    SimpleLog slog;
    ExtentedLog elog;
    std::vector<Log*> logs;
    logs.push_back(&slog);
    logs.push_back(&elog);

    for(Log* l : logs){
        l->add("C++");
        l->add("er");
        l->add("sjovt");
        l->print();
    }

}
