#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include "CalculationEngine.h"

class AdvancedInterpreter : public InputInterpreter {
    public:
        virtual std::shared_ptr<Operation> getOperation(std::string operation) override {
            if (operation == "*") {
                return std::make_shared<MultiplicationOperation>();
            }
            else if (operation == "/") {
                return std::make_shared<DivisionOperation>();
            }
            else if (operation == "mr") {
                return std::make_shared<MemoryRecall>();
            }
            else if (operation == "ms") {
                return std::make_shared<MemorySave>();
            }
        }
};

class DivisionOperation : public Operation {

};

class MemoryRecall : public Operation {

};

class MemorySave : public Operation {

};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {

}

#endif