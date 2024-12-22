#include "Range.h"

using namespace std;

int main() {
    vector<Range> ranges;

    string line;
    while (std::getline(std::cin, line) && line != ".") {
        int begin, end;

        istringstream iss(line);
        iss >> begin >> end;

        Range newRange(begin, end);
        ranges.push_back(newRange);
    }

    sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        return a.getStart() < b.getStart();
    });

    while (std::getline(std::cin, line) && line != ".") {
        int num = stoi(line);

        string msg = Range::isInAnyRange(num, ranges) ? "in" : "out";
        cout << msg << endl;
    }
    return 0;
}