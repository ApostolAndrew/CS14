#include "Stack.H"
#include <iostream>
using namespace std;

void Stack::push(T a)
{
    if(stk.empty())
    {
        top = a;
    }
    stk.push_back(a);
}

void Stack::pop_back()
{
    stk.pop_back();
    if(stk.empty())
    {
        top = "";
    }
}

int Stack::size()
{
    return stk.size();
}

bool Stack::empty()
{
    return stk.empty();
}