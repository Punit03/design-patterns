#include <iostream>
#include <stack>

using namespace std;

class TextEditor
{
    string text;

public:
    void copy(string newText)
    {
        text = newText;
        cout << "Copied text: " << text << "\n";
    }

    void paste()
    {
        cout << "Pasted text: " << text << "\n";
    }

    void undoPaste()
    {
        text.clear();
        cout << "Undo paste: cleared text " << "\n";
    }
};

class Command
{
public:
    virtual ~Command(){};
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class CopyCommand : public Command
{
    TextEditor &editor;
    string text;

public:
    CopyCommand(TextEditor &editor, string text) : editor(editor), text(text){};
    void execute() override
    {
        editor.copy(text);
    }

    void undo() override
    {
        // no undo operation
    }
};

class PasteComand : public Command
{
    TextEditor &editor;

public:
    PasteComand(TextEditor &editor) : editor(editor){};
    void execute() override
    {
        editor.paste();
    }

    void undo() override
    {
        editor.undoPaste();
    }
};

class TextEditorInvoker
{
    stack<Command *> commandHistory;

public:
    void executeCommand(Command *command)
    {
        command->execute();
        commandHistory.push(command);
    }

    void undoCommand()
    {
        if (!commandHistory.empty())
        {
            Command *lastCommand = commandHistory.top();
            lastCommand->undo();
            commandHistory.pop();
        }
    }
};