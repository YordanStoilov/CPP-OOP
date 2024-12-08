#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> operator<<(vector<string>& vector, string& str)
{
    vector.push_back(str);
    return vector;
}