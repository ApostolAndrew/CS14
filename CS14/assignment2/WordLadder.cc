#include "WordLadder.H"
#include "Stack.H"
#include "Queue.H"
#include <iostream>
#include <list>
#include <cstdlib>
#include <fstream>
using namespace std;

WordLadder::WordLadder(const string& listFile)
{
    ifstream data(listFile.c_str());
    if(!data.is_open())
    {
        cerr << "file \" " << listFile << " \" not found \n";
        exit(1);
    }
    string w;
    while(data >> w)
    {
        dictionary.push_back(w);
    }
    data.close();
}

bool WordLadder::neighbors(const string& x,const string& y)
{   
    int counter = 2;
    for(unsigned i = 0; i < 5; i++)
    {
        if(x.at(i) != y.at(i))
        {
            counter--;
        }
        if(counter == 0)
        {
            return false;
        }
    }
    return true;
}

#define each(I) for(typeof((I).end()) it = (I).begin(); it!= (I).end(); ++it)
void WordLadder::outpLadder(const string& start, const string& end)
{
    Queue< Stack<string> > worklist;
    Stack<string> stk;
    stk.push(start);
    worklist.push(stk);
    while(!worklist.isEmpty())
    {
        each(dictionary)
        {
            Stack<string> stk = worklist.isFront();
            if(!neighbors(*it, stk.top()))
            {
                continue;
            }
            stk.push(*it);
            if(stk.top() != end)
            {
                worklist.push(stk);
                (it = dictionary.erase(it))--;
                continue;
            }
            Stack<string> temp;
            while (stk.top() != start)
            {
                temp.push(stk.top());
                stk.pop();
            }
            temp.push(stk.top());
            while (temp.top() != end)
            {
                cout << temp.top() << endl;
                temp.pop();
                if (temp.top() == end)
                {
                    cout << temp.top() << endl;
                }
            }

            return;
        }
        worklist.pop();
    }
}
