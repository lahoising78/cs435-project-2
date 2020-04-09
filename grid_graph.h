#ifndef _GRID_GRAPH_H_
#define _GRID_GRAPH_H_

#include "graph.h"
#include <unordered_map>

typedef struct vec2d_t
{
    int x, y;

    bool operator==(const vec2d_t &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator<(const vec2d_t &other) const
    {
        if(other.y == y) return x < other.x;
        else return y < other.y;
    }
} vec2d;

class Vec2dHash
{
public:
    size_t operator()(const vec2d &vec) const
    {
        return (std::hash<int>()(vec.x)) ^ (std::hash<int>()(vec.y));
        // return (std::hash<int>()(node.position.x) * 73856093) ^ (std::hash<int>()(node.position.y) * 19349663);
    }
};

class GridNode
{
public:
    vec2d position;
    std::string value;
    std::unordered_map<GridNode*, int> adjacency;

    GridNode() { position.x = position.y = -1; }

    GridNode(const int x, const int y, std::string nodeVal)
    {
        position.x = x;
        position.y = y;
        value = nodeVal;
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
    // std::map<vec2d, GridNode, Vec2dHash> &getAllNodes() { return nodes; }
    std::map<vec2d, GridNode> &getAllNodes() { return nodes; }

    void printAdjacency();
    void printGrid();

private:
    // std::map<vec2d, GridNode, Vec2dHash> nodes;
    std::map<vec2d, GridNode> nodes;

};

#endif