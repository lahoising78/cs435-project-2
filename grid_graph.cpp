#include "grid_graph.h"
#include <string.h>

void GridGraph::addGridNode(const int x, const int y, std::string nodeVal)
{
    GridNode node = GridNode(x, y, nodeVal);
    // printf("insert grid node: %d\n", nodes.insert(node).second);
    nodes.insert(node);
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
        printf("%s: ", n.value.c_str());
        for(auto &a : n.adjacency)
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

    // printf("for each node: \n");
    // int i = 0;
    for(const auto &node : nodes)
    {
        // printf("node ");
        if(node.position.x > max.x) max.x = node.position.x;
        if(node.position.y > max.y) max.y = node.position.y;
        if(node.value.length() > maxLen) maxLen = node.value.length();
        // i++;
    }

    // printf("\nyes %d\n", i);
    /* account for spaces */
    maxLen++;
    max.x++; max.y++;
    max.x *= maxLen;
    max.y *= maxLen;
    // printf("len %d, max x %d, max y %d\n", maxLen, max.x, max.y);

    char output[max.x * max.y / maxLen + 1];
    memset(output, ' ', sizeof(output));

    // printf("set the new lines\n");
    for(int i = 1; i <= max.y / maxLen; i++)
    {
        int s = i * max.x - 1;
        output[ s ] = '\n';
        // printf("set new line at %d\n", s);
    }
    output[ sizeof(output) - 1 ] = '\0';

    // printf("copy what you must\n");
    for(auto &node : nodes)
    {
        int s = node.position.x * maxLen + node.position.y * max.x;
        memcpy( &output[s], node.value.c_str(), node.value.length() );
        // printf("copy %lu characters at %d\n", node.value.length(), s);
    }

    printf("%s", output);
}