#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;

vector<string>& operator<<(vector<string>& vector, const string& str)
{
    vector.push_back(str);
    return vector;
}
string operator+(string& str, int number){
    std::ostringstream oss;
    oss << str << number;
    return oss.str();
}
std::ostream& operator<<(std::ostream& out, const vector<string> strings){
    for (auto& str : strings)
        out << str << std::endl;
    return out;
}