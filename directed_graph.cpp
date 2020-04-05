#include "directed_graph.h"

void DirectedGraph::addDirectedEdge(Node *start, Node *end)
{
    printf("link %s to %s\n", start->value.c_str(), end->value.c_str());
    // start->adjacency.push_back(end);
    start->adjacency[end] = 1;
}

void DirectedGraph::removeDirectedEdge(Node *first, Node *second)
{
    first->adjacency[second] = 0;
    // auto it = first->adjacency.begin();
    // for(; it < first->adjacency.end(); it++)
    // {
    //     if(*it == second)
    //     {
    //         break;
    //     }
    // }
    // if(it < first->adjacency.end()) first->adjacency.erase(it);
}