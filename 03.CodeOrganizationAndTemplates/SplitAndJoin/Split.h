#ifndef SPLIT_H

#define SPLIT_H

class Song;

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

template <typename T>
std::vector<T>split(const std::string& line, char separator){
    std::vector<T> vec;
    std::istringstream iss(line);
    
    while (true){
        std::string buffer;
        if (!getline(iss, buffer, separator)){
            break;
        }

        T result;
        std::istringstream data(buffer);
        data >> result;
        vec.push_back(result);
    }
    return vec;
}
#endif