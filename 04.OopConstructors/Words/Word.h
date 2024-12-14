#ifndef WORD_H

#define WORD_H
class Word{
public:
    Word(const std::string& wordStr) : wordStr(wordStr), count(1)
    { }
    const std::string& getWord() const { return wordStr; }
    int getCount() const { return count; }

    bool operator<(const Word& other) const {
        if (wordStr == other.getWord()){
            count++;
        }
        return getWord() < other.getWord();
    }

private:
    std::string wordStr;
    mutable int count;
};
#endif