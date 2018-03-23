#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>
using namespace std;

#define each(I) for (typeof((I).begin()) it = (I).begin(); it!=(I).end(); it++)
template< typename Key, typename T>
class Node { 
    public:
    Key first;
    mutable T second;
    enum{free, active, deactivated} state;
    Node() :first(), second(), state(free) {}
    Node( Key s, T t ) : first(s), second(t),state(active) {}
}; // end of Node

unsigned int hash(const string & x) //first hash function
{
    unsigned int h = 0;
    each(x) h = 37 * h + unsigned(*it);
    return h % 103;
}

unsigned int hash2(const string & x) //double hash function
{
    unsigned int h = 0;
    each(x) h = 37 * h + unsigned(*it);
    return (h % 7) + 1;
}
template <typename T >
class hashmap {
public:

    typedef vector<Node<string,T> > VectorPair;
    VectorPair vec;
    hashmap() :vec(103) {}  // set vec to 103 size
    hashmap(const hashmap & x): vec(x.vec) {} //copy constructor
    hashmap & operator=(const hashmap & x) //assignment operator
    {
        vec = x.vec;
        return *this;
    }
    ~hashmap() {} //deconstructor
    T& operator[](string a) //
    {
        int counter = 0;
        unsigned int hashin = hash2(a);
        if(vec.at(hash(a)).state == Node<string, T>::free) //if spot is free
        //set node to active and set key to a
        {
            vec.at(hash(a)).state = Node<string, T>::active;
            vec.at(hash(a)).first = a;
            return vec.at(hash(a)).second;
        }
        while(counter < 103)
        //double hash, counter determines overflow
        {
            counter++;
            if(vec.at((hash(a) + hashin) % 103).state == Node<string, T>::free)
            {
                vec.at((hash(a) + hashin) % 103).first = a;
                //vec.at((hash(a) + hashin) % 103).state = 
                //Node<string, T>::active;
                return vec.at((hash(a) + hashin) % 103).second;
            }
            hashin += hashin;
        }
        //overflow if not put into any spot
        cerr << "Error: Overflow" << endl;
        exit(1);
        return vec.at(hash(a)).second;

    }
    typename VectorPair::iterator find(const string & x)
    {
        each(vec)
        //macro iterating through to find a key
        {
            if(it->first == x)
            {
                return it; //return iterator with the key
            }
        }
        return vec.end(); //else return end
    }
    typename VectorPair::iterator begin()
    {
        each(vec)
        {
            if(it->state == Node<string, T>::active)
            {
                return it;
            }
        }
        return vec.end();
    }
    typename VectorPair::iterator end()
    {
        return vec.end();
    }
  
  
}; // end of mymap