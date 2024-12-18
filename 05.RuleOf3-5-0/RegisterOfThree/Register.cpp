#include "Register.h"
#include <sstream>
#include <algorithm>

Register::Register(size_t numCompanies) : Register() {
    companiesArray = new Company[numCompanies];
}

void Register::add(const Company& c) {
    companiesArray[numAdded++] = c;
}

Register::Register(const Register& other) : numAdded(0), companiesArray(nullptr) {
    *this = other;
}

Company Register::get(int companyId) const {
    for (size_t i = 0; i < numAdded; ++i) {
        if (companiesArray[i].getId() == companyId) {
            return companiesArray[i];
        }
    }
    return Company();
}

Register::~Register() {
    delete[] companiesArray;
}

Register& Register::operator=(const Register& other) {
    Company* newArr = new Company[other.numAdded];
    std::copy(other.companiesArray, other.companiesArray + other.numAdded, newArr);

    delete[] companiesArray;
    companiesArray = newArr;
    numAdded = other.numAdded;
    return *this;
}
