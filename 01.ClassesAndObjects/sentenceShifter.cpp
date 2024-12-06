#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::string;

class Sentence{
public:
    Sentence(std::istream& stream){
        string line;
        getline(stream, line);

        std::istringstream iss(line);

        string word;
        while (iss >> word){
            words.push_back(word);
        }
    }
    void shiftWords(size_t times){
        for (;times;times--){
            string temp = words.back();
            words.pop_back();
            words.emplace(words.begin(), temp);
        }
    }
    void printWords(std::ostream& stream){
        for (string word : words){
            stream << word << std::endl;
        }
    }
private:
    std::vector<string> words;
};

int main(){
    Sentence sentence(std::cin);
    size_t times;
    std::cin >> times;

    sentence.shiftWords(times);
    sentence.printWords(std::cout);
}   