#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <map>
#include <vector>

class GraphSearch;


typedef struct node_s
{
    std::string value;
} Node;

void printVector(std::vector<Node>);

class Graph
{
friend class GraphSearch;

public:
    void addNode(const std::string nodeVal);
    void addUndirectedEdge(const Node &first, const Node &second);
    void removeUndirectedEdge(const Node &first, const Node &second);
    std::map<std::string, Node> &getAllNodes() { return nodes; }

    void addDirectedEdge(const Node &start, const Node &end);

    void printAdjacency();

private:
    std::map<std::string, Node> nodes;
    std::map<std::string, std::vector<std::string>> adjacency;
};

#endif