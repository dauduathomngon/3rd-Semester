#include "graph.h"

Graph::Graph(int vSize)
: m_VertexSize(vSize)
{
	m_AdjList.Reserve(vSize);
}

void Graph::AddEdge(int v, int w)
{
	m_AdjList[v].Push(w);
}

void Graph::BFS(int s)
{
	// create visited node
	MyVector<bool> visited;
	visited.Reserve(m_VertexSize);
	for (int i = 0; i < m_VertexSize; i++)
	{
		visited.Push(false);
	}

	// create a queue
	MyIntQueue q(m_VertexSize + 1);

	// mark current node as visited
	visited[s] = true;
	q.Enqueue(s);

	while (!q.isEmpty())
	{
		// get first element of queue
		int v = q.GetFront();
		std::cout << v << " ";

		// remove it from queue
		q.Dequeue();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int i = 0; i < m_AdjList[v].Size(); i++)
		{
			int node = m_AdjList[v][i];
			if (!visited[node])
			{
				visited[node] = true;
				q.Enqueue(node);
			}
		}
	}
}