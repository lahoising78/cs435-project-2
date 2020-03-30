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