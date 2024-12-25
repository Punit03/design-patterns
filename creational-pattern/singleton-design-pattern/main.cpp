#include <iostream>
#include "databaseConn.cpp"
using namespace std;

int main()
{
    DatabaseConn *dbConn = DatabaseConn::getInstance();
    DatabaseConn *dbConn2 = DatabaseConn::getInstance();
}