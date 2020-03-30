#include <iostream>
#include "graph.h"

/* --========== problem functions ==========- */
void Graph::addNode(const std::string nodeVal)
{
    Node n = {};
    n.value = nodeVal;

    nodes[nodeVal] = n;
    adjacency[nodeVal].clear();
}

void Graph::addUndirectedEdge(const Node &first, const Node &second)
{
    adjacency[first.value].push_back(second.value);
    adjacency[second.value].push_back(first.value);
}

void Graph::removeUndirectedEdge(const Node &first, const Node &second)
{

}

/* --================= EXTRA FUNCTIONS ============-- */

void Graph::addDirectedEdge(const Node &start, const Node &end)
{
    // printf("link %s to %s\n", start.value.c_str(), end.value.c_str());
    adjacency[start.value].push_back(end.value);
}

void Graph::printAdjacency()
{
    for(auto &node : adjacency)
    {
        printf("%s: ", node.first.c_str());
        for(auto &adj : node.second)
        {
            printf("%s ", adj.c_str());
        }
        printf("\n");
    }
}