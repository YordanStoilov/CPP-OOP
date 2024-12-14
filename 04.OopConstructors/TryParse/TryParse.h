#ifndef TRY_PARSE_H

#define TRY_PARSE_H
#include <string> 
#include <sstream>
bool tryParse(std::string& str, int& destination){
    std::istringstream iss(str);

    iss >> destination;

    return (bool)iss;
}

#endif