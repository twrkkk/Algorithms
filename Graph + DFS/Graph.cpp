#include "Graph.h"

void Graph::memory_alloc(int n)
{
	this->n = n;
	matrix = new size_t * [n];
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new size_t[n];
	}
}

void Graph::set_default_value()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

Graph::Graph(int n)
{
	memory_alloc(n);
	set_default_value();
}

Graph::Graph(size_t** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

Graph::~Graph()
{
	if (matrix == nullptr) return;

	for (int i = 0; i < n; i++)
	{
		delete matrix[i];
	}
	delete[] matrix;
}

bool Graph::set_edge(int n, int m)
{
	bool result = n >= 0 && n < this->n&& m >= 0 && m < this->n;
	if (result)
	{
		matrix[n][m] = 1;
		matrix[m][n] = 1;
	}
	return result;
}

void Graph::set_matrix(size_t** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

size_t Graph::get_edge(int n, int m) const
{
	bool correct = n >= 0 && n < this->n&& m >= 0 && m < this->n;
	size_t result;
	if (correct)
		result = matrix[n][m];
	else
		result = 255;
	return result;
}

int Graph::get_size() const
{
	return n;
}

//void Graph::set_side(int n, int m)
//{
//
//}

std::ostream& operator<<(std::ostream& stream, const Graph& graph)
{
	for (int i = 0; i < graph.n; i++)
	{
		for (int j = 0; j < graph.n; j++)
		{
			stream << graph.matrix[i][j] << ' ';
		}
		stream << '\n';
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, Graph& graph)
{
	int n, m;
	while (!stream.eof())
	{
		stream >> n >> m;
		graph.set_edge(n - 1, m - 1);
	}

	return stream;
}
