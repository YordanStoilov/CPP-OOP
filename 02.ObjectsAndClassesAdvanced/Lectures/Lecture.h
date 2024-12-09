#ifndef LECTURE.H
#define LECTURE.H
#include <set>

namespace SoftUni{
    class Lecture{
    public:
        std::__1::set<Resource>::iterator begin(){
            return resources.begin();
        }
        std::__1::set<Resource>::iterator end(){
            return resources.end();
        }
        // There can be 2 resource objects with the same ID and different links.
        // 
    public:
        static std::set<Resource> resources;
    };
}

#endif