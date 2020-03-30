#include "graph_search.h"

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

    printf("start: %s\t\tend: %s\n", start.value.c_str(), end.value.c_str());

    stack.push_back(start);
    DFSRecHelp(ret, visited, stack, end.value);
    if(ret.back().value != end.value) ret.clear();

    return ret;
}

void GraphSearch::DFSRecHelp(std::vector<Node>& path, std::map<std::string, bool> &visited, std::vector<Node> &stack, std::string end)
{
    if(stack.empty()) return;

    Node &v = stack.back();
    stack.pop_back();

    if( visited[v.value] ) return;
    visited[v.value] = true;

    path.push_back(v);
    if( v.value == end ) 
    {
        return;
    }

    auto &nodes = graph.getAllNodes();
    int count = 0;
    for(auto &edge : graph.adjacency[v.value])
    {
        stack.push_back(nodes[edge]);
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
    
    printf("start: %s\t\tend: %s\n", start.value.c_str(), end.value.c_str());

    std::vector<Node> path;
    std::vector<Node> stack;
    auto &nodes = graph.getAllNodes();
    std::map<std::string, bool> visited;

    stack.push_back( nodes[ start.value ] );

    while(!stack.empty())
    {
        Node &v = stack.back();
        stack.pop_back();

        if(visited[v.value]) continue;
        visited[v.value] = true;

        path.push_back( v );
        if(v.value == end.value) break;

        for(auto &n : graph.adjacency[v.value])
        {
            stack.push_back(nodes[n]);
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
#define ENQUEUE_NODE_PRINT(node) (printf("enqueue %s\n", node.value.c_str()))
template<class T>
void enqueue(std::vector<T> &dst, const T val)
{
    dst.insert(dst.begin(), val);
}

template<class T>
Node dequeue(std::vector<T> &queue)
{
    Node ret = queue.back();
    queue.pop_back();
    return ret;
}

std::vector<Node> GraphSearch::BFSRec(const Graph &graph)
{
    std::vector<Node> ret;
    std::vector<Node> queue;
    std::map<std::string, bool> visited;
    this->graph = graph;

    // ENQUEUE_NODE_PRINT(graph.nodes.begin()->second);
    enqueue(queue, graph.nodes.begin()->second);
    BFSRecHelp(ret, queue, visited);

    return ret;
}

void GraphSearch::BFSRecHelp(std::vector<Node> &path, std::vector<Node> &queue, std::map<std::string, bool> &visited)
{
    if(queue.empty()) return;

    Node v = dequeue(queue);

    if(visited[v.value]) return;
    visited[v.value] = true;

    path.push_back(v);

    int count = graph.adjacency[ v.value ].size();
    for(auto node : graph.adjacency[v.value])
    {
        // ENQUEUE_NODE_PRINT(graph.nodes[node]);
        enqueue(queue, graph.nodes[node]);
    }

    for(int i = 0; i < count; i++)
    {
        BFSRecHelp(path, queue, visited);
    }

    while(path.size() != graph.nodes.size())
    {
        for(auto node : graph.nodes)
        {
            if(visited[node.second.value]) continue;

            // ENQUEUE_NODE_PRINT(node.second);
            enqueue(queue, node.second);
            BFSRecHelp(path, queue, visited);
            break;
        }
    }
}