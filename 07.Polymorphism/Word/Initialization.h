#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include "CommandInterface.h"
#include <memory.h>

class AdvancedCI : public CommandInterface {
    public:
        AdvancedCI(std::string& text) : CommandInterface(text), 
            cutTransform(std::shared_ptr<CutTransform>(new CutTransform))
        {}
        virtual ~AdvancedCI() = default;

        class CutTransform : public TextTransform {
            std::string content;

            public:
                virtual ~CutTransform() = default;

                virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
                    if (startIndex == endIndex) {
                        content.clear();
                        return;
                    }
                    content = text.substr(startIndex, endIndex - startIndex);
                    text.erase(startIndex, endIndex - startIndex);
                }
                std::string getContent() const { return content; }
        };
        class PasteTransform : public TextTransform {
            protected:
                std::shared_ptr<CutTransform> cutTransform;
            public:
                PasteTransform(std::shared_ptr<CutTransform> cutTransform) 
                    : cutTransform(cutTransform)
                {}
                virtual ~PasteTransform() = default;

                virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
                    text.erase(startIndex, endIndex - startIndex);
                    text.insert(startIndex, cutTransform->getContent());
                }
        };
    protected:
        std::string memory;
        std::shared_ptr<CutTransform> cutTransform;

        virtual std::vector<Command> initCommands() override {
            std::vector<Command> commands = CommandInterface::initCommands();

            commands.push_back(Command("cut", cutTransform));
            commands.push_back(Command("paste", std::make_shared<PasteTransform>(cutTransform)));

            return commands;
        }
};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
    std::shared_ptr<AdvancedCI> ci = std::make_shared<AdvancedCI>(text); 
    ci->init();

    return ci;
}

#endif