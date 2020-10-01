#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 
class Graph 
{ 
	int V;	 
	list<int> *adj; 
  void val(int v, bool visit[], stack<int> &st)
  {
	  visit[v] = true; 
	  for (auto i = adj[v].begin(); i != adj[v].end(); ++i) 
	  {
		  if (!visit[*i]) 
		  {
			  val(*i, visit, st); 
		  }
	  }
	  st.push(v); 
  }
public: 
	Graph(int V)
	{
	    this->V = V; 
     	adj = new list<int>[V]; 
	}
	void addEdge(int v, int w); 
	void tSort(); 
}; 
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
} 
void Graph::tSort() 
{ 
	stack<int>st; 
	bool *visit = new bool[V]; 
	for (int i = 0; i < V; i++) 
	{
		visit[i] = false; 
	}
	for (int i = 0; i < V; i++) 
	{
	  if (visit[i] == false) 
	  {
		  val(i, visit, st); 
	  }
	}
	while (st.empty() == false) 
	{ 
		cout << st.top() << " "; 
		st.pop(); 
	} 
} 
int main() 
{ 
	Graph g(6); 
	g.addEdge(2, 5); 
	g.addEdge(2, 4); 
	g.addEdge(3, 4); 
	g.addEdge(3, 1); 
	g.addEdge(5, 0); 
	g.addEdge(0, 1); 
	g.tSort(); 
	return 0; 
} 
