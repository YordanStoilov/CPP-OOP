#ifndef TYPED_STREAM_H
#define TYPED_STREAM_H
#include <string>
#include <vector>
#include <sstream>


template <class T>
class TypedStream {

public:
    TypedStream(const std::string& input) : stream(std::istringstream(input))
    {}
    virtual TypedStream<T>& operator>>(T& i) {
        return *this;
    }
    std::vector<T> readToEnd() {
        std::vector<T> result;

        T curr;
        while (true) {
            *this >> curr;
            if ((bool)stream == false) {
                break;
            }
            result.push_back(curr);
        }
        return result;
    }
    virtual ~TypedStream() = default;
protected:
    std::istringstream stream;
};

#endif