#ifndef STACK_H
#define STACK_H
#include <list>
using namespace std;

template<class T>
class Stack
{
    list<T> stk;
    public:
    void push(T x)
    {
        stk.push_back(x); // put on one end
    }
    void pop()
    {
        stk.pop_back(); // take off the same end
    }
    int size()
    {
        return stk.size();
    }
    void empty()
    {
        return stk.empty(); // check if empty
    }
    T& top()
    {
        return stk.back(); // return the top
    }
    Stack& operator=(Stack& n)
    {
        stk = n;
        return *this;
    }
};
#endif