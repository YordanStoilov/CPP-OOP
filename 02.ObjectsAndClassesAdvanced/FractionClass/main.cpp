#include "Fraction.h"

int main(){
    // 3/4
    Fraction f1(3, 4);

    // Initially empty
    Fraction f2;

    std::cin >> f2;

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    std::cout << "F1: " << f1++ << std::endl;
    std::cout << "F2: " << ++f2 << std::endl;
    std::cout << "F1: " << f1 << std::endl;
}