#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include "Company.h"
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>

void removeDuplicates(std::list<Company*>& companies) {
    std::map<std::string, Company*> uniques;
    std::unordered_set<Company*> unique_ptrs;

    for (Company* c : companies) {
        std::string name = c->getName();
        if (uniques.find(name) == uniques.end()) {
            uniques[name] = c;
            unique_ptrs.insert(c);
        }
        else {
            if (std::find(unique_ptrs.begin(), unique_ptrs.end(), c) == unique_ptrs.end())
                delete c;
        }
    }
    companies.clear();

    for (auto& [key, value] : uniques) {
        companies.push_back(value);
    }
}

#endif 
