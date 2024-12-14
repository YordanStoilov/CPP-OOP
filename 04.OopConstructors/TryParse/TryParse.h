#ifndef TRY_PARSE_H

#define TRY_PARSE_H
#include <string> 
bool tryParse(std::string& str, int& destination){
    
    try{
        destination = std::stoi(str);
        return true;
    }
    catch (std::invalid_argument){
        return false;
    }
}
#endif