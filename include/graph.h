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

    void removeEdge(const Node *other)
    {
        auto it = adjacency.begin();
        for(; it != adjacency.end(); it++)
            if(it->first == other) break;

        if( it != adjacency.end() )
            adjacency.erase(it);
    }

    friend bool operator<(const Node &lhs, const Node &rhs)
    {
        if(lhs.value.length() == rhs.value.length())
            return lhs.value < rhs.value;
        else
            return lhs.value.length() < rhs.value.length();
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &node)
    {
        os << node.value;
        return os;
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