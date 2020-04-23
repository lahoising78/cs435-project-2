#include "grid_graph.h"
#include <string.h>

void GridGraph::addGridNode(const int x, const int y, std::string nodeVal)
{
    GridNode node = GridNode(x, y, nodeVal);
    nodes[node.position] = node;
}

void GridGraph::addUndirectedEdge(GridNode *first, GridNode *second)
{
    if(!first || !second) return;

    if(!(first->position.x - second->position.x == 0) && !(first->position.y - second->position.y == 0)) return;

    first->adjacency[second] = 1;
    second->adjacency[first] = 1;
}

void GridGraph::removeUndirectedEdge(GridNode *first, GridNode *second)
{
    if(!first || !second) return;
    first->adjacency.erase( second );
    second->adjacency.erase(first);
}

void GridGraph::printAdjacency()
{
    for(auto &n : nodes)
    {
        printf("%s: ", n.second.value.c_str());
        for(auto &a : n.second.adjacency)
        {
            printf("(%s-%2d) ", a.first->value.c_str(), a.second);
        }
        printf("\n");
    }
}

void GridGraph::printGrid()
{
    vec2d max = {0, 0};
    int maxLen = 0;

    for(const auto &node : nodes)
    {
        if(node.second.position.x > max.x) max.x = node.second.position.x;
        if(node.second.position.y > max.y) max.y = node.second.position.y;
        if(node.second.value.length() > maxLen) maxLen = node.second.value.length();
    }

    /* account for spaces */
    maxLen++;
    max.x++; max.y++;
    max.x *= maxLen;
    max.y *= maxLen;

    char output[max.x * max.y / maxLen + 1];
    memset(output, ' ', sizeof(output));

    for(int i = 1; i <= max.y / maxLen; i++)
    {
        int s = i * max.x - 1;
        output[ s ] = '\n';
    }
    output[ sizeof(output) - 1 ] = '\0';

    for(auto &node : nodes)
    {
        int s = node.second.position.x * maxLen + node.second.position.y * max.x;
        memcpy( &output[s], node.second.value.c_str(), node.second.value.length() );
    }

    printf("%s", output);
}