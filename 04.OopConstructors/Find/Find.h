#ifndef FIND_H

#define FIND_H
Company* find(std::vector<Company*> companies, int searchId){
    for (Company* company : companies){
        if (company->getId() == searchId){
            return company;
        }
    }
    return nullptr;
}
#endif