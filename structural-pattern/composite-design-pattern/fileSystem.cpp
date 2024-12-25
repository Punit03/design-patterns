#include <iostream>
#include <vector>
using namespace std;

class FileSystem
{
public:
    virtual void ls() = 0;
};

class File : public FileSystem
{
    string name;

public:
    File(string name)
    {
        this->name = name;
    }
    void ls() override
    {
        cout << name << "\n";
    }
};

class Directory : public FileSystem
{
    string name;
    vector<FileSystem *> allDirectoryAndFiles;

public:
    Directory(string name, vector<FileSystem *> allDirectoryAndFiles) : name(name), allDirectoryAndFiles(allDirectoryAndFiles){};
    void ls() override
    {
        for (auto u : allDirectoryAndFiles)
        {
            cout << name << "/";
            u->ls();
        }
    }
};