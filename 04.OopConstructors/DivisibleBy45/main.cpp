#include "BigInt.h"
#include <iostream>

bool isDivisibleBy9(const BigInt& num){
    int sum = 0;

    for (char ch : num.getDigits()){
        sum += ch - '0';
    }
    return sum % 9 == 0;
}

bool isDivisibleBy5(const BigInt& num){
    std::string digits = num.getDigits();
    return digits.back() == '5' || digits.back() == '0';
}

bool isDivisibleBy45(const BigInt& num){

    return isDivisibleBy9(num) && isDivisibleBy5(num);
}


int main(){
    std::string from, to;

    std::cin >> from >> to;

    BigInt floor(from);
    BigInt ceil(to);

    for (;floor < ceil; floor += 1){
        if (isDivisibleBy45(floor)){
            std::cout << floor << std::endl;
        }
    }
    return 0;
}