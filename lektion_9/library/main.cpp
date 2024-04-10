#include <stdio.h>
#include <iostream>
#include <vector>

class IWork{
public:
    virtual void print() = 0;
};

class Work : public IWork{
private:
    std::string _artist;
    std::string _name;
public:
    Work(std::string artist, std::string name):_artist(artist), _name(name){}
    std::string getArtist() {return _artist;}
    virtual void print() override{
        std::cout << _artist << std::endl;
        std::cout << _name << std::endl;
    }
};

class Library{
private:
    std::vector<IWork*> works;
public:
    void addWork(IWork &work){works.push_back(&work);}
    void printAll(){
        std::cout << "----- Library begin -----" << std::endl;
        std::cout << "-------------" << std::endl;
        for(IWork* w: works){
            w->print();
            std::cout << "-------------" << std::endl;
        }
        std::cout << "----- Library end -----" << std::endl;
    }
};


class Collection: public IWork{
private:
    std::string _name;
    std::vector<IWork*> _works;
public:
    Collection(std::string name):_name(name){}
    void add(IWork& w){
        _works.push_back(&w);
    }
    virtual void print() override{
        std::cout << "--- Collection " << _name << " contains: " << std::endl;
        std::cout <<"--" << std::endl;
        for(int i=0; i<_works.size(); i++){
            std::cout << "Work " << i << std::endl;
            _works[i]->print();
            std::cout <<"--" << std::endl;
        }
        std::cout << "--- Collection end ---" << std::endl;
    }
};




int main(int argc, char**  argv) {
    Work c1("John Lemon", "Hey Dude");
    Work c2("Lion Maiden", "The slumber of the beast");
    Work b1("Hank Frerbert", "A lot of sand");
    Work b2("Fen Kollet", "Caterpillars of the earth");
    Work b3("Merman Helville", "The big white fish");
    Work b4("Wild Oscar", "Fifty shades of Dorian Gray");
    Library l1;
    l1.addWork(c1);
    l1.addWork(c2);
    l1.addWork(b1);
    l1.addWork(b2);
    l1.addWork(b3);
    l1.addWork(b4);
    l1.printAll();

    std::cout << std::endl << std::endl;

    Library l2;
    l2.addWork(c1);
    l2.addWork(c2);
    Collection myBooks("My Book Collection");
    myBooks.add(b1);
    myBooks.add(b2);
    myBooks.add(b3);
    myBooks.add(b4);
    l2.addWork(myBooks);
    l2.printAll();
    std::cout << std::endl << std::endl;

    Library l3;
    Collection myCollectionCollection("Nested Collections");
    Collection myCDs("My CD Collection");
    myCDs.add(c1);
    myCDs.add(c2);
    myCollectionCollection.add(myCDs);
    myCollectionCollection.add(myBooks);
    l3.addWork(myCollectionCollection);
    l3.printAll();
}
