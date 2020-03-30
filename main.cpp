#include <iostream>
#include <random>
#include <ctime>

#include "graph.h"
#include "graph_search.h"

#define EDGE_CHANCE 0.1f
#define NUM_NODES 10

Graph createRandomUnweightedGraphIter(int n);
Graph createLinkedList(int n);
std::string createString(int i);

int main(int argc, char *argv[])
{
    Graph graph = createRandomUnweightedGraphIter(NUM_NODES);
    // Graph graph = createLinkedList(NUM_NODES);
    graph.printAdjacency();
    auto nodes = graph.getAllNodes();

    GraphSearch search = GraphSearch(graph);

    std::srand( std::time(nullptr) );
    int startNum = std::rand() % (NUM_NODES-1);
    int endNum = -1;

    do
    {
        endNum = std::rand() % NUM_NODES;
    } while(startNum >= endNum);

    std::string start = createString( startNum );
    std::string end = createString( endNum );

    // auto dfs = search.DFSIter( nodes[start], nodes[end] );
    // auto dfs = search.DFSRec( nodes[start], nodes[end] );
    auto dfs = search.BFSRec( graph );
    printVector(dfs);

    return 0;
}

void printVector(std::vector<Node> vec)
{
    for(auto &node : vec)
    {
        printf("%s ", node.value.c_str());
    }
    printf("\n");
}

std::string createString(int i)
{
    std::string ret;
    char range = 'Z' - 'A' + 1;                                 // + 1 to include the z
    int shifted = 0;

    while(i > -1)
    {
        ret += 'A' + (i - shifted) % range;
        i /= range;
        if(i == 0) break;

        shifted = 1;
    }

    // printf("new string %s\n", ret.c_str());

    return ret;
}

Graph createRandomUnweightedGraphIter(int n)
{
    Graph graph = {};

    std::srand( std::time(nullptr) );

    for(int i = 0; i < n; i++)
    {
        std::string nodeVal = createString(i);
        graph.addNode( nodeVal );
        auto nodes = graph.getAllNodes();
        unsigned long count = nodes.size();
        
        Node &newNode = nodes[nodeVal];

        for(auto &node : nodes)
        {
            if(node.first == nodeVal) continue;
            if( ((float)(std::rand() % count) / (float)(count)) <= EDGE_CHANCE )
            {
                graph.addUndirectedEdge(newNode, (node.second));
            }
        }
    }
    return graph;
}

Graph createLinkedList(int n)
{
    Graph graph = {};

    std::srand( std::time(nullptr) );

    for(int i = 0; i < n; i++)
    {
        std::string nodeVal = createString(i);
        graph.addNode( nodeVal );

        if(i == 0) continue;

        auto nodes = graph.getAllNodes();
        Node &newNode = nodes[nodeVal];

        auto it = nodes.find(createString(i -  1));

        if(it != nodes.end())
        {
            Node &prev = it->second;
            graph.addDirectedEdge(prev, newNode);
        }

    }

    return graph;
}