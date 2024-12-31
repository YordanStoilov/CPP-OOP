#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include "Company.h"
#include <string>
#include <map>
#include <set>
#include <algorithm>

void removeDuplicates(std::list<Company*>::iterator it, std::list<Company*>& companies) {
    std::set<Company*> toRemove;
    Company* comp = *it;
    std::string compName = comp->getName();

    it++;

    while (it != companies.end()) {
        if (*it == comp) {
            it = companies.erase(it);
        }
        else if ((*it)->getName() == compName) {
            toRemove.insert(*it);
            it = companies.erase(it);
        }
        else {
            it++;
        }
    }

    for (Company* c : toRemove) {
        delete c;
    }
}

void removeDuplicates(std::list<Company*>& companies) {
    auto it = companies.begin();

    while (it != companies.end()) {
        removeDuplicates(it, companies);
        it++;
    }
}

#endif 
