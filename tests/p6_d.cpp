#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 100;
    GridGraph g = createRandomGridGraph(numNodes);
    g.printAdjacency();
    g.printGrid();

    auto &nodes = g.getAllNodes();
    auto star = astar( &nodes[ {0, 0} ], &nodes[ {numNodes - 1, numNodes - 1} ] );
    printf("astar: ");
    for(const auto n : star)
    {
        printf("%s ", n->value.c_str());
    }
    printf("\n");
    
    return 0;
}
