#include "min_heap.h"
#include "main.h"

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
        
        for(auto &other : nodes)
        {
            if(other.first == nodeVal) continue;
            if( (float)(std::rand() % numNodes) / (float)(numNodes) <= EDGE_CHANCE )
            {
                /* make sure you don't create a cycle by linking the nodes */
                auto cycle = search.DFSIter(other.second, nodeVal);
                if(cycle.empty())
                    graph.addDirectedEdge(&nodes[nodeVal], &other.second);
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

typedef std::pair<Node*, int> HeapPair;

template<class T>
struct HeapPairCmpLess
{
    bool operator()(T lhs, T rhs) { return lhs.second < rhs.second; }
};

std::map<Node*, int> dijkstras(Node *start)
{
    std::map<Node*, int> ret;
    std::map<Node*, bool> visited;
    std::map<Node*, Node*> parents;
    Node *cur = start;
    MinHeap<HeapPair, HeapPairCmpLess<HeapPair>> heap = MinHeap<HeapPair, HeapPairCmpLess<HeapPair>>();

    if(!start) return ret;

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
                heap.insert( HeapPair(n.first, distance) );
            }
            /* we haven't seen this node before */
            else
            {
                parents[n.first] = cur;
                ret[n.first] = distance;
                heap.insert( HeapPair(n.first, distance) );
            }
        }

        visited[cur] = true;

        /* select new cur */
        Node *min = nullptr;
        do
        {
            min = heap.extractMin().first;
        } while( min && visited[min] );
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

void checkAndAddEdge(vec2d initial, vec2d offset, GridGraph &graph, GridNode &first, std::map<vec2d, GridNode> &nodes, int n)
{
    vec2d temp = initial;
    /* add offset to temp */
    temp.x += offset.x; 
    temp.y += offset.y;

    /* make sure the position is within the graph */
    if( (temp.x > -1 && temp.x < n) &&
        (temp.y > -1 && temp.y < n))
    {
        createRandomUndirectedEdge(graph, first, nodes[temp]);
    }
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

        checkAndAddEdge(node.first, {-1, 0}, graph, node.second, nodes, n);
        checkAndAddEdge(node.first, {1, 0}, graph, node.second, nodes, n);
        checkAndAddEdge(node.first, {0, -1}, graph, node.second, nodes, n);
        checkAndAddEdge(node.first, {0, 1}, graph, node.second, nodes, n);
    }

    return graph;
}

void createRandomUndirectedEdge(GridGraph &graph, GridNode &first, GridNode &second)
{
    bool p = std::rand() % 2 == 0;
    if(p) return;

    graph.addUndirectedEdge(&first, &second);
}

typedef std::pair<GridNode*, int> AStarHeapPair;

int heuristic(GridNode *node, GridNode *destNode)
{
    return std::max(
        std::abs( node->position.x - destNode->position.x ), 
        std::abs( node->position.y - destNode->position.y )
    );
}

std::vector<GridNode*> astar(GridNode *sourceNode, GridNode *destNode)
{
    std::vector<GridNode*> ret;
    std::map<GridNode*, bool> visited;
    std::map<GridNode*, int> d;
    std::map<GridNode*, GridNode*> par;
    std::map<GridNode*, int> h;
    MinHeap<AStarHeapPair, HeapPairCmpLess<AStarHeapPair>> heap = MinHeap<AStarHeapPair, HeapPairCmpLess<AStarHeapPair>>();

    if(!sourceNode || !destNode) return ret;

    GridNode *cur = sourceNode;
    d[destNode] = 0;
    h[destNode] = 0;
    par[cur] = nullptr;
    
    do
    {
        for(auto node : cur->adjacency)
        {
            if(visited[node.first]) continue;

            int distance = d[cur] + node.second;

            if(par[node.first])
            {
                if( d[node.first] < distance ) continue;

                par[node.first] = cur;
                d[node.first] = distance;
                heap.insert( AStarHeapPair( node.first, distance + h[node.first] ) );
            }
            else
            {
                /* the max is to include diagonals */
                h[node.first] = heuristic(node.first, destNode);
                
                par[node.first] = cur;
                d[node.first] = distance;
                heap.insert( AStarHeapPair( node.first, distance + h[node.first] ) );
            }
        }

        visited[cur] = true;
        GridNode *min = nullptr;
        do
        {
            min = heap.extractMin().first;
        } while(min && visited[min]);
        cur = min;
    } while(cur != destNode && cur != nullptr);
    
    if(cur != nullptr) 
    {
        do{
            enqueue(ret, cur);
            cur = par[cur];
        } while(cur != nullptr);
    }

    return ret;
}

void createGraphAndSearch(Graph g, int8_t funcBits)
{
    g.printAdjacency();
    auto &nodes = g.getAllNodes();

    GraphSearch search = {};

    if(funcBits & FUNC_BITS_BFT_REC)
    {
        std::vector<Node> dfs = search.BFTRec( g );
        printVector(dfs);
        return;
    }
    if(funcBits & FUNC_BITS_BFT_ITER)
    {
        std::vector<Node> dfs = search.BFTIter( g );
        printVector(dfs);
        return;
    }

    std::srand( std::time(nullptr) );
    int startNum = std::rand() % (NUM_NODES-1);
    int endNum = -1;

    do
    {
        endNum = std::rand() % NUM_NODES;
    } while(startNum >= endNum);

    std::string start = CREATE_STRING(startNum);
    std::string end = CREATE_STRING(endNum);

    printf("start: %s\tend: %s\n", start.c_str(), end.c_str());
    if(funcBits & FUNC_BITS_DFS_REC)
    {
        std::vector<Node> dfs = search.DFSRec( nodes[start], nodes[end] );
        printVector(dfs);
    }
    if(funcBits & FUNC_BITS_DFS_ITER)
    {
        std::vector<Node> dfs = search.DFSIter( nodes[start], nodes[end] );
        printVector(dfs);
    }
}