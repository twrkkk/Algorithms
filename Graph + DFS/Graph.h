#pragma once
#include <iostream>

class Graph
{
private:
	int n;
	size_t** matrix;
	void memory_alloc(int n);
	void set_default_value();
public:
	Graph() { matrix = nullptr; }
	Graph(int n);
	Graph(size_t** matrix, int n);
	~Graph();
	bool set_edge(int n, int m);
	//void set_side(int n, int m);
	void set_matrix(size_t** matrix, int n);
	size_t get_edge(int n, int m) const;
	int get_size() const;
	friend std::ostream& operator<< (std::ostream& stream, const Graph& graph);
	friend std::istream& operator>> (std::istream& stream, Graph& graph);
};