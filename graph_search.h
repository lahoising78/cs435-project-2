#ifndef _GRAPH_SEARCH_H_
#define _GRAPH_SEARCH_H_

#include <vector>

#include "graph.h"

class GraphSearch
{
public:
    GraphSearch() { this->graph = {}; }
    GraphSearch( Graph graph ) { this->graph = graph; }

    std::vector<Node> DFSRec(const Node &start, const Node &end);
    std::vector<Node> DFSIter(const Node &start, const Node &end);

private:
    void DFSRecHelp(std::vector<Node>& path, std::map<std::string, bool> &visited, std::vector<Node> &stack, std::string end);

private:
    Graph graph;
};

#endif