#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Memento
{
    string state;

public:
    Memento(string text) : state(text){};
    string getState()
    {
        return state;
    }
};

class TextEditor
{
    string text;

public:
    void setText(string inputText)
    {
        text = inputText;
    }

    string getText()
    {
        return text;
    }
    Memento save()
    {
        return Memento(text);
    }

    void restore(Memento state)
    {
        text = state.getState();
    }
};

class History
{
    stack<Memento> mementos;

public:
    void save(Memento state)
    {
        mementos.push(state);
    }

    Memento undo()
    {
        if (mementos.empty())
        {
            cout << "No mementos to undo \n";
            exit(1);
        }
        Memento prevMemento = mementos.top();
        mementos.pop();
        return prevMemento;
    }
};