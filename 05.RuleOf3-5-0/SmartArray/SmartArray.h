#ifndef SMART_ARRAY_H

#define SMART_ARRAY_H
#include <iostream>

template <class T>
class SmartArray{
public:
    SmartArray();
    SmartArray(size_t size);
    SmartArray(SmartArray& other) = delete;
    SmartArray(SmartArray&& other) = delete;
    SmartArray& operator=(SmartArray& other) = delete;
    SmartArray& operator=(SmartArray&& other) = delete;
    ~SmartArray();
    T& operator[](size_t idx);

    void push_back(T& element);
    void pop_back();
    size_t size() const;
private:
    T* data;
    size_t length;
    size_t capacity;
    void resize();
};

#endif