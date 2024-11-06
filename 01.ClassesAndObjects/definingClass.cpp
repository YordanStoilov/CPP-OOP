#include <iostream>

class Car
{
    // attributes
    std::string make;
    std::string model;
    int year;
    double engineSize;

    // methods
    void getCarInfo();
    void increaseEngineSize(int amount);
};

int main()
{
    // Creating a car on the heap:
    Car* car = new Car();

    // Creating a car on the stack:
    Car car2;
}