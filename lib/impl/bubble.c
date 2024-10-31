#include "../bubble.h"

Data bubbleSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  for (int i = 0; i < size - 1; i++) {
    int swapped = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        swapped = 1;
        data.numberOfSwaps++;
      }
      data.numberOfComparisons++;
    }
    if (!swapped)
      break;
  }

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}
