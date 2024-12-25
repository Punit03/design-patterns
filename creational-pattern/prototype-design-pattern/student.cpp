#include <iostream>
using namespace std;

class Student
{
    int id;
    string name;
    string email;

public:
    Student(int id, string name, string email) : id(id), name(name), email(email){};
    void Display()
    {
        cout << "id: " << id << "\n";
        cout << "name: " << name << "\n";
        cout << "email: " << email << "\n";
    }
    Student clone()
    {
        return Student(id, name, email);
    }
};