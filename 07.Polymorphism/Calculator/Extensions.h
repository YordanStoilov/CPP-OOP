#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include "CalculationEngine.h"
#include <stack>

class MedianOperation : public Operation {

protected:
    std::vector<int> operands;
    int result;
};

class DivisionOperation : public MedianOperation {

public:
    virtual void addOperand(int operand) override {
        this->operands.push_back(operand);

        if (this->isCompleted()) {
            this->result = this->operands[0] / this->operands[1];
        }
    }
    virtual int getResult() override {
        return result;
    }
    virtual bool isCompleted() override {
        return this->operands.size() == 2;
    }

    virtual ~DivisionOperation() = default;
};

class MemorySet : public Operation {
    std::stack<int> memory;

public:
    virtual void addOperand(int operand) override {
        memory.push(operand);
    }
    virtual int getResult() override {
        if (memory.empty()) {
            return 0;
        }
        int result = memory.top();
        memory.top();

        return result;        
    }
    virtual bool isCompleted() override {
        return false;
    }

    virtual ~MemorySet() = default;
};

class MemoryRecall : public Operation {
    MemorySet& ms;

public:
    MemoryRecall(MemorySet& ms) 
        : ms(ms)
        {}
    virtual void addOperand(int operand) override {
        return;
    }
    virtual int getResult() override {
        return ms.getResult();
    }
    virtual bool isCompleted() override {
        return true;
    }

    virtual ~MemoryRecall() = default;
};

class AdvancedInterpreter : public InputInterpreter {
    std::shared_ptr<MemorySet> ms;
    std::shared_ptr<MemoryRecall> mr;

public:
    AdvancedInterpreter(CalculationEngine& engine) 
            : InputInterpreter(engine)
            , ms(std::make_shared<MemorySet>())
            {}
    virtual std::shared_ptr<Operation> getOperation(std::string operation) override {
        if (operation == "/") {
            return std::make_shared<DivisionOperation>();
        }
        else if (operation == "mr") {
            return std::make_shared<MemoryRecall>(*ms.get());
        }
        else if (operation == "ms") {
            return ms;
        }

        return InputInterpreter::getOperation(operation);
    }
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
    return std::make_shared<AdvancedInterpreter> (engine);
}

#endif