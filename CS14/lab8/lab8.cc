#include <iostream>
using namespace std;


//#1
// V1 = k                   set 1 has k vertices
// V2 = n-k                 set 2 has the rest of the vertices
// V1*V2 = k(n-k)           
// k = n/2                  the maximum edges occur when both edges have n/2
// V1*V2 =(n/2)(n-(n/2))
// V1*V2 = n^2/4
//
//#2
//every tree has levels and every node points to the next level of a tree
//

void strong_connect(Node* x) //3
{
    if(x == NULL)
    {
        return;
    }
    int count = 0;
    findall(count, x, x)
}

void findall(int count,Node* y, Node* x)
{
    if(x == NULL)
    {
        return;
    }
    if(x == y)
    {
        cout << count << endl;
    }
    count++;
    findall(count, y, x->right);
    findall(count, y, x->left);
}

void order(Node* y)
{
    vector<Node*> x;
    helper(y, x);
    //pushes all nodes in the tree into a vector
    x.sort(); 
    //sort based on extra component of Node that holds # of children per Node
    for (int i = 0; i < x.size(); i++)
    {
        cout << x.at(i)->data << endl;
    }

int main()
{

    return 0;
}