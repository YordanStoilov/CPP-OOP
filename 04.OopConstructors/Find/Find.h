#ifndef FIND_H

#define FIND_H
Company* find(const std::vector<Company*> companies, const int searchId){
    for (Company* company : companies){
        if (company->getId() == searchId){
            return company;
        }
    }
    return nullptr;
}
#endif