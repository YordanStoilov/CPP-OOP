#ifndef RANGE_H

#define RANGE_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class Range {
public:
    Range(int start, int end) : start(start), end(end) 
    { }
    static bool isInRangeNum(int num, Range& range) {
        return num <= range.getEnd() && num >= range.getStart();
    }
    int getStart() const { return start; }
    int getEnd() const { return end; }
    static bool isInAnyRange(int num, std::vector<Range>& ranges) {
        auto it = std::lower_bound(ranges.begin(), ranges.end(), num, [](const Range& range, const int value) {
            return range.getEnd() < value;
        });

        return it != ranges.end() && isInRangeNum(num, *it);
    }
private:
    int start;
    int end;
};

#endif