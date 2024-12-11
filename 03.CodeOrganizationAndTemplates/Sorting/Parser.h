#ifndef PARSER_H

#define PARSER_H
#include <sstream>
template <class T>
class Parser{
public:
    Parser(std::istream& is, std::string& stopLine)
        : is(is), stopLine(stopLine)
    { }
    bool readNext(T& value){
        std::string command;
        getline(is, command);

        if (command == stopLine){
            return false;
        }
        std::istringstream iss(command);
        iss >> value;
        return true;
    }
private:
    std::istream& is;
    std::string stopLine;
};

#endif