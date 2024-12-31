#ifndef TYPED_STREAM_H
#define TYPED_STREAM_H
#include <sstream>

template <typename T>
class TypedStream {
public:
    TypedStream(const std::string input) : input(input) {
    }
    virtual TypedStream<std::string>& operator>>(std::string& s) {
    }
    friend std::string& operator>>(std::ostringstream& stream, std::string& s);


protected:
    std::string input;
    std::ostringstream stream;
}; 

std::string& operator>>(std::ostringstream& stream, std::string& s) {
    s = stream.str();
    return s;
}

#endif