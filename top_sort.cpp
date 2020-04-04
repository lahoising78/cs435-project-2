#include "top_sort.h"
#include "graph_utils.h"

void enqueueZeroes(std::vector<Node> &queue, std::map<std::string, int> &inDegree, DirectedGraph *graph)
{
    auto &nodes = graph->getAllNodes();
    for(auto n : inDegree)
    {
        if(n.second == 0)
            enqueue(queue, nodes[n.first]);
    }
}

std::vector<Node> TopSort::Kahns(DirectedGraph *graph)
{
    std::vector<Node> ret;

    std::map<std::string, int> inDegree;
    calculateInDegree(graph, inDegree);

    std::vector<Node> queue;
    enqueueZeroes(queue, inDegree, graph);
    
    auto &nodes = graph->getAllNodes();
    while(!queue.empty())
    {
        Node n = dequeue(queue);
        ret.push_back(n);

        for(auto *a : n.adjacency)
        {
            inDegree[a->value]--;
            if(inDegree[a->value] == 0)
            {
                enqueue(queue, nodes[a->value]);
            }
        }
    }

    return ret;
}

std::vector<Node> TopSort::mDFS(DirectedGraph *graph)
{
    std::vector<Node> ret;

    return ret;
}

void TopSort::calculateInDegree(DirectedGraph *graph, std::map<std::string, int> &dst)
{
    auto &nodes = graph->getAllNodes();

    for(auto n : nodes)
    {
        dst[n.second.value];
        for(Node *a : n.second.adjacency)
        {
            dst[a->value]++;
        }
    }

    printf("{");    
    for(auto d : dst)
    {
        printf(" %s: %d ", d.first.c_str(), d.second);
    }
    printf("}\n");
}