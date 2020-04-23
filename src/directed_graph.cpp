#include "directed_graph.h"

void DirectedGraph::addDirectedEdge(Node *start, Node *end)
{
    start->adjacency[end] = 1;
}

void DirectedGraph::removeDirectedEdge(Node *first, Node *second)
{
    if(!first || !second) return;
    first->adjacency.erase(second);
}