#include <iostream>
#include <vector>
using namespace std;

class Iterator
{
public:
    virtual ~Iterator(){};
    virtual bool hasNext() = 0;
    virtual int getNext() = 0;
};

class ConcreteIterator : public Iterator
{
    vector<int> &collection;
    int currPos;

public:
    ConcreteIterator(vector<int> &coll) : collection(coll), currPos(0){};
    bool hasNext() override
    {
        if (currPos < collection.size())
        {
            return true;
        }
        return false;
    }

    int getNext() override
    {
        return collection[currPos++];
    }
};

class Aggregate
{
public:
    virtual ~Aggregate(){};
    virtual Iterator *getIterator() = 0;
};

class ConcreteAggregate : public Aggregate
{
    vector<int> collection;

public:
    void add(int val)
    {
        collection.push_back(val);
    }

    Iterator *getIterator() override
    {
        return new ConcreteIterator(collection);
    }
};