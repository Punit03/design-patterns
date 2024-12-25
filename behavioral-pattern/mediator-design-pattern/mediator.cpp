#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User;

class Mediator
{
public:
    virtual void addUser(User *user) = 0;
    virtual void sendMessage(string &message, User *user) = 0;
};

class User
{
protected:
    string name;
    Mediator& mediator;

public:
    User(string name, Mediator& mediator) : name(name), mediator(mediator){};

    virtual void receiveMessage(string &message) = 0;
    virtual void sendMessage(string message) = 0;
};

class ConcreteUser : public User
{
public:
    ConcreteUser(string name, Mediator& mediator) : User(name, mediator){};

    void receiveMessage(string &message) override
    {
        cout << "[Mesage] " << message << " received by " << name << "\n";
    }

    void sendMessage(string message) override
    {
        cout << name << " sending message " << message << " to all\n";
        mediator.sendMessage(message, this);
    }
};

class ChatRoom : public Mediator
{
    vector<User *> userList;

public:
    void addUser(User *user)
    {
        userList.push_back(user);
    }

    void sendMessage(string &message, User *user)
    {
        for (auto u : userList)
        {
            if (u != user)
            {
                u->receiveMessage(message);
            }
        }
    }
};