#include <iostream>
using namespace std;

class Vehicle
{
// Public attributes can be accessed and changed everywhere in the code:
public:
    string ownerName;
    double price;

// Private attributes can only be accessed within the class itself:
private:
    string vinNumber;

// Protected attributes can be accessed within the class or classes that inherit it:
protected:
    double weight;
    string make;
    string model;
};

int main()
{
    Vehicle car;

    car.ownerName = "George"; // OK (public)
    car.price = 25000.25; // OK (public)

    car.weight = 2500; // Compile error (protected)
    car.make = "VW"; // Compile error (protected)

    car.vinNumber = "25041239"; // Compile error (private)
}