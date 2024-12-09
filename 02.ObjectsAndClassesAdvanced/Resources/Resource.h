#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"
#include <string>
#include <iostream>

namespace SoftUni{
    class Resource{
    public:
        SoftUni::ResourceType getType() const { return type; }
        bool operator<(const Resource& other) const {
            return this->id < other.id;
        }

    private:
        friend std::istream& operator>>(std::istream& in, SoftUni::Resource& resource);
        friend std::ostream& operator<<(std::ostream& out, const Resource& resource);
        int id;
        SoftUni::ResourceType type;
        std::string link;
	};

    std::istream& operator>>(std::istream& in, SoftUni::Resource& resource){
        int id;
        std::string type;
        std::string link;
        in >> id >> type >> link;

        resource.id = id;
        resource.link = link;
        
        if (type == "Presentation"){
            resource.type = SoftUni::ResourceType::PRESENTATION;
        }
        else if (type == "Demo"){
            resource.type = SoftUni::ResourceType::DEMO;
        }
        else if (type == "Video"){
            resource.type = SoftUni::ResourceType::VIDEO;
        }
        return in;
    }
    std::ostream& operator<<(std::ostream& out, const Resource& resource){
        out << resource.id << ' ' << resource.type << ' ' << resource.link;
        return out;
    }
}
#endif // !RESOURCE_H 
