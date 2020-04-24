#include "top_sort.h"
#include "graph_utils.h"
#include <algorithm>

void enqueueZeroes(std::vector<Node> &queue, std::map<std::string, int> &inDegree, DirectedGraph *graph)
{
    auto &nodes = graph->getAllNodes();
    for(auto n : inDegree)
    {
        if(n.second == 0)
        {
            enqueue(queue, nodes[n.first]);
        }
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

        for(auto a : n.adjacency)
        {
            inDegree[a.first->value]--;
            if(inDegree[a.first->value] == 0)
            {
                enqueue(queue, nodes[a.first->value]);
            }
        }
    }

    return ret;
}

#ifdef REC
std::vector<Node> TopSort::mDFS(DirectedGraph *graph)
{
    std::vector<Node> ret;
    std::vector<Node> stack;
    std::map<std::string, bool> visited;

    auto &nodes = graph->getAllNodes();

    for(auto n : nodes)
    {
        if(!visited[n.first])
        {
            mDFSRec(n.second, stack, visited);
        }
    }

    std::reverse(stack.begin(), stack.end());

    return stack;
}

void TopSort::mDFSRec(Node v, std::vector<Node> &stack, std::map<std::string, bool> &visited)
{
    visited[v.value] = true;

    for(auto n : v.adjacency)
    {
        if(!visited[n.first->value])
        {
            mDFSRec(*n.first, stack, visited);
        }
    }

    stack.push_back(v);
}
#else
std::vector<Node> TopSort::mDFS(DirectedGraph *graph)
{
    std::vector<Node> ret;

    std::vector<Node> stack;
    std::vector<Node> dfs;
    std::map<std::string, bool> visited;

    auto &nodes = graph->getAllNodes();
    dfs.push_back( nodes.begin()->second );

    bool all = false;

    while(!dfs.empty() || !all)
    {
        /* if this is true, then we finished a path
        and we need to pick a new node so that we process
        all nodes in the end and not just a single node */
        if(dfs.empty())
        {
            for(auto &v : nodes)
            {
                if( !visited[v.first] )
                {
                    dfs.push_back(v.second);
                    break;
                }
            }
        }

        Node v = dfs.back();
        dfs.pop_back();

        if(visited[v.value]) continue;

        bool add = true;

        /* add neighbors to stack so we process them later */
        for(Node *n : v.adjacency)
        {
            if(!visited[n->value]) 
            {
                add = false;
                dfs.push_back(*n);
            }
        }

        /* 
        if we still have to process neighbors
        we need to process them first and then come back here
        */
        if(add)
        {
            stack.push_back(v);
            visited[v.value] = true;
        }

        all = (stack.size() == nodes.size());
    }

    /* empty stack into the array we will return */
    // while(!stack.empty())
    // {
    //     ret.push_back(stack.back());
    //     stack.pop_back();
    // }
    std::reverse(stack.begin(), stack.end());

    return stack;
}
#endif

void TopSort::calculateInDegree(DirectedGraph *graph, std::map<std::string, int> &dst)
{
    auto &nodes = graph->getAllNodes();

    for(auto n : nodes)
    {
        dst[n.second.value];
        for(auto a : n.second.adjacency)
        {
            dst[a.first->value]++;
        }
    }
}