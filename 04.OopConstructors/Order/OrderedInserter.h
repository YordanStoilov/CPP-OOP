#ifndef ORDERED_INSERTER_H

#define ORDERED_INSERTER_H
#include <vector>
#include <algorithm>
class Comparator{
public:
    bool operator()(const Company* c1, const Company* c2){
        return c1->getId() < c2->getId();
    }
};

class OrderedInserter{
public:
    OrderedInserter(std::vector<const Company*>& companies)
        : companies(companies) { }

    void insert(const Company* c){
        companies.push_back(c);
        std::sort(companies.begin(), companies.end(), comp);
    }
private:
    Comparator comp;
    std::vector<const Company*>& companies;
};
#endif