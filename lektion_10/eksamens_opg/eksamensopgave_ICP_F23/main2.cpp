#include<iostream>
#include<vector>

//If you write all classes in a single file use:
#include "allClasses.h"

//If you write each class in a seperate file use:
//#include "cargo.h"
//#include "priority_cargo.h"
//#include "truck.h"
//#include "loading_area.h"

using namespace std;


template <class T1>
void test(T1 test, T1 target, std::string msg){
    std::string equal = test==target ? "Success: " : "Failed:  ";
    std::cout << equal << msg << "\t " << test << "    " << target << std::endl;
}

void testEps(double test, double target, std::string msg, double eps=1e-5){
    std::string equal = (target-test)*(target-test) < eps*eps ? "Success: " : "Failed:  ";
    std::cout << equal << msg << "\t " << test << " " << target << std::endl;
}

void test_2_1(){
    cout << "Testing 2.1" << endl;
    cout << "-----------" << endl;
    Cargo c("c1",10,3);
    test<std::string>(c.getName(), "c1", "getName");
    test<int>(c.getWeight(), 10, "getWeight");
    test<int>(c.getDaysToDelivery(), 3, "getDaysToDelivery");
    Cargo c2("c2",2.5,-1);
    test<std::string>(c2.getName(), "c2", "getName");
    test<int>(c2.getWeight(), 2.5, "getWeight");
    test<int>(c2.getDaysToDelivery(), 1, "getDaysToDelivery");
    cout << "-----------" << endl << endl;
}

void test_2_2(){
    cout << "Testing 2.2" << endl;
    cout << "-----------" << endl;
    PriorityCargo pc("myImportantPackage",7.3);
    test<int>(pc.getWeight(), 7.3, "getWeight");
    test<int>(pc.getDaysToDelivery(), 0, "getDaysToDelivery");
    Cargo c = pc;
    test<int>(c.getWeight(), 7.3, "getWeight");
    test<int>(c.getDaysToDelivery(), 99, "getDaysToDelivery");
    cout << "-----------" << endl << endl;
}

void test_2_3(){
    cout << "Testing 2.3" << endl;
    cout << "-----------" << endl;
    Truck t(15);
    Cargo c1("a",10.1,3);
    Cargo c2("b",2.7,4);
    PriorityCargo pc("X",1.3);

    t.addCargo(c1);
    t.addCargo(c2);
    t.addCargo(pc);

    test<double>(t.getAllCargo().size(),3,"size of getAllCargo");
    testEps(t.remainingCapacity(),0.9,"remaningCapacity");
    std::string s = "";
    for(Cargo c: t.getAllCargo()){
        s+=c.getName() + "-";
    }
    test<std::string>(s,"a-b-X-","getCargo");

    cout << "-----------" << endl << endl;
}

void test_2_4(){
    cout << "Testing 2.4" << endl;
    cout << "-----------" << endl;
    LoadingArea a;
    Cargo ca("a",7.4,3);
    Cargo cb("b",3.1,7);
    Cargo cc("c",1.1,8);
    Cargo cd("d",7.5,1);
    Cargo ce("a",4.5,7);//same name as ca
    Cargo cf("f",10.5,2);
    PriorityCargo pcx("X",6);
    PriorityCargo pcy("Y",0.2);

    a.addCargo(ca);
    a.addCargo(cb);
    a.addCargo(cf);
    a.addCargo(cc);
    a.addCargo(pcy);
    a.addCargo(cd);
    a.addCargo(pcx);
    a.addCargo(ce);

    std::string s = "";
    for(Cargo* c: a.getAvailableCargo()){
        s += c->getName() + "-";
    }
    test<std::string>(s,"a-b-f-c-Y-d-X-","addCargo");

    a.removeCargo("f");
    std::string s2 = "";
    for(Cargo* c: a.getAvailableCargo()){
        s2 += c->getName() + "-";
    }
    test<std::string>(s2,"a-b-c-Y-d-X-","removeCargo");

    Truck t(9);
    a.loadTruckSimple(t);
    std::string s3 = "";
    for(Cargo c: t.getAllCargo()){
        s3+=c.getName() + "-";
    }
    test<std::string>(s3,"a-c-Y-","loadTruckSimple");


    /* Initialize new loading area idential to a, before
    packages were removed */
    LoadingArea a2;
    a2.addCargo(ca);
    a2.addCargo(cb);
    a2.addCargo(cf);
    a2.addCargo(cc);
    a2.addCargo(pcy);
    a2.addCargo(cd);
    a2.addCargo(pcx);
    a2.addCargo(ce);


    Truck t2(9);
    a2.loadTruckAdvanced(t2);
    std::string s4 = "";
    for(Cargo c: t2.getAllCargo()){
        s4+=c.getName() + "-";
    }
    test<std::string>(s4,"X-Y-c-","loadTruckAdvanced");

    cout << "-----------" << endl;
}


int main(){
    test_2_1();
    test_2_2();
    test_2_3();
    test_2_4();


    return 0;
}
