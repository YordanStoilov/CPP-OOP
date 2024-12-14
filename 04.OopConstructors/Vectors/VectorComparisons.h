#ifndef VECTOR_COMPARISONS_H

#define VECTOR_COMPARISONS_H
#include "Vector.h"

template <typename Type, typename Comparator>
class ReverseComparer{
public:
    bool operator()(const Vector& a, const Vector& b) const {
        Comparator comp;
        return !comp(a, b);
    }
};

class VectorLengthComparer{
public:
    bool operator()(const Vector& a, const Vector& b){
        return a.getLength() < b.getLength();
    }
};

#endif