#pragma once
#include <string>
using std::string;

class Car
{
public:
    Car(string brand, string model, int year);

    string GetBrand() const;
    string GetModel() const;
    int GetYear() const;

private:
    const string brand;
    const string model;
    const int year;
};