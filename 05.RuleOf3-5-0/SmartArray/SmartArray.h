#ifndef SMART_ARRAY_H

#define SMART_ARRAY_H
#include <iostream>
#include <memory>

template <class T>
class SmartArray{
public:
    SmartArray();
    SmartArray(size_t size);
    SmartArray(const SmartArray& other){
        std::unique_ptr newArr = std::make_unique<T>(other.length);
        std::copy(other, other.length, newArr);
    }

    SmartArray(SmartArray&& other) : length(other.length), capacity(other.capacity) {
        SmartArray newArr;
        std::swap(data, other.data);

        other.capacity = 0;
        other.length = 0;
    }

    SmartArray& operator=(const SmartArray& other) {
        length = other.length;
        capacity = other.capacity;
        std::copy(other.data, other.length, data);
    }
    SmartArray& operator=(SmartArray&& other){
        SmartArray newArr;
        std::swap(data, other.data);

        other.capacity = 0;
        other.length = 0;
    }
    ~SmartArray();
    T& operator[](size_t idx);

    void push_back(T& element);
    void push_back(T&& element);
    void pop_back();
    size_t size() const;
    void print();

    class Iterator{
    public:
        Iterator(size_t idx, SmartArray& parent) 
            : idx(idx), data(parent.data.get()), size(parent.size()) 
        {}
        Iterator& operator++(){
            idx++;
            return *this;
        }
        bool operator!=(const Iterator& other){
            if (data != other.data || size != other.size) { return true; }

            if (idx >= size && other.idx >= other.size){
                return false;
            }

            return idx != other.idx;
        }
        T& operator*() { return data[idx]; }

    private:
        T* data;
        size_t size;
        size_t idx;
    };

    Iterator begin() { return Iterator(0, *this); }
    Iterator end()   { return Iterator(UINT_MAX, *this); }

private:
    const size_t defaultCapacity = 5;
    std::unique_ptr<T[]> data;
    size_t length;
    size_t capacity;
    void resize();
};

template <class T>
SmartArray<T>::SmartArray() 
    : data(std::make_unique<T[]>(defaultCapacity)), length(0), capacity(defaultCapacity)
{}

template <class T>
SmartArray<T>::SmartArray(size_t size)
    : data(std::make_unique<T[]>(size)), length(0), capacity(size)
{
    if (size < 0){
        throw std::invalid_argument("Capacity must be greater than 0.");
    }
}

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
    data[length++] = std::forward<T>(element);
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
    std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity * 2);
    for (size_t i = 0; i < length; ++i){
        newData[i] = std::move(data[i]);
    }

    data = std::move(newData);
    capacity *= 2;
}

template <class T>
void SmartArray<T>::print(){
    for (size_t i = 0; i < length; ++i){
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

#endif