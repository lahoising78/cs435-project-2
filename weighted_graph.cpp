#include "weighted_graph.h"

void WeightedGraph::addWeightedEdge(Node *first, Node *second, const int weight)
{
    if(!first || !second) return;
    first->adjacency[second] = weight;
}

