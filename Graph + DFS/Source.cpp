#include "Graph.h"
#include <fstream>

void dfs(const Graph& g, bool* flags, int i, int prev)
{
	int size = g.get_size();
	flags[i] = true; 
	for (int j = 0; j < size; j++)
	{
		if (g.get_edge(i, j) == 1 && !flags[j])
		{
			//std::cout << j;
			dfs(g, flags, j, i);
		}
		else if (g.get_edge(i, j) == 1 && j != prev)
		{
			std::cout << "YES\n";
			exit(0);
		}
	}
}

void DFS(Graph& g)
{
	int m = g.get_size();
	bool* flags = new bool[m] {false};
	for (int i = 0; i < m; i++)
	{
		if (!flags[i])
			dfs(g, flags, i,i-1);
	}
	std::cout << "NO\n";
}

int main()
{
	std::ifstream file("data.txt");
	int size, delim;
	file >> size >> delim;
	//std::cin >> size >> delim;
	Graph graph(size);
	file >> graph;
	/*int n, m;
	for (int i = 0; i < delim; i++)
	{
		std::cin >> n >> m;
		graph.set_edge(n, m);
	}*/
	std::cout << graph;
	std::cout << '\n';
	DFS(graph);
}