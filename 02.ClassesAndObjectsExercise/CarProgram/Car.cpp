#include <string>
#include "Car.h"

Car::Car(string brand, string model, int year) : brand(brand), model(model), year(year) {}

string Car::GetBrand() const { return brand; }
string Car::GetModel() const { return model; }
int Car::GetYear() const { return year; }