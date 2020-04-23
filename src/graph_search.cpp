#include "graph_search.h"
#include "graph_utils.h"

/*  
    **********************
    DFS REC
    ********************** 
*/
std::vector<Node> GraphSearch::DFSRec(const Node &start, const Node &end)
{
    std::vector<Node> ret;
    std::map<std::string, bool> visited;
    std::vector<Node> stack;

    stack.push_back(start);
    DFSRecHelp(ret, visited, stack, end.value);
    if(ret.back().value != end.value) ret.clear();

    return ret;
}

void GraphSearch::DFSRecHelp(std::vector<Node>& path, std::map<std::string, bool> &visited, std::vector<Node> &stack, std::string end)
{
    if(stack.empty()) return;

    Node curr = stack.back();
    stack.pop_back();

    if( visited[curr.value] ) return;
    visited[curr.value] = true;

    path.push_back(curr);
    if( curr.value == end ) 
    {
        return;
    }

    int count = 0;
    for(auto edge : curr.adjacency)
    {
        stack.push_back(*edge.first);
        count++;
    }
    
    for(int i = 0; i < count; i++)
    {
        DFSRecHelp(path, visited, stack, end);
        if(path.back().value == end)
        {
            return;
        }
    }
}

/*  
    *****************
    DFS ITER
    ***************** 
*/
std::vector<Node> GraphSearch::DFSIter(const Node &start, const Node &end)
{
    
    std::vector<Node> path;
    std::vector<Node> stack;
    std::map<std::string, bool> visited;

    stack.push_back( start );

    while(!stack.empty())
    {
        Node curr = stack.back();
        stack.pop_back();

        if(visited[curr.value]) continue;
        visited[curr.value] = true;

        path.push_back( curr );
        if(curr.value == end.value) break;

        for(auto node : curr.adjacency)
        {
            stack.push_back(*node.first);
        }
    }

    if(path.back().value != end.value) path.clear();

    return path;
}

/* 
****************
BFS REC
****************
*/
std::vector<Node> GraphSearch::BFTRec(const Graph &graph)
{
    std::vector<Node> ret;
    std::vector<Node> queue;
    std::map<std::string, bool> visited;

    // ENQUEUE_NODE_PRINT(graph.nodes.begin()->second);
    enqueue(queue, graph.nodes.begin()->second);
    BFTRecHelp(graph, ret, queue, visited);

    return ret;
}

void GraphSearch::BFTRecHelp(const Graph &graph, std::vector<Node> &path, std::vector<Node> &queue, std::map<std::string, bool> &visited)
{
    if(queue.empty()) return;

    Node curr = dequeue(queue);

    if(visited[curr.value]) return;
    visited[curr.value] = true;

    path.push_back(curr);

    int count = curr.adjacency.size();
    for(auto node : curr.adjacency)
    {
        enqueue(queue, *node.first);
    }

    for(int i = 0; i < count; i++)
    {
        BFTRecHelp(graph, path, queue, visited);
    }

    while(path.size() != graph.nodes.size())
    {
        for(auto node : graph.nodes)
        {
            if(visited[node.second.value]) continue;

            enqueue(queue, node.second);
            BFTRecHelp(graph, path, queue, visited);
            break;
        }
    }
}

/* 
*************************
BFT ITER
*************************
*/
std::vector<Node> GraphSearch::BFTIter(const Graph &graph)
{
    std::vector<Node> path;
    std::vector<Node> queue;
    auto &nodes = graph.nodes;
    std::map<std::string, bool> visited;

    enqueue(queue, nodes.begin()->second);

    while(!queue.empty())
    {
        Node curr = dequeue(queue);

        if(visited[curr.value]) continue;
        visited[curr.value] = true;

        path.push_back( curr );

        for(auto nodeKeyValue : curr.adjacency)
        {
            if(!visited[nodeKeyValue.first->value])
                enqueue(queue, *nodeKeyValue.first);
        }

        if(queue.empty() && path.size() != nodes.size())
        {
            for(auto nodeKeyValue : graph.nodes)
            {
                if(visited[nodeKeyValue.first]) continue;

                // ENQUEUE_NODE_PRINT(node.second);
                enqueue(queue, nodeKeyValue.second);
                break;
            }
        }
    }

    return path;
}