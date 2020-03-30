#ifndef _GRAPH_SEARCH_H_
#define _GRAPH_SEARCH_H_

#include <vector>

#include "graph.h"

class GraphSearch
{
public:
    std::vector<Node> DFSRec(const Node &start, const Node &end);
    std::vector<Node> DFSIter(const Node &start, const Node &end);
    std::vector<Node> BFTRec(const Graph &graph);
    std::vector<Node> BFTIter(const Graph &graph);

private:
    void DFSRecHelp(std::vector<Node> &path, std::map<std::string, bool> &visited, std::vector<Node> &stack, std::string end);
    void BFTRecHelp(const Graph &graph, std::vector<Node> &path, std::vector<Node> &queue, std::map<std::string, bool> &visited);
};

#endif