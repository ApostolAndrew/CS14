#ifndef QUEUE_H
#define QUEUE_H
#include <list>
#include <iostream>
using namespace std;

template <class T>
class Queue
{
    list<T> myList;
    public:
    void push(T x)
    {
        myList.push_back(x); //put in one side
    }
    void pop()
    {
        myList.pop_front(); // take off the other
    }
    int isSize()
    {
        return myList.size();
    }
    bool isEmpty()
    {
        return myList.empty(); // check if empty
    }
    T& isFront()
    {
        return myList.front(); //return front of the list
    }
};
#endif