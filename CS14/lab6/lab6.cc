#include <iostream>
using namespace std;

/*

    #1
    4(m-1)/m^3
    1/m^2 probability that the three keys will be in the same spot
    m-1/m probablity of the 4th key not being in the same spot as the 3 chained
    4 is the amount of different possibilities from each key

    #6
    The first hash functions assumes there are only 3 items in the key. If there
    are no collisions it will return the same value every time
    The second hash function will always have collisions but it's better than 
    the first hash function because there is a way to fix collisions like 
    chaining the values.
    
    
*/

bool tableTopTennis(string paddle) // find function
{
    int pingPongBall = paddle.get_key();
    if(table[pingPongBall] == NULL)
    {
        return false;
    }
    return true;
}

void removeHash(string x) // remove function
{
    int k = x.get_key();
    if(table[k] == NULL)
    {
        return;
    }
    if(table[k].size() == 1)
    {
        detele table[k];
    }
    Node* a = table[k];
    Node* b = a;
    while(a != 0)
    {
        if(a->value == x)
        {
            b->next = a->next;
            delete a;
            return;
        }
        b = a;
        a = a->next;
    }
}


int main()
{
    
    
    
    return 0;
}