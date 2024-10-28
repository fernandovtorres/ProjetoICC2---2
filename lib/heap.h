#ifndef HEAP_H
#define HEAP_H
#include "util.h"
Data heapSort(int *array, int size);
static void buildHeap(int *array, int size, int root, Data *data);
#endif
