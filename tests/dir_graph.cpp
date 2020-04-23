#include "main.h"

void delEdge(DirectedGraph &graph, int firstIndex, int secondIndex, std::vector<std::string> nodeNames)
{
    if(firstIndex >= nodeNames.size() || secondIndex >= nodeNames.size()) return;
    auto &nodes = graph.getAllNodes();
    printf("delete edge %s -> %s\n", nodeNames[firstIndex].c_str(), nodeNames[secondIndex].c_str());
    graph.removeDirectedEdge( &nodes[ nodeNames[firstIndex] ], &nodes[ nodeNames[secondIndex] ] );
}

int main(int argc, char const *argv[])
{
    const int numNodes = 10;
    const int rem = 5;
    std::vector<std::string> nodeNames;
    DirectedGraph g = {};
    auto &nodes = g.getAllNodes();
    std::srand( std::time( nullptr ) );
    
    for(int i = 0; i < numNodes; i++)
    {
        nodeNames.push_back( CREATE_STRING(i) );
        g.addNode( nodeNames[i] );

        if(i > 0)
        {
            g.addDirectedEdge( &nodes[ nodeNames[i] ], &nodes[ nodeNames[i-1] ] );
            if( i > 1 && std::rand()%2 == 0 )
                g.addDirectedEdge( &nodes[ nodeNames[i] ], &nodes[ nodeNames[i-2] ] );
        }
    }
    g.printAdjacency();

    delEdge(g, 1, 0, nodeNames);
    delEdge(g, 6, 5, nodeNames);
    delEdge(g, 3, 2, nodeNames);
    delEdge(g, 3, 2, nodeNames);
    delEdge(g, 9, 2, nodeNames);

    g.printAdjacency();

    return 0;
}
