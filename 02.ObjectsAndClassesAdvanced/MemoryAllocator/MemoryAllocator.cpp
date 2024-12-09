#include "Defines.h"
#include <set>
#include <sstream>
#include <iostream>
using namespace std;
using std::vector;
static int allocated = 1;

class Command{
public:
    Command(const string& command, vector<int*>& memory) : memory(memory){
        istringstream istr(command);
        istr >> this->command >> this->index;
    }
    ErrorCode execute(){
        if (index >= memory.size()){
            return ErrorCode::INDEX_OUT_OF_BOUND;
        }
        if (command == "Idle") { return ErrorCode::EXECUTE_IDLE; }
        else if (command == "Allocate"){
            return allocate();
        }
        else if (command == "Deallocate"){
            return deallocate();
        }
    }
private:
    ErrorCode allocate(){
        if (memory[index] == nullptr){
            memory[index] = &allocated;
            return ErrorCode::EXECUTE_SUCCESS;
        } else {
            return ErrorCode::MEMORY_LEAK;
        }
    }
    ErrorCode deallocate(){
        if (memory[index] == &allocated){
            memory[index] = nullptr;
            return ErrorCode::EXECUTE_SUCCESS;
        } else {
            return ErrorCode::DOUBLE_FREE;
        }
    }

    string command;
    int index;
    vector<int*>& memory;
};

ErrorCode executeCommand(const string& command, vector<int*>& memory){
    Command c(command, memory);
    c.execute();
}

void printResult(const ErrorCode errorCode, const string & command){
    cout << command;

    switch (errorCode){
        case ErrorCode::EXECUTE_SUCCESS:
            cout << " - success";
            break;
        case ErrorCode::DOUBLE_FREE:
            cout << " - system crash prevented, will skip this deallocation";
            break;
        case ErrorCode::EXECUTE_IDLE:
            cout << " - this exam is a piece of cake! Where is the OOP already?!?";
            break;
        case ErrorCode::INDEX_OUT_OF_BOUND:
            cout << " - out of bound";
            break;
        case ErrorCode::MEMORY_LEAK:
            cout << " - memory leak prevented, will not make allocation";
            break;
    }
    cout << endl;
}