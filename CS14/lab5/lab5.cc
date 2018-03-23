// -*- bst.cc -*-

// If you undefine TEST this file can be used as a header file
// that defines the class tree.

#ifndef BST_H
#define BST_H
#define TEST

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>

using namespace std;

#define nil 0

//#define Value int  // restore for testing. 
template < typename Value >
class Tree {

  class Node {  //  binary tree node
  public:
    Value value;
    int level;  // for Andersson trees
    Node* left;
    Node* right;
    Node( const Value v = Value(), int lev = 1 ) 
      : value(v), level(lev), left(nil), right(nil)
    {}
    Value& content()  { return value; }
    bool isInternal() { return left != nil && right != nil; }
    bool isExternal() { return left != nil || right != nil; }
    bool isLeaf()     { return left == nil && right == nil; }
    int hHeight(Node* node)
    {
        if(node == NULL)
        {
            return 0;
        }
        else
        {
            int left = hHeight(node->left);
            int right = hHeight(node->right);
            if(right > left)
            {
                return (right+1);
            }
            else
            {
                return (left +1);
            }
        }
    }
    int height() 
    { 
        // returns the height of the subtree rooted at this node
        // FILL IN
        return hHeight(*this);  
        // dummy return to suppress warnings
    }
    int size(Node* const &y, int & x)
    {
        if(y == NULL)
        {
            return 0;
        }
        x++;
        size(y->left, x);
        size(y->right, x);
        return x;
    }
    int size() {  
      // returns the size of the subtree rooted at this node, 
      // FILL IN
        int x = 0;  
        return size(*this, x);  
    }
  }; // Node


  // const Node* nil;  // later nil will point to a sentinel node.
  int count;
  Node* root;

public:
    int size(Node* const &y, int & x)
    {
        if(y == NULL)
        {
            return 0;
        }
        x++;
        size(y->left, x);
        size(y->right, x);
        return x;
    }
    int size() 
    {  
        // size of the overall tree.
        // FILL IN
        int x = 0;
        return size(root, x);
    }
    
    bool empty() 
    { 
        return size() == 0; 
    }
    
    void print_node( const Node* n ) 
    {
        // Print the node's value.
        // FILL IN
        cout << n->value;
    }
    
    bool search ( Value x ) 
    { 
        // search for a Value  in the BST and return true if it was found.
        // FILL IN
        Node* curr = root;
        while(x != curr->value)
        {
            if(x > curr->value)
            {
                if(curr->right == NULL)
                {
                    return false;
                }
                curr = curr->right;
            }
            else
            {
                if(curr->left == NULL)
                {
                    return false;
                }
                curr = curr->left;
            }
        }
        return true;
    }

    void PreOrder(Node* const & y)const
    {

        if(y == NULL)
        {
            return;
        }
        cout << y->value << endl;
        PreOrder(y->left); 
        PreOrder(y->right);
    }
    
    void preorder()const 
    {
        // Traverse and print the tree one Value per line in preorder.
        // FILL IN
        PreOrder(root);
    }
    
    void PostOrder(Node* const & y)const
    {

        if(y == NULL)
        {
            return;
        }
        PostOrder(y->left);
        PostOrder(y->right);
        cout << y->value << endl;    
    }
    void postorder()const 
    {
        // Traverse and print the tree one Value per line in postorder.
        // FILL IN
        PostOrder(root);
    }
    
    void InOrder(Node* const & y) const
    {
        if(y == NULL)
        {
            return;
        }
        InOrder(y->left);
        cout << y->value << endl;
        InOrder(y->right);
    }
    
    void inorder()const 
    {
        // Traverse and print the tree one Value per line in inorder.
        // FILL IN
        InOrder(root);
    }  

    void operatorHelper(Node* const & y, vector<Value>& a)
    {
        if(y == NULL)
        {
            return;
        }
        operatorHelper(y->left, a);
        a.push_back(y->value);
        operatorHelper(y->right, a);
    }
    Value& operator[] (int n) 
    { 
        // returns reference to the value field of the n-th Node.
        // FILL IN
        vector<Value> a;
        operatorHelper(root, a);
        return a[n];
    }

  Tree() : count(0), root(nil) {}


  void insert( Value X ) { root = insert( X, root ); }
  Node* insert( Value X, Node* T ) {
    // The normal binary-tree insertion procedure ...  
    if (  T == nil ) {
      T = new Node( X );    // the only place that T gets updated.
    } else if ( X < T->value ) {
      T->left = insert( X, T->left );
    } else if ( X > T->value ) {
      T->right = insert( X, T->right );
    } else { 
      T->value = X;
    }

    // later, rebalancing code will be installed here

    return T;
  }

  void remove( Value X ) { root = remove( X, root ); }
  Node* remove( Value X, Node* T ) {
    // The normal binary-tree removal procedure ...       
    // Weiss's code is faster but way more intricate.
    if (  T != nil ) {
      if ( X > T->value ) {
        T->right = remove( X, T->right );
      } else if ( X < T->value ) { 
        T->left = remove( X, T->left );
      } else {                                // X == T->value
        if ( T->right != nil ) {
          Node* x = T->right;
          while ( x->left != nil ) x = x->left;
          T->value = x->value;      // successor's value
          T->right = remove( T->value, T->right );
        } else if ( T->left != nil ) {

          Node* z = T->left;
          Node* x = T->left;
	  while ( x->right != nil ) {
	    z = x;
	    x = x->right;
	  }
          T->value = x->value;          // predecessor's value
          z->right = x->left;
          delete x;

//           Node* x = T->left;
//           while ( x->right != nil ) x = x->right;
//           T->value = x->value;          // predecessor's value
//           T->left = remove( T->value, T->left );

        } else {                             // *T is external
          delete T;
          T = nil;                   // the only updating of T
        }
      }
    }

    // later, rebalancing code will be installed here

    return T;
  }


  void display() { display( root ); }
  void display( Node* n ) { 
    // in-order traversal with indented display.
    static int depth = 0;
    ++ depth;
    if ( n == nil ) return;
    if ( n->right != nil ) 
      display(n->right);
    for( int i = 0; i != depth; ++i ) cout << "  ";
    cout << n->value << "-" << n->level << endl;
    if ( n->left != nil ) display(n->left);
    --depth;
  }


  void okay( ) { okay( root ); }
  void okay( Node* T ) { 
    // diagnostic code can be installed here
    T=0;  // dummy line to keep T from being unused.
    return; 
  }
   int callAvg(Node* const & y)
   {
        if(y == NULL)
        {
            return 0;
        }
        return y->value + callAvg(y->left) + callAvg(y->right);
    }
    int avg()
    {
        if(root == nil)
        {
            return 0;
        }
        return callAvg(root) / size();
    }
    int hHeight(Node*const & node)
    {
        if(node == NULL)
        {
            return 0;
        }
        else
        {
            int left = hHeight(node->left);
            int right = hHeight(node->right);
            if(right > left)
            {
                return (right+1);
            }
            else
            {
                return (left +1);
            }
        }
    }
    int height() 
    { 
        return hHeight(root);  

    }
    void callR(Node* const & y)
    {
        if(y == nil)
        {
            return;
        }
        else
        {
            callR(y->left);
            callR(y->right);
            remove(y->value);
        }
    }
    Node* Rm()
    {
        callR(root->left);
        callR(root->right);
        return root;
    }

};  // Tree


// ============== below is for testing ===============================

#ifdef TEST

int myrand() {  // a simple random number generator
  static unsigned long next = 3;
  next = next * 1103515245 + 12345;
  unsigned x = (unsigned) (next/65536) % 32768 ;
  return x % 100;
}


int main() {

  // This is a test routine to exercise the list.

  Tree<int> t;

  //int n = 0;
  //  for(;;) {
//   for(int times = 0; times != 70; ++ times ) {

//     int j = myrand();
//     cerr << "inserting: " << j << endl;
//     t.insert( j );
    // cerr << "Traversing: " << ++n << "\n";
    // t.display();
    // cerr << "done\n";
    // t.okay();

    // int k = myrand();
    // cerr << "removing: " << k << endl;
    // t.remove( k );
    // cerr<< "Traversing: " << ++n << "\n";
    // t.display();
    // cerr << "Done\n";
    // t.okay();

  //}
  t.insert(5);
  t.insert(8);
  t.insert(3);
  t.insert(12);
  t.insert(9);
  t.display();
  cout << "The size of the tree is: ";
  cout << t.size() << endl;
//   cout << "Inorder test: " << endl;
//   t.inorder();
//   cout << endl;
//   cout << "Preorder test: " << endl;
//   t.preorder();
//   cout << endl << "Postorder test: " << endl;
//   t.postorder();
//   cout << endl << "operator[] test: " << endl;
//   cout << t[3] << endl;
    cout << "The average of the tree is: ";
    cout << t.avg() << endl;
    t.Rm();
    t.inorder();
  
  

} // main

#endif
#endif
