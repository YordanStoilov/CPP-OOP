#ifndef MIN_BY_H
#define MIN_BY_H
using std::string;
#include <algorithm>

string minBy(std::vector<string>& words, bool (*func)(const string& a, const string& b)){
    std::stable_sort(words.begin(), words.end(), func);
    return words[0];
}
#endif 
