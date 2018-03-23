#ifndef WORDLADDER_H
#define WORDLADDER_H
#include <list>
#include <iostream>
using namespace std;

class WordLadder
{
    private:
    list<string> dictionary;
    public:
    WordLadder(const string& listFile); //default constructor
    void outpLadder(const string& start, const string& end); //output WordLadder
    bool neighbors(const string& x,const string& y); //check if two strings
    //have only one character apart
};
#endif