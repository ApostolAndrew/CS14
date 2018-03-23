#include <iostream>
#include "MyList.H"
using namespace std;

void MyList::split()
{
    MyList* temp = new MyList();
    Node* curr = head;
    MyList* tem = new MyList();
    for(unsigned k = 0; k < size()/2;k++)
    {
        temp->push_back(curr->value);
        curr = curr->next;
    }
    for(unsigned k = size()/2; k < size(); k++)
    {
        tem->push_back(curr->value);
        curr = curr->next;
    }
    cout << "First half: ";
    temp->print();
    cout << endl << "Second half: ";
    tem->print();
}

void MyList::findN(int n)
{
    if(size()-n-1 < 0)
    {
        cout << endl << "Error: Out of range." << endl;
        exit(1);
    }
    Node* curr = head;
    for(unsigned i = 0; i < size()-n-1; i++)
    {
        curr = curr->next;
    }
    cout << endl << "The nth term from the tail is : ";
    cout << curr->value;
    cout << endl << endl;
}

void MyList::findNM(Node& n, int m)
{
    Node* temp = head;
    int count = 0;
    while(temp->next != &n)
    {
        count++;
        temp = temp->next;
        if(temp == 0)
        {
            break;
        }
    }
    int place = count - m;
    if(place < 0)
    {
        exit(1);
    }
    if(place == 0)
    {
        pop_front();
        this->print();
        return;
    }
    Node* behind = head;
    temp = head;
    count = 0;
    while(count != place)
    {
        behind = temp;
        temp = temp->next;
        count++;
    }
    behind->next = temp->next;
    delete temp;
    this->print();
}

Node& MyList::retNode(int a)
{
    Node* curr = head;
    int count = 0;
    while(count != a)
    {
        curr = curr->next;
        count++;
    }
    
    return *curr;
}

void MyList::recursive(Node & x)
{
    Node* temp = &x;
    if(x.next == 0)
    {
        cout << temp->value;
        return;
    }
    Node* hold = temp;
    temp = temp->next;
    recursive(*temp);
    cout << hold->value;
}

int main()
{
    MyList l1;
    l1.push_back('a');
    l1.push_back('b');
    l1.push_back('c');
    l1.push_back('d');
    l1.push_back('e');
    l1.print();
    cout << endl;
    l1.split();
    l1.findN(3);
    l1.findNM(l1.retNode(3),1);
    cout << endl;
    l1.recursive(l1.retNode(0));
    cout << endl;
    return 0;
}