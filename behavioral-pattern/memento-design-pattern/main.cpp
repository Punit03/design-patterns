#include <iostream>
#include "memento.cpp"

using namespace std;

int main()
{
    History history;
    TextEditor textEditor;

    textEditor.setText("Version 1");
    history.save(textEditor.save());
    cout << "[TextEditor] " << textEditor.getText() << endl;

    textEditor.setText("Version 2");
    history.save(textEditor.save());
    cout << "[TextEditor] " << textEditor.getText() << endl;

    textEditor.setText("Version 3");
    history.save(textEditor.save());
    cout << "[TextEditor] " << textEditor.getText() << endl;

    textEditor.setText("Version 4");
    cout << "[TextEditor] " << textEditor.getText() << endl;

    cout << "Undo: " << endl;
    textEditor.restore(history.undo());
    cout << "[TextEditor] " << textEditor.getText() << endl;

    cout << "Undo: " << endl;
    textEditor.restore(history.undo());
    cout << "[TextEditor] " << textEditor.getText() << endl;
}