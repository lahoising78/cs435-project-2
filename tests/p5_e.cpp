#include "main.h"

int main(int argc, char const *argv[])
{
    printf("=======================WITH GRAPH FROM LECTURE 17==================");
    std::map<int, std::string> numToString;
    WeightedGraph g = WeightedGraph();
    for(int i = 0; i < 7; i++)
    {
        numToString[i] = CREATE_STRING(i);
        g.addNode( numToString[i] );
    }

    auto &nodes = g.getAllNodes();
    g.addWeightedEdge( &nodes[ numToString[A] ], &nodes[ numToString[B] ], 2 ); // A to B : 2
    g.addWeightedEdge( &nodes[ numToString[A] ], &nodes[ numToString[C] ], 4 ); // A to C : 4
    g.addWeightedEdge( &nodes[ numToString[A] ], &nodes[ numToString[D] ], 7 );
    g.addWeightedEdge( &nodes[ numToString[A] ], &nodes[ numToString[F] ], 5 );
    
    g.addWeightedEdge( &nodes[ numToString[B] ], &nodes[ numToString[A] ], 2 );
    g.addWeightedEdge( &nodes[ numToString[B] ], &nodes[ numToString[D] ], 6 );
    g.addWeightedEdge( &nodes[ numToString[B] ], &nodes[ numToString[E] ], 3 );
    g.addWeightedEdge( &nodes[ numToString[B] ], &nodes[ numToString[G] ], 8 );

    g.addWeightedEdge( &nodes[ numToString[C] ], &nodes[ numToString[A] ], 4 );
    g.addWeightedEdge( &nodes[ numToString[C] ], &nodes[ numToString[F] ], 6 );

    g.addWeightedEdge( &nodes[ numToString[D] ], &nodes[ numToString[A] ], 7 );
    g.addWeightedEdge( &nodes[ numToString[D] ], &nodes[ numToString[B] ], 6 );
    g.addWeightedEdge( &nodes[ numToString[D] ], &nodes[ numToString[F] ], 10 );
    g.addWeightedEdge( &nodes[ numToString[D] ], &nodes[ numToString[G] ], 6 );

    g.addWeightedEdge( &nodes[ numToString[E] ], &nodes[ numToString[B] ], 3 );
    g.addWeightedEdge( &nodes[ numToString[E] ], &nodes[ numToString[G] ], 7 );

    g.addWeightedEdge( &nodes[ numToString[F] ], &nodes[ numToString[A] ], 5 );
    g.addWeightedEdge( &nodes[ numToString[F] ], &nodes[ numToString[C] ], 6 );
    g.addWeightedEdge( &nodes[ numToString[F] ], &nodes[ numToString[D] ], 10 );

    g.addWeightedEdge( &nodes[ numToString[G] ], &nodes[ numToString[B] ], 8 );
    g.addWeightedEdge( &nodes[ numToString[G] ], &nodes[ numToString[D] ], 6 );
    g.addWeightedEdge( &nodes[ numToString[G] ], &nodes[ numToString[E] ], 7 );
    g.addWeightedEdge( &nodes[ numToString[G] ], &nodes[ numToString[F] ], 6 );

    g.printAdjacency();
    auto known = dijkstras( &nodes[ numToString[A] ] );
    for(auto n : known)
    {
        printf(" %s: %d ", n.first->value.c_str(), n.second);
    }
    printf("\n");

    printf("=======================WITH RANDOM COMPLETE WEIGHTED GRAPH==================");
    const int numNodes = 10;
    
    WeightedGraph dgraph = createRandomCompleteWeightedGraph(numNodes);
    dgraph.printAdjacency();
    
    std::srand( std::time(nullptr) );
    std::string start = CREATE_STRING( std::rand() % dgraph.getAllNodes().size() );
    printf("start: %s\n", start.c_str());
    
    auto dijks = dijkstras( &dgraph.getAllNodes()[start] );
    printf("dijkstras: { ");
    for(auto n : dijks)
    {
        if(!n.first) continue;
        printf(" %s: %d ", n.first->value.c_str(), n.second);
    }
    printf("}\n");

    return 0;
}
