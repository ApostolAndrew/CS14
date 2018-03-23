#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& v) 
//function that compares each node with its parent
{
    int j = 0;
    int k = 0;
    for(unsigned i = v.size()-1; i > 0; i--)
    {
        j = i;
        while(v[j] > v[(j-1)/2])
        {
            k = v[j];
            v[j] = v[(j-1)/2];
            v[(j-1)/2] = k;
            j/=2;
        }
    }
}

void Heaping(vector<int> & v, int last) 
//helper recursive function that sorts 
{
    int j = 0;
    int k = 0;
    if(last == 0)
    {
        return;
    }
    if(v[0] > v[last]) //swap the root and last unsorted 
    {
        j = v[0];
        v[0] = v[last];
        v[last] = j;
    }
    if(v[k] < v[2*k+1] || v[k] < v[2*k+2]) //make sure root is largest #
    {
        while((v[k] < v[2*k+1] || v[k] < v[2*k+2]) && 2*k+2 < last)
        {
            if(v[2*k+1] > v[2*k+2])
            {
                j = v[k];
                v[k] = v[2*k+1];
                v[2*k+1] = j;
            }
            else if(v[2*k+1] < v[2*k+2])
            {
                j = v[k];
                v[k] = v[2*k+2];
                v[2*k+2] = j;
            }
            k = 2*k + 1;
        }
    }
    Heaping(v, last-1);
}

void heapsort(vector<int>& v)
{
    if(v.empty())
    {
        return;
    }
    sort(v);
    for(unsigned i = 0;i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    Heaping(v,v.size()-1);
    return;
}

int main()
{
    vector<int> heap;
    heap.push_back(100);
    heap.push_back(500);
    heap.push_back(395);
    heap.push_back(740);
    heap.push_back(200);
    cout << "Unsorted Vector: ";
    for(unsigned i = 0;i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
    
    heapsort(heap);
    cout << "Sorted Vector: ";
    for(unsigned i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
    return 0;
}