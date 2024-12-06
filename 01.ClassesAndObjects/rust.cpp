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
    void rustCells(){
        putTemporaryRust();
        putRust();
    }
    void putTemporaryRust(){
        for (size_t row = 0; row < SIZE; ++row){
            for (size_t col = 0; col < SIZE; ++col){
                if (mtx[row][col] == RUST){
                    // Up
                    if (row > 0){
                        if (mtx[row - 1][col] == HEALTHY){
                            mtx[row - 1][col] = TEMP_RUST;
                        }
                    }
                    // Down
                    if (row < SIZE - 1)
                    {
                        if (mtx[row + 1][col] == HEALTHY){
                            mtx[row + 1][col] = TEMP_RUST;
                        }
                    }
                    // Left
                    if (col > 0){
                        if (mtx[row][col - 1] == HEALTHY){
                            mtx[row][col - 1] = TEMP_RUST;
                        }
                    }
                    // Right
                    if (col < SIZE - 1){
                        if (mtx[row][col + 1] == HEALTHY){
                            mtx[row][col + 1] = TEMP_RUST;
                        }
                    }
                }
            }
        }
    }
    void putRust(){
        for (size_t row = 0; row < SIZE; ++row){
            for (size_t col = 0; col < SIZE; ++col){
                if (mtx[row][col] == TEMP_RUST){
                    mtx[row][col] = RUST;
                }
            }
        }
    }
    static const size_t SIZE = 10;

private:
    static const char RUST = '!';
    static const char HEALTHY = '.';
    static const char TEMP_RUST = '?';
    static const char RESISTANT = '#';
    char mtx[SIZE][SIZE];
};

class RustProcessor{
public:
    RustProcessor(std::istream& stream) : plate(stream), iterations(0){
        stream >> iterations;
    }
    void rust(){
        size_t iterations = this->iterations;
        for (;iterations; iterations--){
            plate.rustCells();
        }
    }
    void go(std::ostream& stream){
        rust();
        plate.print(stream);
    }

private:
    size_t iterations;
    Plate plate;
};

int main(){
    RustProcessor rp(std::cin);
    rp.go(std::cout);
}