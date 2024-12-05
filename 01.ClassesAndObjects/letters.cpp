#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <iostream>
#include <cctype>
using std::vector;
using std::string;
using std::set;

class Text
{
public:
    Text(std::istream& stream)
    {
        string buffer;
        getline(stream, buffer);
        for (int i = 0; i < buffer.size(); ++i)
        {
            if (ispunct(buffer[i])) { buffer[i] = ' '; }
        }
        std::istringstream ss(buffer);

        string word;
        while (ss >> word) { words.insert(word); }
    }
    void printFoundWords(char letter)
    {
        letter = toLower(letter);
        for (string word : words)
        {
            for (int i = 0; i < word.size(); ++i)
            {
                char currentChar = toLower(word[i]);
                if (currentChar == letter)
                {
                    std::cout << word << ' ';
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
private:
    set<string> words;
    char toLower(char character)
    {
        return std::tolower(static_cast<unsigned char>(character));
    }
};

int main()
{
    Text textObj(std::cin);

    char command;
    while (true)
    {
        std::cin >> command;
        if (command == '.') { break; }
        textObj.printFoundWords(command);
    }
}