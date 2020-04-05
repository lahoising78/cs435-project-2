#include <iostream>
#include "graph.h"

/* --========== problem functions ==========- */
void Graph::addNode(const std::string nodeVal)
{
    Node n(nodeVal);
    // n.value = nodeVal;

    nodes[nodeVal] = n;
    n.adjacency.clear();
}

void Graph::addUndirectedEdge(Node *first, Node *second)
{
    if(!first || !second) return;
    
    first->adjacency[second] = 1;
    second->adjacency[first] = 1;
}

void Graph::removeUndirectedEdge(Node *first, Node *second)
{
    if(!first || !second) return;

    first->adjacency[second] = 0;
    second->adjacency[first] = 0;
    // auto it = first->adjacency.begin();
    // for(; it < first->adjacency.end(); it++)
    // {
    //     if(*it == second) break;
    // }

    // if(it < first->adjacency.end()) first->adjacency.erase(it);

    // it = second->adjacency.begin();
    // for(; it < second->adjacency.end(); it++)
    // {
    //     if(*it == first) break;
    // }

    // if(it < second->adjacency.end()) second->adjacency.erase(it);
}

/* --================= EXTRA FUNCTIONS ============-- */

void Graph::printAdjacency()
{
    for(auto &node : nodes)
    {
        printf("%s: ", node.first.c_str());
        for(auto &adj : node.second.adjacency)
        {
            printf("%s ", adj.first->value.c_str());
        }
        printf("\n");
    }
}