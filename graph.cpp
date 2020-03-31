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
    
    first->adjacency.push_back(second);
    second->adjacency.push_back(first);
}

void Graph::removeUndirectedEdge(Node *first, Node *second)
{
    if(!first || !second) return;

    auto it = first->adjacency.begin();
    for(; it < first->adjacency.end(); it++)
    {
        if(*it == second) break;
    }

    if(it < first->adjacency.end()) first->adjacency.erase(it);

    it = second->adjacency.begin();
    for(; it < second->adjacency.end(); it++)
    {
        if(*it == first) break;
    }

    if(it < second->adjacency.end()) second->adjacency.erase(it);
}

/* --================= EXTRA FUNCTIONS ============-- */

void Graph::addDirectedEdge(Node *start, Node *end)
{
    // printf("link %s to %s\n", start.value.c_str(), end.value.c_str());
    start->adjacency.push_back(end);
}

void Graph::printAdjacency()
{
    for(auto &node : nodes)
    {
        printf("%s: ", node.first.c_str());
        for(auto &adj : node.second.adjacency)
        {
            printf("%s ", adj->value.c_str());
        }
        printf("\n");
    }
}