#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include "directed_graph.h"

class WeightedGraph : public DirectedGraph
{
public:
    void addWeightedEdge(Node *first, Node *second, const int weight);
};

#endif