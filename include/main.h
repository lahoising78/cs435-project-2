#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <random>
#include <ctime>

#include "graph.h"
#include "graph_search.h"
#include "directed_graph.h"
#include "top_sort.h"
#include "weighted_graph.h"
#include "grid_graph.h"
#include "graph_utils.h"

#define EDGE_CHANCE 0.1f
#define NUM_NODES 5
#define MAX_WEIGHT 10

Graph createRandomUnweightedGraphIter(int n);
Graph createLinkedList(int n);

std::string createString(int i);

std::vector<Node> BFTRecLinkedList(const int numNodes);
std::vector<Node> BFTIterLinkedList(const int numNodes);

DirectedGraph createRandomDAGIter(const int numNodes);

WeightedGraph createRandomCompleteWeightedGraph(const int numNodes);
WeightedGraph createWeightedLinkedList(const int numNodes);

GridGraph createRandomGridGraph(const int n);
void createRandomUndirectedEdge(GridGraph &graph, GridNode &first, GridNode &second);

std::map<Node*, int> dijkstras(Node *start);
bool allVisited(std::map<Node*, bool> &visited);

std::vector<GridNode*> astar(GridNode *sourceNode, GridNode *destNode);

typedef enum
{
    A = 0,
    B, C, D, E, F, G
} StringToNumber;

#ifdef LETTER_NODES
    inline std::string CREATE_STRING(int i) { return createString(i); }     //nodes are labeled with letters
#else
    inline std::string CREATE_STRING(int i) { return std::to_string(i); }   //nodes are labeled with numbers
#endif

#endif

typedef enum
{
    FUNC_BITS_NONE      = 0,
    FUNC_BITS_DFS_ITER  = 1,
    FUNC_BITS_DFS_REC   = 2,
    FUNC_BITS_BFT_ITER  = 4,
    FUNC_BITS_BFT_REC   = 8
} FuncBits;
void createGraphAndSearch(Graph g, int8_t funcBits);