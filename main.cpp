#include <iostream>
#include <random>
#include <ctime>

#include "graph.h"
#include "graph_search.h"
#include "directed_graph.h"
#include "top_sort.h"
#include "weighted_graph.h"
#include "grid_graph.h"

#define EDGE_CHANCE 0.1f
#define NUM_NODES 5
#define MAX_WEIGHT 10
// #define CREATE_STRING(i) createString(i)                //nodes are labeled with letters
#define CREATE_STRING(i) std::to_string(i)           //nodes are labeled with numbers

#define BFT_LINKED_CREATE_AND_PRINT_REC(num) std::vector<Node> bft##num = BFTRecLinkedList(num); \
printf("\n%d\n", num); \
printVector(bft##num); \

#define BFT_LINKED_CREATE_AND_PRINT_ITER(num) std::vector<Node> bft##num = BFTIterLinkedList(num); \
printf("\n%d\n", num); \
printVector(bft##num); \

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

typedef enum
{
    A = 0,
    B, C, D, E, F, G
} StringToNumber;

int main(int argc, char *argv[])
{
    // Graph graph = createRandomUnweightedGraphIter(NUM_NODES);
    // Graph graph = createLinkedList(NUM_NODES);
    // graph.printAdjacency();
    // auto &nodes = graph.getAllNodes();

    // GraphSearch search = {};

    // std::srand( std::time(nullptr) );
    // int startNum = std::rand() % (NUM_NODES-1);
    // int endNum = -1;

    // do
    // {
    //     endNum = std::rand() % NUM_NODES;
    // } while(startNum >= endNum);

    // std::string start = CREATE_STRING(startNum);
    // std::string end = CREATE_STRING(endNum);

    // auto dfs = search.DFSRec( nodes[start], nodes[end] );
    // auto dfs = search.DFSIter( nodes[start], nodes[end] );
    // auto dfs = search.BFTRec( graph );
    // auto dfs = search.BFTIter( graph );
    // printVector(dfs);

    // BFT_LINKED_CREATE_AND_PRINT_REC(100)

    // BFT_LINKED_CREATE_AND_PRINT_REC(10000)

    // BFT_LINKED_CREATE_AND_PRINT_ITER(10000)

    // DirectedGraph dirGraph = createRandomDAGIter( NUM_NODES );
    // dirGraph.printAdjacency();

    // std::vector<Node> khan = TopSort::Kahns(&dirGraph);
    // printVector(khan);

    // std::vector<Node> dfs = TopSort::mDFS(&dirGraph);
    // printVector(dfs);

    // WeightedGraph weight = createRandomCompleteWeightedGraph(NUM_NODES);
    // weight.printAdjacency();

    // WeightedGraph weightList = createWeightedLinkedList(NUM_NODES);
    // weightList.printAdjacency();


    /**
     * @note test with a known graph (lecture 17 daily quiz) 
    WeightedGraph dgraph = {};
    for(int i = 0; i < 7; i++)
    {
        dgraph.addNode( CREATE_STRING(i) );
    }

    auto &nodes = dgraph.getAllNodes();
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(A) ], &nodes[CREATE_STRING(B)], 2 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(A) ], &nodes[CREATE_STRING(C)], 4 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(A) ], &nodes[CREATE_STRING(D)], 7 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(A) ], &nodes[CREATE_STRING(F)], 5 );

    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(B) ], &nodes[CREATE_STRING(A)], 2 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(B) ], &nodes[CREATE_STRING(D)], 6 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(B) ], &nodes[CREATE_STRING(E)], 3 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(B) ], &nodes[CREATE_STRING(G)], 8 );

    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(C) ], &nodes[CREATE_STRING(A)], 4 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(C) ], &nodes[CREATE_STRING(F)], 6 );

    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(D) ], &nodes[CREATE_STRING(A)], 7 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(D) ], &nodes[CREATE_STRING(B)], 6 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(D) ], &nodes[CREATE_STRING(F)], 10 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(D) ], &nodes[CREATE_STRING(G)], 6 );

    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(E) ], &nodes[CREATE_STRING(B)], 3 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(E) ], &nodes[CREATE_STRING(G)], 7 );

    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(F) ], &nodes[CREATE_STRING(A)], 5 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(F) ], &nodes[CREATE_STRING(C)], 6 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(F) ], &nodes[CREATE_STRING(D)], 10 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(F) ], &nodes[CREATE_STRING(G)], 6 );

    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(G) ], &nodes[CREATE_STRING(B)], 8 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(G) ], &nodes[CREATE_STRING(D)], 6 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(G) ], &nodes[CREATE_STRING(E)], 7 );
    dgraph.addWeightedEdge( &nodes[ CREATE_STRING(G) ], &nodes[CREATE_STRING(F)], 6 );

    std::string start = "A";
    */

    // WeightedGraph dgraph = createRandomCompleteWeightedGraph(NUM_NODES);
    // dgraph.printAdjacency();
    // std::srand( std::time(nullptr) );
    // std::string start = CREATE_STRING( std::rand() % dgraph.getAllNodes().size() );    
    // auto dijks = dijkstras( &dgraph.getAllNodes()[start] );

    // printf("dijkstras: { ");
    // for(auto n : dijks)
    // {
    //     if(!n.first) continue;
    //     printf(" %s: %d ", n.first->value.c_str(), n.second);
    // }
    // printf("}\n");

    auto grid = createRandomGridGraph(NUM_NODES);
    grid.printGrid();
    grid.printAdjacency();

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

    printf("new string %s\n", ret.c_str());

    return ret;
}

Graph createRandomUnweightedGraphIter(int n)
{
    Graph graph = {};

    std::srand( std::time(nullptr) );

    for(int i = 0; i < n; i++)
    {
        std::string nodeVal = CREATE_STRING(i);
        graph.addNode( nodeVal );
        auto &nodes = graph.getAllNodes();
        unsigned long count = nodes.size();
        
        Node *newNode = &nodes[nodeVal];

        for(auto &node : nodes)
        {
            if(node.first == nodeVal) continue;
            if( ((float)(std::rand() % count) / (float)(count)) <= EDGE_CHANCE )
            {
                graph.addUndirectedEdge(newNode, &node.second);
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
        std::string nodeVal = CREATE_STRING(i);
        graph.addNode( nodeVal );

        if(i == 0) continue;

        auto &nodes = graph.getAllNodes();
        Node *newNode = &nodes[nodeVal];

        auto it = graph.getAllNodes().find( CREATE_STRING(i - 1) );

        if(it != nodes.end())
        {
            Node *prev = &it->second;
            graph.addUndirectedEdge(prev, newNode);
        }

    }

    return graph;
}

std::vector<Node> BFTRecLinkedList(const int numNodes)
{
    Graph graph = createLinkedList(numNodes);
    GraphSearch search = {};

    return search.BFTRec(graph);
}

std::vector<Node> BFTIterLinkedList(const int numNodes)
{
    Graph graph = createLinkedList(numNodes);
    GraphSearch search = {};

    return search.BFTIter(graph);
}

DirectedGraph createRandomDAGIter(const int numNodes)
{
    DirectedGraph graph = {};
    GraphSearch search = {};

    std::srand( std::time(nullptr) );

    auto &nodes = graph.getAllNodes();

    /* populate graph */
    for(int i = 0; i < numNodes; i++)
    {
        std::string nodeVal = CREATE_STRING(i);
        graph.addNode( nodeVal );
    }

    /* create some edges */
    for(auto &node : nodes)
    {
        for(auto &other : nodes)
        {
            if(node.first == other.first) continue;

            if( (float)(std::rand() % numNodes) / (float)(numNodes) <= EDGE_CHANCE )
            {
                /* make sure you don't create a cycle by linking the nodes */
                auto cycle = search.DFSIter(other.second, node.second);
                if(cycle.empty())
                    graph.addDirectedEdge(&node.second, &other.second);
            }
        }
    }

    return graph;
}

WeightedGraph createRandomCompleteWeightedGraph(const int numNodes)
{
    WeightedGraph graph = {};

    std::srand( std::time(nullptr) );

    auto &nodes = graph.getAllNodes();

    /* create the nodes */
    for(int i = 0; i < numNodes; i++)
    {
        graph.addNode( CREATE_STRING(i) );
    }

    /* create edges */
    for(auto &node : nodes)
    {
        for(auto &other : nodes)
        {
            if(node.first == other.first) continue;
            graph.addWeightedEdge(&node.second, &other.second, (std::rand() % MAX_WEIGHT) + 1);
        }
    }

    return graph;
}

#define DEFAULT_WEIGHT 1
WeightedGraph createWeightedLinkedList(const int numNodes)
{
    WeightedGraph graph = {};
    auto &nodes = graph.getAllNodes();

    graph.addNode( CREATE_STRING(0) );
    for(int i = 1; i < numNodes; i++)
    {
        std::string cur = CREATE_STRING(i);
        graph.addNode(cur);

        std::string prev = CREATE_STRING(i-1);

        graph.addWeightedEdge( &nodes[prev], &nodes[cur], DEFAULT_WEIGHT );
    }

    return graph;
}

std::map<Node*, int> dijkstras(Node *start)
{
    std::map<Node*, int> ret;
    std::map<Node*, bool> visited;
    std::map<Node*, Node*> parents;
    Node *cur = start;

    if(!start) return ret;

    printf("start %s\n", start->value.c_str());

    ret[start] = 0;

    do
    {
        for(auto n : cur->adjacency)
        {
            /* make sure all values are in the map. default is false */
            if(visited[n.first]) continue;

            int distance = ret[cur] + n.second;
            /* we have calculated a distance already */
            if(parents[n.first])
            {
                if(distance > ret[n.first]) continue;
                ret[n.first] = distance;
                parents[n.first] = cur;
            }
            /* we haven't seen this node before */
            else
            {
                parents[n.first] = cur;
                ret[n.first] = distance;
            }
        }

        visited[cur] = true;

        /* select new cur */
        Node *min = nullptr;
        for(auto n : ret)
        {
            if(visited[n.first]) continue;

            if(!min) min = n.first;
            else if(ret[min] > n.second) min = n.first;
        }
        cur = min;
    } while (cur != nullptr);
    

    return ret;
}

bool allVisited(std::map<Node*, bool> &visited)
{
    for(auto n : visited)
    {
        if(!n.second) return false;
    }

    return true;
}

GridGraph createRandomGridGraph(const int n)
{
    GridGraph graph = {};

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            graph.addGridNode(x, y, CREATE_STRING(x + y * n));
        }
    }

    auto &nodes = graph.getAllNodes();

    std::srand( std::time(nullptr) );

    bool skip = true;
    for(auto &node : nodes)
    {
        /* to make sure we dont try to add edges several times per node. we are skipping adjacent nodes with this */
        if(n % 2 == 0)
        {
            if(node.first.x != 0)
                skip = !skip;
        }
        else
        {
            skip = !skip;
        }

        if(skip)
        {
            continue;
        }

        vec2d temp = node.first;
        temp.x -= 1;
        if(temp.x > -1)
        {
            createRandomUndirectedEdge(graph, node.second, nodes[temp] );
            // printf("node %s\n", node.second.value.c_str());
            // printf("node %s\n", nodes[temp].value.c_str());
        }

        temp = node.first;
        temp.x += 1;
        if(temp.x < n)
            createRandomUndirectedEdge(graph, node.second, nodes[temp] );

        temp = node.first;
        temp.y -= 1;
        if(temp.y > -1)
            createRandomUndirectedEdge(graph, node.second, nodes[temp] );

        temp = node.first;
        temp.y += 1;
        if(temp.y < n)
            createRandomUndirectedEdge(graph, node.second, nodes[temp] );
    }

    return graph;
}

void createRandomUndirectedEdge(GridGraph &graph, GridNode &first, GridNode &second)
{
    bool p = !(std::rand() % 2);
    // printf("p = %d\n", p);
    if(p) return;

    graph.addUndirectedEdge(&first, &second);
}