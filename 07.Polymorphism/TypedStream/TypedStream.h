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
    virtual std::string& operator>>(std::ostream& stream, std::string& s) {
    s = stream.str();
    return s;
}

    std::string readToEnd(void) {
        return stream.str();
    }
protected:
    std::string input;
    std::ostringstream stream;
}; 

#endif