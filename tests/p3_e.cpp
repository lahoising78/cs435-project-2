#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 10;
    FuncBits bit = FUNC_BITS_DFS_ITER;

    printf("rand unw graph\n");
    createGraphAndSearch(
        createRandomUnweightedGraphIter(numNodes),
        bit
    );

    printf("\nlinked list\n");
    createGraphAndSearch(
        createLinkedList(numNodes),
        bit
    );

    return 0;
}
