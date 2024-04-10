#include <iostream>
#include <vector>

class IWork{
public:
    virtual void print()=0;
};

class Work : public IWork{
    std::string _artist;
    std::string _name;

public:
    Work(std::string artist, std::string name):_artist(artist), _name(name){}

    std::string getArtist(){return _artist;}

    std::string getName(){return _name;}

    virtual void print() override{
        std::cout <<_artist << std::endl << _name << std::endl;
    }
};


class Collection : public IWork{
private:
    std::string _name;
    std::vector<IWork*> _v;

public:
    Collection(std::string name):_name(name){}
    void add(IWork& w){
        _v.push_back(&w);
    }

    virtual void print() override{
        std::cout << "---- Collection " << _name << " ----" << std::endl;
        for(IWork* p :_v){
            p->print();
        }
        std::cout << "---- Collection End ----" << std::endl;
    }
};


class Library{
    std::vector<Work*> _works;

public:
    void addWork(Work &work){_works.push_back(&work);}

    void printAll(){
        std::cout << "------ Library Begin ------" << std::endl;
        for(Work* w : _works){
            w->print();
            std::cout << "------------" << std::endl;
        }
        std::cout << "------ Library end ------" << std::endl;
    }

};


class Book: public Work{
    int _pages;

public:
    Book(std::string artist, std::string name, int pages): Work(artist, name), _pages(pages){}

    virtual void print() override{
        Work::print();
        std::cout << "pages: " << _pages << std::endl;
    }
};


class CD: public Work{
    int _year;

public:
    CD(std::string artist, std::string name, int year): Work(artist, name), _year(year){}

    virtual void print() override{
        Work::print();
        std::cout << "year: " << _year << std::endl;
    }
};


int main(int argc, char** argv) {
    Work w1("Merman Helville", "The big white fish");
    Work w2("Wild Oscar", "Fifty shades of Dorian Gray");
    Library l;
    l.addWork(w1);
    l.addWork(w2);
    std::cout << "The following works are in the library" << std::endl;
    l.printAll();
    CD c1("John Lemon", "Hey Dude", 1968);
    CD c2("Lion Maiden", "The slumber of the beast", 1982);
    Book b1("Hank Frerbert", "A lot of sand", 896);
    Book b2("Fen Kollet", "Caterpillars of the earth", 1104);
    l.addWork(c1);
    l.addWork(c2);
    l.addWork(b1);
    l.addWork(b2);
    l.printAll();
}
