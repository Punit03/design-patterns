#include <iostream>
#include <map>
using namespace std;

class IWordProcessor
{
public:
    virtual ~IWordProcessor(){};
    virtual void render(string font, int size) = 0;
};

class WordProcessor : public IWordProcessor
{
    char c;

public:
    WordProcessor(char c) : c(c){};
    void render(string font, int size) override
    {
        cout << "Character " << c << " rendered with font " << font << " and size " << size << endl;
    }
};

class WordProcessorFactory
{
    map<char, IWordProcessor*> characters;

public:
    IWordProcessor* getCharacter(char symbol)
    {
        if (characters.find(symbol) == characters.end())
        {
            IWordProcessor *wordProcessor = new WordProcessor(symbol);
            characters[symbol] = wordProcessor;
        }
        return characters[symbol];
    }
};