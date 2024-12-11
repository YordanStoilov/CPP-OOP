#ifndef PARSER_H

#define PARSER_H
#include <sstream>
template <typename T>
class Parser {
public:
    Parser(std::istream& is, std::string stopLine)
        : stopLine(stopLine),  is(is) {}

    bool readNext(T& t) {
        std::string line;
        getline(is, line);
        if (line == stopLine) { return false; }
        
        std::istringstream iss(line);
        iss >> t;
        return true;
    }
    
private:
    std::istream& is;
    std::string stopLine;
};

#endif