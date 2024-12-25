#include <iostream>
#include "command.cpp"
using namespace std;

int main()
{
    TextEditor editor;
    Command *copyCommand = new CopyCommand(editor, "Hello");
    Command *pasteCommand = new PasteComand(editor);
    TextEditorInvoker invoker;

    invoker.executeCommand(copyCommand);
    invoker.executeCommand(pasteCommand);
    invoker.undoCommand();
}