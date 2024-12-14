#ifndef PROFIT_REPORT_H

#define PROFIT_REPORT_H
#include <sstream>

std::string getProfitReport(Company* begin, Company* end, std::map<int, ProfitCalculator>& profitCalculatorsByCompany){
    std::ostringstream os;

    for (;begin != end + 1; ++begin){
        int totalCompanyProfits = profitCalculatorsByCompany[begin->getId()].calculateProfit(*begin);
        os << begin->getName() << " = " << totalCompanyProfits << '\n';
    }
    return os.str();
}
#endif