#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 1000;
    DirectedGraph g = createRandomDAGIter(numNodes);
    g.printAdjacency();
    auto mdfs = TopSort::mDFS( &g );
    printVector(mdfs);
    return 0;
}