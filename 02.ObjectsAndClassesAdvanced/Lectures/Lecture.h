#ifndef LECTURE_H
#define LECTURE_H 
#include <set>
#include <map>
#include <vector>
#include "Resource.h"

namespace SoftUni{
    class Lecture{
    public:
        std::set<Resource>::iterator begin(){
            return resources.begin();
        }
        std::set<Resource>::iterator end(){
            return resources.end();
        }
        int operator[](ResourceType rt){
            return count[rt];
        }
    private:
        std::set<Resource> resources;
        std::map<SoftUni::ResourceType, int> count;

        friend Lecture& operator<<(Lecture& l, Resource& r);
        friend std::vector<ResourceType>& operator<<(std::vector<ResourceType>& vec, Lecture& l);
    };

    Lecture& operator<<(Lecture& l, Resource& r){
        ResourceType rt = r.getType();
        auto itFound = l.resources.find(r);

        if (itFound != l.resources.end()){
                l.resources.erase(itFound);
                l.count[rt]--;
                if (l.count[rt] == 0){
                    l.count.erase(rt);
                }
            }
            l.resources.insert(r);
            l.count[rt]++;
            return l;
        }
    std::vector<ResourceType>& operator<<(std::vector<ResourceType>& vec, Lecture& l){
        // Use count map
        for (auto [key, value] : l.count){
            vec.push_back(key);
        }
        return vec;
    }
}
#endif