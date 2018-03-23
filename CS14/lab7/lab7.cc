#include <iostream>
using namespace std;

void sort(int a[], int size)
{
    int z = 0, y = 0, x = 0, j = 0;
    for(unsigned i = 0; i < size; i++)
    {
        if(a[i] == 0)
        {
            z++;
        }
        else if(a[i] == 1)
        {
            y++;
        }
        else if(a[i] == 2)
        {
            x++;
        }
    }
    for(unsigned i = 0; i < z; i++)
    {
        
        a[j] == 0;
        j++;
    }
    for(unsigned i = 0; i < y; i++)
    {
        a[i] == 1;
        j++;
    }
    for(unsigned i = 0; i < x; i++)
    {
        a[i] == 2;
        j++;
    }
}

bool numbatwo(int a[], int size, int k)
{
    if(k >= a[0])
    {
        return false;
    }
    int i = 0, int j = size - 1;
    while(i != j)
    {
        if(a[i] + a[j] == k)
        {
            return true;
        }
        else if(a[i] + a[j] > k)
        {
            j--;
        }
        else if(a[i] + a[j] < k)
        {
            k++;
        }
    }
    return false;
}

//#6
//-bubble sort: 10 
//-quicksort: 10log10

//#5
//-sorted: n^2
//-reverse-ordered input: n^2
//-random input: nlogn

int main()
{
    
    return 0;
}