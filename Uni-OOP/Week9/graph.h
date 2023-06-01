#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "myqueue.h"

class Graph
{
public:
	Graph(int vSize);
	void AddEdge(int v, int w);
	void BFS(int s);

private:
	MyVector<MyVector<int>> m_AdjList;
	int m_VertexSize;
};

#endif // GRAPH_H