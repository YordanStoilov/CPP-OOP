#ifndef SEQUENCE_H

#define SEQUENCE_H
#include <vector>
#include <limits.h>
template <typename T, typename Generator>
class Sequence{
public:
    void generateNext(int numToGenerate){
        while (numToGenerate--){
            data.push_back(gen());
        }
    }
private:
    class Iterator{
    public:
        Iterator(std::vector<T>& data, size_t idx)
            : data(data), idx(idx) { }
        
        static Iterator getBegin(std::vector<T>& data){
            return Iterator(data, 0);
        }
        static Iterator getEnd(std::vector<T>& data){
            return Iterator(data, ULONG_MAX);
        }
        bool operator!=(const Iterator& other) const {
            if ((&data) != (&other.data)){
                return true;
            }
            if (this->idx == other.idx){
                return false;
            }
            if (this->idx >= data.size() && other.idx >= data.size()){
                return false;
            }
            return true;
        }
        Iterator& operator++(){
            idx++;
            return *this;
        }
        T& operator*(){
            return data[idx];
        }
    private:
        std::vector<T>& data;
        size_t idx;
    };
    std::vector<T> data;
    Generator gen;

public:
    Iterator begin() { return Iterator::getBegin(data); }
    Iterator end() { return Iterator::getEnd(data); }
};

#endif