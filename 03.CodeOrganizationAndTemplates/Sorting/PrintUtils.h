#ifndef PRINT_UTILS_H

#define PRINT_UTILS_H
template <typename T>
void printContainer(typename T::iterator start, typename T::iterator end){
    for (; start != end; ++start){
        std::cout << *start << ' ';
    }
    std::cout << std::endl;
}
#endif