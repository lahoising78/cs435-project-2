#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <vector>
#include <string>

template <typename T, typename Cmp = std::less<T> >
class MinHeap
{
private:
    std::vector<T> heap;
    Cmp cmp;

public:
    void insert(T val);
    void remove(int n);
    T getMin();
    T extractMin();

    MinHeap() { heap.clear(); }
    std::vector<T> toVector() { return heap; }

private:
    void swap(std::vector<T> &list, int firstIndex, int secondIndex);
    void heapifyUp(int index);
    void heapifyDown(int index);
    int getIndexOfLowestChild(int n);

    int parent(int index) { return (index - 1)/2; }
};

/* 
 * =========================================
 * IMPLEMENTATION
 * =========================================
*/
template <typename T, typename Cmp>
void MinHeap<T, Cmp>::insert(T val)
{
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

template <typename T, typename Cmp>
void MinHeap<T, Cmp>::remove(int n)
{
    swap(heap, n, heap.size() - 1);
    heap.pop_back();
    heapifyDown(n); 
}

template <typename T, typename Cmp>
T MinHeap<T, Cmp>::getMin()
{
    if(heap.size() < 1) return {};
    return heap[0];
}

template <typename T, typename Cmp>
T MinHeap<T, Cmp>::extractMin()
{
    if(heap.size() < 1) return {};
    T min = getMin();
    remove(0);
    return min;
}

template <typename T, typename Cmp>
void MinHeap<T, Cmp>::swap(std::vector<T> &list, int index1, int index2)
{
    T firstElement = list[index1];
    list[index1] = list[index2];
    list[index2] = firstElement;
}

template <typename T, typename Cmp>
void MinHeap<T, Cmp>::heapifyUp(int index)
{
    while ( cmp( heap[index], heap[parent(index)] ) ) {
        swap(heap, index, parent(index));
        index = parent(index);
    }
}

template <typename T, typename Cmp>
void MinHeap<T, Cmp>::heapifyDown(int n)
{
    int indexOfLowestChild = getIndexOfLowestChild(n);
    int current = n;

    while (indexOfLowestChild > -1) {
        swap(heap, current, indexOfLowestChild);
        current = indexOfLowestChild;
        indexOfLowestChild = getIndexOfLowestChild(current);
    }
}

template <typename T, typename Cmp>
int MinHeap<T, Cmp>::getIndexOfLowestChild(int n)
{
    int indexOfLowestChild = -1;

    int leftIndex = 2*n + 1;
    int rightIndex = 2*n + 2;

    if (leftIndex < heap.size() && cmp(heap[leftIndex], heap[n]) ) 
    {
        indexOfLowestChild = leftIndex;
    }

    if (rightIndex < heap.size() && cmp(heap[rightIndex], heap[n]) ) 
    {
        if(indexOfLowestChild == leftIndex)
        {
            if( cmp(heap[leftIndex], heap[rightIndex]) ) indexOfLowestChild = leftIndex;
            else indexOfLowestChild = rightIndex;
        }
        else
        {
            indexOfLowestChild = rightIndex;
        }
    }

    return indexOfLowestChild;
}


#endif