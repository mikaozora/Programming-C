#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.cpp"

struct Graph
{
	int V;
	Node *head, *tail;
};

Graph createGraph(int V)
{
	Graph g;
	g.V = V;
	g.head = g.tail = NULL;
	return g;
}

int findParent(int *parent, int pos)
{
	if (parent[pos] == pos)
	{
		return pos;
	}
	return findParent(parent, parent[pos]);
}

bool isCycle(Graph g)
{
	int parent[g.V];
	for (int i = 0; i < g.V; i++)
	{
		parent[i] = i;
	}

	Node *curr = g.head;
	while (curr)
	{

		int src = curr->edge.src;
		int dst = curr->edge.dst;
		int srcParent = findParent(parent, src);
		int dstParent = findParent(parent, dst);

		if (srcParent == dstParent)
		{
			return true;
		}
		// union
		parent[srcParent] = dstParent;
		curr = curr->next;
	}
	return false;
}

int main()
{

	Node *qHead = NULL, *qTail = NULL;

	//	//4
	pushValue(&qHead, &qTail, createEdge(0, 1, 2));
	pushValue(&qHead, &qTail, createEdge(3, 0, 4));
	pushValue(&qHead, &qTail, createEdge(2, 3, 1));
	pushValue(&qHead, &qTail, createEdge(1, 2, 3));

	//	//5
	//	pushValue(&qHead, &qTail, createEdge(0, 1, 2));
	//	pushValue(&qHead, &qTail, createEdge(0, 3, 6));
	//	pushValue(&qHead, &qTail, createEdge(1, 2, 3));
	//	pushValue(&qHead, &qTail, createEdge(1, 3, 8));
	//	pushValue(&qHead, &qTail, createEdge(1, 4, 5));
	//	pushValue(&qHead, &qTail, createEdge(2, 4, 7));
	//	pushValue(&qHead, &qTail, createEdge(3, 4, 9));

	//	//9
	//	pushValue(&qHead, &qTail, createEdge(0, 1, 4));
	//	pushValue(&qHead, &qTail, createEdge(0, 7, 8));
	//	pushValue(&qHead, &qTail, createEdge(1, 2, 8));
	//	pushValue(&qHead, &qTail, createEdge(1, 7, 11));
	//	pushValue(&qHead, &qTail, createEdge(2, 3, 7));
	//	pushValue(&qHead, &qTail, createEdge(2, 5, 4));
	//	pushValue(&qHead, &qTail, createEdge(2, 8, 2));
	//	pushValue(&qHead, &qTail, createEdge(3, 4, 9));
	//	pushValue(&qHead, &qTail, createEdge(3, 5, 14));
	//	pushValue(&qHead, &qTail, createEdge(4, 5, 10));
	//	pushValue(&qHead, &qTail, createEdge(5, 6, 2));
	//	pushValue(&qHead, &qTail, createEdge(6, 7, 1));
	//	pushValue(&qHead, &qTail, createEdge(6, 8, 6));
	//	pushValue(&qHead, &qTail, createEdge(7, 8, 7));

	int V = 4;
	Graph g = createGraph(V);
	Node *curr = qHead;
	int total = 0;
	while (curr)
	{
		pushValue(&g.head, &g.tail, curr->edge);

		if (isCycle(g))
		{
			popValue(&g.head, &g.tail, curr->edge.src, curr->edge.dst);
		}
		else
		{
			total += curr->edge.weight;
			printf("%d ---- %d (%d)\n", curr->edge.src, curr->edge.dst, curr->edge.weight);
		}
		curr = curr->next;
	}

	printf("total = %d\n", total);
	// viewNode(qHead);

	return 0;
}
