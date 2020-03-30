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
    first->adjacency.push_back(second);
    second->adjacency.push_back(first);
}

// void Graph::removeUndirectedEdge(Node &first, Node &second)
// {

// }

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