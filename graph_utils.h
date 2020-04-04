#ifndef _GRAPH_UTILS_H_
#define _GRAPH_UTILS_H_

#include <vector>

#define ENQUEUE_NODE_PRINT(node) (printf("enqueue %s\n", node.value.c_str()))
template<class T>
void enqueue(std::vector<T> &dst, const T val)
{
    dst.insert(dst.begin(), val);
}

template<class T>
T dequeue(std::vector<T> &queue)
{
    T ret = queue.back();
    queue.pop_back();
    return ret;
}

#endif