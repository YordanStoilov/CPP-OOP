#include "SmartArray.h"

template <class T>
SmartArray<T>::SmartArray() : data(new T[5]), length(0), capacity(5)
{}

template <class T>
SmartArray<T>::SmartArray(size_t size) : data(new T[size]), length(0), capacity(size)
{}

template <class T>
SmartArray<T>::~SmartArray(){
    delete[] data;
}

template <class T>
T& SmartArray<T>::operator[](size_t idx){
    if (idx >= length){
        throw (std::out_of_range("Trying to access invalid index"));
    }
    return data[idx];
}

template <class T>
void SmartArray<T>::push_back(T& element){
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
    T* newData = new T[capacity * 2];
    for (size_t i = 0; i < length; ++i){
        newData[i] = data[i];
    }

    delete[] data;

    data = newData;
    capacity *= 2;
}