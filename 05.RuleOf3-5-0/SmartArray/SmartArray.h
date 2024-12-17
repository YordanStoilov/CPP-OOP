#ifndef SMART_ARRAY_H

#define SMART_ARRAY_H
#include <iostream>
#include <memory>

template <class T>
class SmartArray{
public:
    SmartArray();
    SmartArray(size_t size);
    SmartArray(const SmartArray& other) = delete;
    SmartArray(SmartArray&& other) = delete;
    SmartArray& operator=(const SmartArray& other) = delete;
    SmartArray& operator=(SmartArray&& other) = delete;
    ~SmartArray();
    T& operator[](size_t idx);

    void push_back(T&& element);
    void pop_back();
    size_t size() const;
    void print();
private:
    std::unique_ptr<T[]> data;
    size_t length;
    size_t capacity;
    void resize();
};

template <class T>
SmartArray<T>::SmartArray() 
    : data(std::make_unique<T[]>(5)), length(0), capacity(5)
{}

template <class T>
SmartArray<T>::SmartArray(size_t size)
    : data(std::make_unique<T[]>(size)), length(0), capacity(size)
{}

template <class T>
SmartArray<T>::~SmartArray() {}

template <class T>
T& SmartArray<T>::operator[](size_t idx){
    if (idx >= length){
        throw (std::out_of_range("Trying to access invalid index"));
    }
    return data[idx];
}

template <class T>
void SmartArray<T>::push_back(T&& element){
    if (length == capacity){
        resize();
    }
    data[length++] = element;
}

template <class T>
void SmartArray<T>::pop_back(){
    if (length == 0){
        throw (std::underflow_error("Array is empty"));
    }
    length--;
}

template <class T>
size_t SmartArray<T>::size() const {
    return length;
}

template <class T>
void SmartArray<T>::resize(){
    std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity * 2);
    for (size_t i = 0; i < length; ++i){
        newData[i] = data[i];
    }

    data = std::move(newData);
    capacity *= 2;
}

template <class T>
void SmartArray<T>::print(){
    for (size_t i = 0; i < length - 1; ++i){
        std::cout << data[i] << ' ';
    }
    std::cout << data[length - 1] << std::endl;
}

#endif