#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 10;
    DirectedGraph g = createRandomDAGIter(numNodes);
    g.printAdjacency();
    auto khan = TopSort::Kahns( &g );
    printVector(khan);
    return 0;
}
