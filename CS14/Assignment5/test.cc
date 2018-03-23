#include "hashmap.H"
#include <iostream>
using namespace std;

int main() {

    cerr << "default constructor" << endl;
    hashmap<int> ml;
    cerr << "copy constructor" << endl;
    hashmap<int> ml1(ml);
    cerr << "assignment constructor" << endl;
    hashmap<int> ml2 = ml;

    cerr << "destructor" << endl;
    hashmap<int> *ptr = new hashmap<int>();
    delete ptr;


    cerr << "adding elements" << endl;
    ml["January"]  = 31;
    ml["February"] = 30;
    ml["March"]    = 31;
    ml["April"]    = 30;
    ml["May"]     = 31;
    ml["June"]    = 30;
    ml["July"]    = 31;
    ml["August"]    = 31;
    ml["September"] = 30;
    ml["October"]    = 31;
    ml["November"] = 30;
    ml["December"] = 31;

    cerr << "testing find" << endl;
    cerr << "find January ml = " << (ml.find("January") != ml.end()) << endl;
    cerr << "find January ml = " << ml.find("January")->second  << endl;
    cerr << "find Blah    ml = " << (ml.find("Blah") != ml.end()) << endl;

    cerr << "these will be 0 if assignment operator implemented properly" << endl;
    cerr << "find January ml2 = " << (ml2.find("January") != ml2.end()) << endl;
    cerr << "find Blah    ml2 = " << (ml2.find("Blah") != ml2.end()) << endl;

    cerr << "testing begin and end" << endl;
    for (typeof(ml.begin()) it=ml.begin(); it!=ml.end(); it++) {
        cerr << it->second << ", ";
    }

    return 1;
}
