#include "../heap.h"

Data heapSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  for(int i = (size / 2) - 1; i >= 0; i--){
    buildHeap(array, size, i, &data);
  }

  for(int i = size - 1; i > 0; i--){
    swap(&array[0], &array[i]);
    data.numberOfComparisons++;
    buildHeap(array, i, 0, &data);
  }

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;
  return data;
}

void buildHeap(int *array, int size, int root, Data *data){
  int max = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if (left < size && array[left] > array[max])
    max = left;

  if (right < size && array[right] > array[max])
    max = right;

  data->numberOfComparisons += 2;

  if (max != root) {
    swap(&array[root], &array[max]);
    data->numberOfSwaps++;
    buildHeap(array, size, max, data);
  }
}
