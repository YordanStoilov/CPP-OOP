#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) { }

void Register::add(const Company& c){
    companiesArray[numAdded++] = c;
}

Company Register::get(int companyId) const{
    for (size_t i = 0; i < numAdded; ++i){
        if (companiesArray[i].getId() == companyId){
            return companiesArray[i];
        }
    }
    Company c;
    return c;
}

Register::~Register(){
    delete[] companiesArray;
}