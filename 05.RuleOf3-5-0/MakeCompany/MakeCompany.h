#ifndef MAKE_COMPANY_H

#define MAKE_COMPANY_H
#include <memory>
#include <vector>
#include <string>
std::shared_ptr<Company> makeCompany(std::vector<std::string>& properties) {
    std::vector<std::pair<char, char>> initials;
    
    int companyId = std::stoi(properties[0]);
    std::string companyName = properties[1];

    if (properties.size() > 2)
    {
        auto it = properties.begin() + 2;
        
        while (it != properties.end()) {
            initials.push_back({(*it)[0], (*it)[1]});
            it++;
        }
    }

    std::shared_ptr<Company> newCompany = std::make_shared<Company>
        (companyId, companyName, initials);
    
    return newCompany;
}   
#endif