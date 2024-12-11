#ifndef PRINT_UTILS_H

#define PRINT_UTILS_H

template <typename T>
void printVector(std::vector<T> vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << ' ';
    }
}
#endif