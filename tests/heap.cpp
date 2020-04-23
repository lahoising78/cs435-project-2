#include "main.h"
#include "min_heap.h"

typedef std::pair<Node, int> HeapMap;

std::ostream &operator<<(std::ostream &os, HeapMap pair)
{
    os << pair.first;
    return os;
}

struct HeapMapCmpLess
{
    bool operator()(HeapMap lhs, HeapMap rhs) { return lhs.second < rhs.second; }
};

void printCustom(std::vector<int> v)
{
    for(auto &node : v)
    {
        printf(" %d ", node);
    }
    printf("\n");
}

void printMap(std::vector< HeapMap > v)
{
    for(auto &node : v)
    {
        printf(" %s ", node.first.value.c_str());
    }
    printf("\n");
}

template< typename T, typename Cmp = std::less<T> >
void doHeapTest(MinHeap<T, Cmp> heap, const int total, const int rem, void (*printFunc)(std::vector<T>) )
{
    printFunc(heap.toVector());

    for(int i = 0; i < rem; i++ )
    {
        int index = std::rand() % heap.toVector().size() ;
        printf("remove %d\n", index);
        heap.remove(index);
        printFunc(heap.toVector());
    }

    std::cout << "min: " << heap.getMin() << std::endl;
    for(int i = 0; i < total - rem + 1; i++)
    {
        std::cout << "extract min " << heap.extractMin() << std::endl;
        printFunc(heap.toVector());
    }
}

int main(int argc, char const *argv[])
{
    const int total = 10;
    const int rem = 3;
    
    MinHeap< Node > heapNode = MinHeap< Node >();
    
    for(int i = total; i > 0; i--)
    {
        Node n( CREATE_STRING(i) );
        heapNode.insert(n);
    }

    doHeapTest<Node>(heapNode, total, rem, printVector);

    printf("\n\n=============WITH INT===========\n");

    MinHeap<int> heapInt = MinHeap<int>();
    for(int i = total; i > 0; i--)
        heapInt.insert(i);
    doHeapTest<int>(heapInt, total, rem, printCustom);

    printf("\n\n=============WITH KEY VAL PAIR===========\n");
    MinHeap< HeapMap, HeapMapCmpLess > heapMap = MinHeap< HeapMap, HeapMapCmpLess >();
    for(int i = total; i > 0; i--)
    {
        heapMap.insert( 
            HeapMap( 
                Node( CREATE_STRING(i) ), 
                i 
            ) 
        );
    }

    doHeapTest< HeapMap, HeapMapCmpLess >(heapMap, total, rem, printMap);

    return 0;
}
