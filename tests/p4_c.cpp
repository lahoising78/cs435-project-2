#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 10;
    DirectedGraph g = createRandomDAGIter(numNodes);
    g.printAdjacency();
    return 0;
}
