#include "main.h"

int main(int argc, char const *argv[])
{
    const int numNodes = 10;

    printf("linked list\n");
    createGraphAndSearch( 
        createLinkedList(numNodes),
        FUNC_BITS_DFS_REC
    );

    printf("\nrand unweighted graph iter\n");
    createGraphAndSearch( 
        createRandomUnweightedGraphIter(numNodes),
        FUNC_BITS_DFS_REC
    );

    return 0;
}
