#ifndef COMPARATORS_H

#define COMPARATORS_H
template <class T>
class LessThan{
    public: bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template <class T, class Comparator>
class Reverse{
    public: bool operator()(const T& a, const T& b) const {
        Comparator comp;
        return !comp(a, b);
    }
};
#endif