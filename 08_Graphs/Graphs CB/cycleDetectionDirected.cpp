#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
	int V;
	vector<int> *g;

public:
	int count = 0;
	Graph(int V)
	{
		this->V = V;
		g = new vector<int>[V];
	}
	void addEdge(int x, int y)
	{
		g[x].push_back(y);
	}
	bool cycle_helper(int node, bool *visited, bool *stack)
	{
		visited[node] = true;
		stack[node] = true;

		for (int nbr : g[node])
		{
			if (stack[nbr])
			{
				// count == g[node].size();
				return true;
			}
			else if (!visited[nbr])
			{
				bool cycle_found = cycle_helper(nbr, visited, stack);

				if (cycle_found)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool hasCycle(T src)
	{
		bool *visited = new bool[V];
		bool *stack = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = 0;
			stack[i] = 0;
		}
		return cycle_helper(src, visited, stack);
	}
};

int main()
{
	Graph<int> g(7);
	// g.addEdge(0,1);
	// g.addEdge(0,3);
	// g.addEdge(2,1);
	// g.addEdge(2,3);
	// g.addEdge(3,4);
	// g.addEdge(4,5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 2);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	if (g.hasCycle(0))
	{
		cout << "Cycle is present";
		cout << endl
			 << g.count << endl;
	}
	else
	{
		cout << "Cycle is not present.";
	}
	// g.DFS(0);
	return 0;
}