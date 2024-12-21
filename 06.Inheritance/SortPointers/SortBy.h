#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>

void sortBy(Company** begin, Company** end, bool (*comp)(const Company& a, const Company& b)){
    std::sort(begin, end, [comp] (Company* a, Company* b) {
        return comp(*a, *b);
    });
}

#endif
