#include "IndexedSet.h"

IndexedSet::IndexedSet() : valuesArray(nullptr) {}

IndexedSet::IndexedSet(const IndexedSet& other) : valuesSet(other.valuesSet), valuesArray(nullptr) {
    if (other.valuesArray) {
        buildIndex(); 
    }
}

void IndexedSet::add(const Value& v) {
    valuesSet.insert(v);
    clearIndex(); 
}

size_t IndexedSet::size() const {
    return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
    if (!valuesArray) {
        buildIndex(); 
    }
    return valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
    if (this != &other) {
        valuesSet = other.valuesSet;
        clearIndex();
        if (other.valuesArray) {
            buildIndex();
        }
    }
    return *this;
}

IndexedSet::~IndexedSet() {
    clearIndex();
}

void IndexedSet::buildIndex() {
    clearIndex(); 

    size_t n = valuesSet.size();
    valuesArray = new Value[n];
    size_t count = 0;
    for (const auto& v : valuesSet) {
        valuesArray[count++] = v; 
    }
}

void IndexedSet::clearIndex() {
    delete[] valuesArray; 
    valuesArray = nullptr; 
}
