#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include "CommandInterface.h"
#include <memory.h>

class AdvancedCI : public CommandInterface {
    public:
        AdvancedCI(std::string& text) : CommandInterface(text) 
        {}
        virtual ~AdvancedCI() = default;

        class CutTransform : public TextTransform {
            AdvancedCI* parent;

            public:
                explicit CutTransform(AdvancedCI* parent) : parent(parent)
                {}
                virtual ~CutTransform() = default;

                virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
                    if (startIndex == endIndex) {
                        parent->memory.clear();
                        return;
                    }
                    parent->memory = text.substr(startIndex, endIndex - startIndex);
                    text.erase(startIndex, endIndex - startIndex);
                }
        };
        class PasteTransform : public TextTransform {
            AdvancedCI* parent;

            public:
                explicit PasteTransform(AdvancedCI* parent) : parent(parent)
                {}
                virtual ~PasteTransform() = default;

                virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
                    if (startIndex == endIndex) {
                        text.insert(startIndex, parent->memory);
                    }
                    text.replace(text.begin() + startIndex, text.begin() + endIndex, parent->memory);
                }
        };
    protected:
        std::string memory;
        friend TextTransform;
        virtual std::vector<Command> initCommands() override {
            std::vector<Command> commands = CommandInterface::initCommands();

            commands.push_back(Command("cut", std::make_shared<CutTransform>(this)));
            commands.push_back(Command("paste", std::make_shared<PasteTransform>(this)));

            return commands;
        }
};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
    std::shared_ptr<AdvancedCI> ci = std::make_shared<AdvancedCI>(text); 
    ci->init();

    return ci;
}

#endif