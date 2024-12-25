#include <iostream>
#include "student.cpp"
using namespace std;

int main()
{
    Student student =  Student(5432, "aman", "aman95@gmail.com");
    student.Display();
    Student student2 = student.clone();
    student2.Display();
}