#ifndef SERIALIZE_H

#define SERIALIZE_H
#include <algorithm>
#include <sstream>

byte* serializeToMemory(std::string str, size_t& bytesWritten) {
    std::vector<byte> data;

    size_t countCompanies = std::count(str.begin(), str.end(), '\n');
    data.push_back(countCompanies);

    std::istringstream iss(str);

    std::string company;
    while (getline(iss, company, '\n')) {
        size_t countEmployees = std::count(company.begin(), company.end(), ',') + 1;
        std::istringstream companyStream(company);

        size_t id;
        std::string name;
        std::string employeesString;
        companyStream >> id >> name >> employeesString;

        data.push_back(id);
        for (char c : name) {
            data.push_back(c);
        }
        data.push_back('\0');
        data.push_back(countEmployees);

        for (char c : employeesString) {
            if (c == '(' || c == ')' || c == '.' || c == ',') {
                continue;
            }
            data.push_back(c);
        }
    }
    bytesWritten = data.size();
    byte* result = new byte[bytesWritten];

    std::copy(data.begin(), data.end(), result);

    return result;
}
#endif