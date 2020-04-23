#include "main.h"

int main(int argc, char const *argv[])
{
    Graph g = createRandomUnweightedGraphIter(10);
    g.printAdjacency();

    return 0;
}
