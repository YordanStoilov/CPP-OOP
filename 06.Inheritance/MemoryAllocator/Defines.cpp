#include "Defines.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Command {
public:
    Command(string command, vector<MemoryNode>& memory)
    : index(-1), 
      type(MemoryType::UNKNOWN),
      memory(memory),
      action("Unknown")
      {
        istringstream iss(command);

        string typeStr;

        iss >> this->action >> typeStr >> this->index;

        if (typeStr == "Single") {
            this->type = MemoryType::SINGLE;
        }
        else if (typeStr == "Multiple") {
            this->type = MemoryType::MULTIPLE;
        }
    }

    ErrorCode operator()() {
        if (action == "Allocate") {
            if (memory[index].memoryType != MemoryType::UNKNOWN) {
                return ErrorCode::MEMORY_LEAK;
            }
            MemoryNode node;
            node.memoryType = type;
            memory[index] = node;
        }
        else if (action == "Deallocate") {
            if (memory[index].memoryType == MemoryType::UNKNOWN) {
                return ErrorCode::DOUBLE_FREE;
            }
            if (memory[index].memoryType != this->type) {
                return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
            }
            memory[index].memoryType = MemoryType::UNKNOWN;
        }
        return ErrorCode::EXECUTE_SUCCESS;
    }
protected:
    MemoryType type;
    int index;
    vector<MemoryNode>& memory;
    string action;
};

ErrorCode executeCommand(const string& command, vector<MemoryNode> & memory) {
    Command cmd(command, memory);
    return cmd();
}

void printResult(const ErrorCode errorCode, const string & command) {
    cout << command;

    switch (errorCode){
        case ErrorCode::EXECUTE_SUCCESS:
            cout << " - success";
            break;
        case ErrorCode::DOUBLE_FREE:
            cout << " - system crash prevented, will skip this deallocation";
            break;
        case ErrorCode::MEMORY_LEAK:
            cout << " - memory leak prevented, will not make allocation";
            break;
        case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH:
            cout << " - Warning allocate/deallocate mismatch, will skip this deallocation";
            break;
    }
    cout << endl;
}