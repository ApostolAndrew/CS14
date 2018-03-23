#include <iostream>
#include <cstdlib>
#include "Stack.H"
#include "WordLadder.H"
using namespace std;

int main(int argc, char* argv[]) //takes in command line arguments
{
    if(argc != 4)
    {
        cerr << "Invalid number of arguments." << endl;
        exit(1);
    }
    WordLadder a(argv[1]);
    a.outpLadder(argv[2], argv[3]);
    return 0;
}