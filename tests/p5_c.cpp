#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 10;
    WeightedGraph g = createRandomCompleteWeightedGraph(numNodes);
    g.printAdjacency();
    return 0;
}
