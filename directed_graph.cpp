#include "directed_graph.h"

void DirectedGraph::addDirectedEdge(Node *start, Node *end)
{
    printf("link %s to %s\n", start->value.c_str(), end->value.c_str());
    start->adjacency.push_back(end);
}