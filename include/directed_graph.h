#ifndef _DIRECTED_GRAPH_H_
#define _DIRECTED_GRAPH_H_

#include "graph.h"

class DirectedGraph : public Graph
{
public:
    void addDirectedEdge(Node *start, Node *end);
    void removeDirectedEdge(Node *first, Node *second);
};

#endif