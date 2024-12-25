#include <iostream>
#include "mediator.cpp"
using namespace std;

int main()
{
    ChatRoom chatRoom;
    User *userA = new ConcreteUser("A", chatRoom);
    User *userB = new ConcreteUser("B", chatRoom);
    User *userC = new ConcreteUser("C", chatRoom);

    chatRoom.addUser(userA);
    chatRoom.addUser(userB);
    chatRoom.addUser(userC);   

    userA->sendMessage("Good morning");
    userB->sendMessage("Classes time?");
    userC->sendMessage("10:30 AM");
}