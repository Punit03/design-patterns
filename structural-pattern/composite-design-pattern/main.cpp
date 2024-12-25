#include <iostream>
#include <vector>
#include "fileSystem.cpp"
using namespace std;

int main()
{
    vector<FileSystem *> comedyFilesContent;
    comedyFilesContent.push_back(new File("golmaal"));
    FileSystem *comedyMoviesDir = new Directory("comedy movies", comedyFilesContent);

    vector<FileSystem *> moviesDirContent;
    moviesDirContent.push_back(new File("airlift"));
    moviesDirContent.push_back(comedyMoviesDir);
    FileSystem *movieDirectory = new Directory("movies", moviesDirContent);

    cout << "All working directories:\n";
    movieDirectory->ls();
}