#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

vector<string> operator+(const vector<string>& v1, const vector<string>& v2)
{
    vector<string> result;

    for (size_t i = 0; i < v1.size(); ++i)
    {
        result.push_back(v1[i] + ' ' + v2[i]);
    }
    return result;
}