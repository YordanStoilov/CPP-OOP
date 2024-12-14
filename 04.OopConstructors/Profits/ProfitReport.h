#ifndef PROFIT_REPORT_H

#define PROFIT_REPORT_H
#include <sstream>

std::string getProfitReport(Company* begin, Company* end, std::map<int, ProfitCalculator>& profitCalculatorsByCompany){
    std::ostringstream os;
    
    Company* it = begin;

    for (auto it = begin ;it != end + 1; ++it){
        int totalCompanyProfits = profitCalculatorsByCompany[it->getId()].calculateProfit(*it);
        os << it->getName() << " = " << totalCompanyProfits << '\n';
    }
    return os.str();
}
#endif