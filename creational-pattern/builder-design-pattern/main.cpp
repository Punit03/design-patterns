#include <iostream>
#include "computer.cpp"
using namespace std;

int main()
{
    GamingComputerBuilder builder;
    ComputerAssembler assembler;
    Computer gamingComputer = assembler.assemble(builder);
    gamingComputer.display();
}