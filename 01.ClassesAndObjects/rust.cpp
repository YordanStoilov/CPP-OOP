#include <iostream>

class Plate{
public:
    Plate(std::istream& stream){
        for (size_t row = 0; row < SIZE; ++row){
            for (size_t col = 0; col < SIZE; ++col){
                char cell; stream >> cell;
                mtx[row][col] = cell;
            }
        }
    }
    void print(std::ostream& stream){
        for (size_t row = 0; row < SIZE; ++row){
            for (size_t col = 0; col < SIZE; ++col){
                stream << mtx[row][col];
            }
            stream << '\n';
        }
    }

private:
    static const size_t SIZE = 10;
    static const char INFECTION = '!';
    static const char HEALTHY_CELL = '.';
    static const char RESISTANT = '#';
    char mtx[SIZE][SIZE];
};
class RustProcessor{
public:
    RustProcessor(std::istream& stream) : plate(stream), iterations(0){
        stream >> iterations;
    }

private:
    size_t iterations;
    Plate plate;

};

int main(){
    RustProcessor rp(std::cin);

}