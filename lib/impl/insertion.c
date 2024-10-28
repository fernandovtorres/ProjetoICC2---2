#include "../insertion.h"

Data insertionSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  for (int i = 1; i < size; i++) {
    int actual = array[i];
    int j = i - 1;

    do {
      if (array[j] > actual) {
        array[j + 1] = array[j];
        j--;
        data.numberOfSwaps++;
      }
      data.numberOfComparisons++;
    } while (j >= 0);

    array[j + 1] = actual;
    data.numberOfSwaps++;
  }

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;
  return data;
}
