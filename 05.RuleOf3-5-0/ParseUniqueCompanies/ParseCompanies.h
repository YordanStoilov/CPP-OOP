#ifndef PARSE_COMPANIES_H

#define PARSE_COMPANIES_H
#include <sstream>
#include <unordered_set>
Company* parseUniqueCompanies(std::string&& input, int& numCompanies, std::string (*func)(const Company& c)) {
    std::unordered_set<std::string> identifiers;
    std::vector<Company> uniqueCompanies;
    std::istringstream iss(input);

    int id;
    std::string companyName;

    while (iss >> id >> companyName){
        Company newCompany(id, companyName);
        std::string identifier = func(newCompany);

        if (identifiers.insert(identifier).second){
            uniqueCompanies.push_back(newCompany);
        }
    }
    numCompanies = uniqueCompanies.size();

    Company* result = new Company[numCompanies];

    for (size_t i = 0; i < numCompanies; ++i) {
        result[i] = uniqueCompanies[i];
    }
    return result;
}
#endif