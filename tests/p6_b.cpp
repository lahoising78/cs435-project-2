#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 3;
    GridGraph g = createRandomGridGraph(numNodes);
    g.printAdjacency();
    g.printGrid();
    return 0;
}
