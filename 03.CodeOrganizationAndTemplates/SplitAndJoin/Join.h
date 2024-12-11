#ifndef JOIN_H

#define JOIN_H
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

template <typename T>
std::string join(std::vector<T> vec, std::string joinStr){
    std::ostringstream ostr;

    for (size_t i = 0; i < vec.size() - 1; ++i){
        ostr << vec[i];
        ostr << joinStr;
    }
    ostr << vec.back();
    return ostr.str();
}
#endif