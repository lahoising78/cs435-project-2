#ifndef _GRID_GRAPH_H_
#define _GRID_GRAPH_H_

#include "graph.h"
#include <unordered_set>

typedef struct
{
    int x, y;
} vec2d;

class GridNode : public Node
{
public:
    vec2d position;

    GridNode() : Node() { position.x = position.y = -1; }

    GridNode(const int x, const int y, std::string nodeVal) 
        : Node(nodeVal)
    {
        position.x = x;
        position.y = y;
    }

    bool operator==(const GridNode &other) const 
    { 
        return value == other.value;
        // return position.x == other.position.x && position.y == other.position.y;
    }
};

class GridNodeHash
{
// private:
//     const vec2d primes = {73856093,  19349663};

public:
    size_t operator()(const GridNode &node) const
    {
        return (std::hash<int>()(node.position.x)) ^ (std::hash<int>()(node.position.y));
        // return (std::hash<int>()(node.position.x) * 73856093) ^ (std::hash<int>()(node.position.y) * 19349663);
    }
};

class GridGraph
{
public:
    void addGridNode(const int x, const int y, std::string nodeVal);
    void addUndirectedEdge(GridNode *first, GridNode *second);
    void removeUndirectedEdge(GridNode *first, GridNode *second);
    std::unordered_set<GridNode, GridNodeHash> &getAllNodes() { return nodes; }

    void printAdjacency();
    void printGrid();

private:
    std::unordered_set<GridNode, GridNodeHash> nodes;

};

#endif