#ifndef MYLIST_H
#define MYLIST_H
using namespace std;

struct Node
{
    char value;
    Node* next;
    Node(char value): value(value), next(0) {}
};

class MyList
{
    private:
        Node* head;
    public:
        MyList(); //default constructor
        MyList(const MyList &str); //constructs a list from a passed in object
        MyList(const char* str); //constructs a list from a passed in string
        ~MyList(); //destructor
        void push_front(char value); //inserts value at the front of the list
        void push_back(char value); //inserts value at the back of the list
        void pop_front(); // removes the front item from the list
        void pop_back(); // removes the last item from the list
        void swap(int i, int j); //swaps the value of the node at i with j
        void insert_at_pos(int i, char value); //insert a node with value at i
        void reverse(); //reverse the items in the list
        int size() const; //returns the number of nodes in the list
        void print() const; //prints the contents of the list
        int find(char value) const; //finds the position of the first occurence 
        //a character value
        int find(MyList& query_str) const; //finds the position of the string
        void split();
        void findN(int n);
        void findNM(Node &, int m);
        Node& retNode(int a);
        void recursive(Node& x);
        MyList & operator=(const MyList &);//assignment of 
        //one list to another
        char& operator[](const int i); //returns the character at position 
        //i
        MyList& operator+(const MyList& str); //concatenates two lists 
        //together
};
#endif
        