#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 10;
    WeightedGraph g = createWeightedLinkedList(numNodes);
    g.printAdjacency();
    return 0;
}
