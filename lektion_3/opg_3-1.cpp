#include <iostream>

class Vehicle
{
private:
    int _wheels;
    double _price;
    double _exchangeRate;

public:
    Vehicle(int n) : _wheels(n), _price(1000), _exchangeRate(100) {}
    Vehicle(int n, double price) : _wheels(n), _price(price), _exchangeRate(100) {}

    int getNumberOfWheels(){
        return _wheels;
    };

    double getPrice(){
        return _price*100./_exchangeRate;
    };

    void setExchangeRate(double exchangeRate){
        _exchangeRate = exchangeRate;
    }

};

int main(int argc, char *argv[])
{
    Vehicle car(4, 50000);
    Vehicle bike(2);

    std::cout << "Car:" << std::endl;
    std::cout << "Number of wheels: " << car.getNumberOfWheels() << std::endl;
    std::cout << "Price in dkk: " << car.getPrice() << std::endl;

    car.setExchangeRate(693.66);
    std::cout << "Price in usd: " << car.getPrice() << std::endl;

    car.setExchangeRate(744.4);
    std::cout << "Price in eur: " << car.getPrice() << std::endl;

    car.setExchangeRate(68.42);
    std::cout << "Price in nok: " << car.getPrice() << std::endl;

    std::cout << "Bike:" << std::endl;
    std::cout << "Number of wheels: " << bike.getNumberOfWheels() << std::endl;
    std::cout << "Price in dkk: " << bike.getPrice() << std::endl;

    bike.setExchangeRate(693.66);
    std::cout << "Price in usd: " << bike.getPrice() << std::endl;

    bike.setExchangeRate(744.4);
    std::cout << "Price in eur: " << bike.getPrice() << std::endl;

    bike.setExchangeRate(68.42);
    std::cout << "Price in nok: " << bike.getPrice() << std::endl;

    return 0;
}
