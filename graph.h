#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <map>
#include <vector>

class GraphSearch;


class Node
{
public:
    std::string value;
    std::map<Node*, int> adjacency;

    Node() { value = ""; }
    Node(std::string val)
    {
        value = val;
    }
};

void printVector(std::vector<Node>);

class Graph
{
friend class GraphSearch;

public:
    void addNode(const std::string nodeVal);
    void addUndirectedEdge(Node *first, Node *second);
    void removeUndirectedEdge(Node *first, Node *second);
    std::map<std::string, Node> &getAllNodes() { return nodes; }

    void printAdjacency();

private:
    std::map<std::string, Node> nodes;
};

#endif