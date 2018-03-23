#include "MyList.H"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

MyList::MyList() //default constructor
:head(0) {}

MyList::MyList(const MyList& str) //copies a list
:head(0)
{
    for(Node* curr = str.head; curr != 0; curr = curr->next)
    {
        push_back(curr->value);
    }
}

MyList::MyList(const char* str) //copies a string
:head(0)
{
    for(unsigned i = 0;str[i] != 0; i++)
    {
        if(head == 0)
        {
            Node* temp = new Node(str[i]);
            head = temp;
        }
        else
        {
            Node* curr = head;
            for(curr; curr->next != 0; curr = curr->next);
            Node* temp = new Node(str[i]);
            curr->next = temp;
        }
    }
}

MyList::~MyList() //destructor
{
    while(head != 0)
    {
        Node *curr = head;
        if(curr->next == 0)
        {
            head = 0;
            delete curr;
            break;
        }
        head = curr->next;
        delete curr;
    }
}

void MyList::push_front(char value) //puts a character at the front of the list
{
    if(head == 0)
    {
        Node* temp = new Node(value);
        head = temp;
    }
    else
    {
        Node* temp = new Node(value);
        temp->next = head;
        head = temp;
    }
}

void MyList::push_back(char value) //adds a character at the end of the list
{
    if(head == 0)
    {
        Node* temp = new Node(value);
        head = temp;
    }
    else
    {
        Node* curr = head;
        for(curr; curr->next != 0; curr = curr->next);
        Node* temp = new Node(value);
        curr->next = temp;
    }
}

void MyList::print() const //print out the list
{
    for(Node* curr = head; curr != 0; curr = curr->next)
    {
        cout << curr->value;
    }
}

void MyList::pop_front() //takes off the first node
{
    if(head == 0);
    else if(head->next == 0)
    {
        delete head;
        head = 0;
    }
    else
    {
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
}

void MyList::pop_back() //take off the last node
{
    if(head ==0);
    else if(head->next == 0)
    {
        delete head;
        head = 0;
    }
    else
    {
        Node* curr = head;
        for(curr; curr->next->next != 0; curr = curr->next);
        delete curr->next;
        curr->next = 0;
        
    }
}

void MyList::swap(int i, int j) //swap values at i and j
{
    Node* first = head;
    Node* second = head;
    for(int k = 0; k < i; k++)
    {
        if(first->next == 0)
        {
            cout << endl << "Error: Out of range." << endl;
            exit(1);
        }
        else
        {
            first = first->next;
        }
    }
    for(int k = 0; k < j; k++)
    {
        if(second->next == 0)
        {
            cout << endl << "Error: Out of range." << endl;
            exit(1);
        }
        else
        {
            second = second->next;
        }   
    }
    char temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void MyList::insert_at_pos(int i, char value) //insert value at i
{
    if(head == 0)
    {
        cout << endl << "Error: Out of range." << endl;
        exit(1);
    }
    else
    {
        if(i == 0)
        {
            push_front(value);
            return;
        }
        Node* behind = head;
        for(int k = 0; k < i-1; k++)
        {
            if(behind->next == 0)
            {
                cout << endl << "Error: Out of range." << endl;
                exit(1);
            }
            behind = behind->next;
        }
        Node* temp = new Node(value);    
        temp->next = behind->next;
        behind->next = temp;
    }
}

void MyList::reverse() //reverse the list
{
    if(head == 0);
    else
    {
        vector<char> list;
        for(Node* curr = head; curr != 0; curr = curr->next)
        {
            unsigned i = 0;
            list.push_back(curr->value);
        }
        while(head != 0)
        {
            pop_front();
        }
        for(unsigned i = 0; i < list.size(); i++)
        {
            push_front(list[i]);
        }
    }
}

int MyList::size() const //returns the size of the list
{
    int count = 0;
    for(Node* curr = head; curr != 0; curr = curr->next)
    {
        count++;
    }
    return count;
}

int MyList::find(char value) const //returns the position of value
{
    int i = 0;
    for(Node* curr = head; curr != 0; curr = curr->next)
    {
        if(curr->value == value)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int MyList::find(MyList& query_str) const //returns the position of a str
{
    int pos;
    int count = 0;
    Node* str = query_str.head;
    for(Node* curr = head; curr != 0; curr = curr->next)
    {
        if(str->value == curr->value && str == query_str.head)
        {
            if(str->next == 0)
            {
                return 0;
            }
            str = str-> next;
            pos = count;
        }
        else if(str->value == curr->value)
        {
            if(str->next == 0)
            {
                return pos;
            }
            str = str->next;
        }
        else if(str->value != curr->value)
        {
            str = query_str.head;
        }
        count++;
    }
    return -1;
}

MyList& MyList::operator=(const MyList& str)
{
    if(this != &str)
    {
        while(this->head != 0)
        {
            this->pop_front();
        }
    for(Node* curr = str.head; curr != 0; curr = curr->next)
    {
        this->push_back(curr->value);
    }        
    }
    return *this;
}

char& MyList::operator[](const int i)
{
    int k = 0;
    for(Node* curr = head; curr != 0; curr = curr->next)
    {
        if(k == i)
        {
            return curr->value;
        }
        k++;
    }
    cout << endl << "Error: Out of range." << endl;
    exit(1);
}

MyList& MyList::operator+(const MyList & str)
{
    
    if(str.head == 0)
    {
        return *this;
    }
    else
    {
        for(Node* curr = str.head; curr != 0; curr = curr->next)
        {
            this->push_back(curr->value);
        }
        return *this;
    }
}

