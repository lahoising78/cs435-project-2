#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 10;
    FuncBits bits = FUNC_BITS_BFT_ITER;

    printf("linked list\n");
    createGraphAndSearch(
        createLinkedList(numNodes),
        bits
    );

    printf("\nrand unw graph\n");
    createGraphAndSearch(
        createRandomUnweightedGraphIter(numNodes),
        bits
    );

    return 0;
}
