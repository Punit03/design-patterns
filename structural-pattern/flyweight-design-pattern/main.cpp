#include <iostream>
#include "wordProcessor.cpp"
using namespace std;

int main()
{
    WordProcessorFactory factory;
    IWordProcessor *charA = factory.getCharacter('A');
    IWordProcessor *charB = factory.getCharacter('B');
    IWordProcessor *charStar = factory.getCharacter('*');

    charA->render("Aerial", 11);
    charB->render("San Francisco", 16);
    charStar->render("Times New Roman", 15);
}