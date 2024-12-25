#include <iostream>
#include "iterator.cpp"
using namespace std;

int main()
{
    ConcreteAggregate aggregate;
    aggregate.add(1);
    aggregate.add(2);
    aggregate.add(3);
    aggregate.add(4);
    aggregate.add(5);

    Iterator *iterator = aggregate.getIterator();

    while (iterator->hasNext())
    {
        cout << iterator->getNext() << "\n";
    }
}