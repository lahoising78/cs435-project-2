#ifndef _TOP_SORT_H_
#define _TOP_SORT_H_

#include "directed_graph.h"

#define REC

class TopSort
{
public:
    static std::vector<Node> Kahns(DirectedGraph *graph);
    static std::vector<Node> mDFS(DirectedGraph *graph);

private:
    static void calculateInDegree(DirectedGraph *graph, std::map<std::string, int> &dst);

    #ifdef REC
    static void mDFSRec(Node v, std::vector<Node> &stack, std::map<std::string, bool> &visited);
    #endif
};

#endif