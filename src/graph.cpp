#include <iostream>
#include "graph.h"

/* --========== problem functions ==========- */
void Graph::addNode(const std::string nodeVal)
{
    Node n(nodeVal);

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

    first->adjacency.erase(second);
    second->adjacency.erase(first);
}

/* --================= EXTRA FUNCTIONS ============-- */

void Graph::printAdjacency()
{
    for(auto &node : nodes)
    {
        printf("%s: ", node.first.c_str());
        for(auto &adj : node.second.adjacency)
        {
            printf("(%s-%2d) ", adj.first->value.c_str(), adj.second);
        }
        printf("\n");
    }
}