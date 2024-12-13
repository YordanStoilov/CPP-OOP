#ifndef SOLFEGE_NOTE_NAMING_H

#define SOLFEGE_NOTE_NAMING_H
#include <string>
#include <map>
#include "NoteName.h"
class SolfegeNoteNaming{
public:
    SolfegeNoteNaming() = default;
    NoteName operator()(const std::string& text) const {
        auto searchResult = translations.find(text);
        if (searchResult == translations.end()){
            NoteName newObj('?');
            return newObj;
        }
        NoteName newObj(searchResult->second);
        return newObj;
    }
private:
    std::map<std::string, char> translations = { 
        {"Do", 'C'}, 
        {"Re", 'D'},
        {"Mi", 'E'},
        {"Fa", 'F'},
        {"Sol", 'G'},
        {"La", 'A'},
        {"Si", 'B'}  
    };
};

#endif