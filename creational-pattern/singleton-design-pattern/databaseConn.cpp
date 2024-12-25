#include <iostream>
#include <mutex>
using namespace std;

class DatabaseConn
{
    static DatabaseConn *conn;
    static mutex mtx;

    DatabaseConn(){};

public:
    static DatabaseConn *getInstance()
    {
        if (conn == NULL)
        {
            lock_guard<mutex> lock(mtx);
            if (conn == NULL)
            {
                cout << "Making a fresh dB Connection \n";
                conn = new DatabaseConn();
            }
        }
        return conn;
    }
};

DatabaseConn *DatabaseConn::conn = nullptr;
std::mutex DatabaseConn::mtx;