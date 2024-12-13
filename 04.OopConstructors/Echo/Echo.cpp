#include "Echo.h"

bool echoOn = true;

void echo(const std::string& message){
    if (echoOn){
        std::cout << message << std::endl;
    }
}