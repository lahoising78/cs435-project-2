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

    Node v = stack.back();
    stack.pop_back();

    if( visited[v.value] ) return;
    visited[v.value] = true;

    path.push_back(v);
    if( v.value == end ) 
    {
        return;
    }

    int count = 0;
    for(auto edge : v.adjacency)
    {
        stack.push_back(*edge);
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

// /*  
//     *****************
//     DFS ITER
//     ***************** 
// */
// std::vector<Node> GraphSearch::DFSIter(const Node &start, const Node &end)
// {
    
//     printf("start: %s\t\tend: %s\n", start.value.c_str(), end.value.c_str());

//     std::vector<Node> path;
//     std::vector<Node> stack;
//     std::map<std::string, bool> visited;

//     stack.push_back( start );

//     while(!stack.empty())
//     {
//         Node &v = stack.back();
//         stack.pop_back();

//         if(visited[v.value]) continue;
//         visited[v.value] = true;

//         path.push_back( v );
//         if(v.value == end.value) break;

//         for(auto &n : v.adjacency)
//         {
//             stack.push_back(n);
//         }
//     }

//     if(path.back().value != end.value) path.clear();

//     return path;
// }

// /* 
// ****************
// BFS REC
// ****************
// */
// #define ENQUEUE_NODE_PRINT(node) (printf("enqueue %s\n", node.value.c_str()))
// template<class T>
// void enqueue(std::vector<T> &dst, const T val)
// {
//     dst.insert(dst.begin(), val);
// }

// template<class T>
// Node dequeue(std::vector<T> &queue)
// {
//     Node ret = queue.back();
//     queue.pop_back();
//     return ret;
// }

// std::vector<Node> GraphSearch::BFTRec(const Graph &graph)
// {
//     std::vector<Node> ret;
//     std::vector<Node> queue;
//     std::map<std::string, bool> visited;

//     // ENQUEUE_NODE_PRINT(graph.nodes.begin()->second);
//     enqueue(queue, graph.nodes.begin()->second);
//     BFTRecHelp(graph, ret, queue, visited);

//     return ret;
// }

// void GraphSearch::BFTRecHelp(const Graph &graph, std::vector<Node> &path, std::vector<Node> &queue, std::map<std::string, bool> &visited)
// {
//     if(queue.empty()) return;

//     Node v = dequeue(queue);

//     if(visited[v.value]) return;
//     visited[v.value] = true;

//     path.push_back(v);

//     int count = v.adjacency.size();
//     for(auto node : v.adjacency)
//     {
//         // ENQUEUE_NODE_PRINT(graph.nodes[node]);
//         enqueue(queue, node);
//     }

//     for(int i = 0; i < count; i++)
//     {
//         BFTRecHelp(graph, path, queue, visited);
//     }

//     while(path.size() != graph.getAllNodes().size())
//     {
//         for(auto node : graph.nodes)
//         {
//             if(visited[node.second.value]) continue;

//             // ENQUEUE_NODE_PRINT(node.second);
//             enqueue(queue, node.second);
//             BFTRecHelp(graph, path, queue, visited);
//             break;
//         }
//     }
// }

// std::vector<Node> GraphSearch::BFTIter(const Graph &graph)
// {
//     this->graph = graph;

//     std::vector<Node> path;
//     std::vector<Node> queue;
//     auto &nodes = this->graph.getAllNodes();
//     std::map<std::string, bool> visited;

//     enqueue(queue, nodes.begin()->second);

//     while(!queue.empty())
//     {
//         Node v = dequeue(queue);

//         if(visited[v.value]) continue;
//         visited[v.value] = true;

//         path.push_back( v );

//         for(auto n : this->graph.adjacency[v.value])
//         {
//             if(!visited[n])
//                 enqueue(queue, nodes[n]);
//         }

//         if(queue.empty() && path.size() != nodes.size())
//         {
//             for(auto n : this->graph.nodes)
//             {
//                 if(visited[n.first]) continue;

//                 // ENQUEUE_NODE_PRINT(node.second);
//                 enqueue(queue, n.second);
//                 break;
//             }
//         }
//     }

//     return path;
// }