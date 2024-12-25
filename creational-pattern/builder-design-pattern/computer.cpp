#include <iostream>
using namespace std;

class Computer
{
    string ram;
    string storage;
    string graphicCard;
    string cpu;

public:
    void setRAM(string ram)
    {
        this->ram = ram;
    }

    void setStorage(string storage)
    {
        this->storage = storage;
    }

    void setGraphicCard(string graphicCard)
    {
        this->graphicCard = graphicCard;
    }

    void setCPU(string cpu)
    {
        this->cpu = cpu;
    }

    void display()
    {
        cout << "Computer Description :\n"
             << "RAM: " << this->ram << "\n"
             << "Storage: " << this->storage << "\n"
             << "Graphic Card: " << this->graphicCard << "\n"
             << "CPU: " << this->cpu << "\n";
    }
};

class ComputerBuilder
{
public:
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGraphicCard() = 0;
    virtual void buildCPU() = 0;
    virtual Computer getComputer() = 0;
    virtual ~ComputerBuilder() {}
};

// Concrete builder: gamingComputer
class GamingComputerBuilder : public ComputerBuilder
{
    Computer computer;

public:
    void buildRAM()
    {
        computer.setRAM("16 GB RAM");
    }

    void buildStorage()
    {
        computer.setStorage("256GB SSD");
    }

    void buildGraphicCard()
    {
        computer.setGraphicCard("NVIDIA GeForce RTX 3090");
    }

    void buildCPU()
    {
        computer.setCPU("intel core i9");
    }

    Computer getComputer()
    {
        return computer;
    }
};

// director
class ComputerAssembler
{
public:
    Computer assemble(ComputerBuilder &builder)
    {
        builder.buildRAM();
        builder.buildStorage();
        builder.buildGraphicCard();
        builder.buildCPU();
        return builder.getComputer();
    }
};