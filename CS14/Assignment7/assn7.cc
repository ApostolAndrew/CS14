#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Edge
{
    public:
    int end1, end2, weight;
    Edge():end1(0), end2(0), weight(0) {}
    Edge(int a, int b, int c): end1(a), end2(b), weight(c) {}
};

template< typename Item > 
class priority_queue {
public:
  typedef int Priority;             // could use float instead 

  struct Entry {
    Item item;
    Priority priority;
    Entry( Item i, Priority p ) 
      : item(i), priority(p)
    {}
  };

  vector<Entry> entries;
  bool empty() { return entries.empty(); }
  int size() { return entries.size(); }
  Item& front() { entries.back(); }
  void pop() { entries.pop_back(); }
  void push( Item item, Priority p) {     
    entries.push_back( Entry(item,p) );
    for( typeof(entries.end()) it = entries.end()-1; it != entries.begin();--it)
    {
      if ( it->priority < (it-1)->priority ) swap(*it, *(it-1));
    }
  }
};

bool operator<(Edge e1,Edge e2) {
  return(
    ( e1.weight < e2.weight )||
    ( e1.weight == e2.weight && e1.end1 < e2.end1 )||
    ( e1.weight == e2.weight && e1.end1 == e2.end1 && e1.end2 < e2.end2 )
  );
}

typedef set<Edge> Graph;

Graph prim(const Graph& g);



int main() {
  set<Edge> test;
  Edge x(1,2,3);
  Edge y(2,3,1);
  Edge z(1,3,5);
  test.insert(x);
  test.insert(y);
  test.insert(z);
  
  for(set<Edge>::iterator it = test.begin(); it != test.end(); it++)
  {
      cout << (*it).end1 << ' ' << (*it).end2 << ' ' << (*it).weight << endl;
  }
  return 0;
}

