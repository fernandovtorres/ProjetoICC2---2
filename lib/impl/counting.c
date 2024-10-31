#include "../counting.h"
#include <stdlib.h>

Data countingSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  int *countingArray, *arrayCopy;
  countingArray = calloc(size, sizeof(int));
  arrayCopy = malloc(size * sizeof(int));

  for (int i = 1; i < size; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (array[i] < array[j]) {
        countingArray[j]++;
      } else {
        countingArray[i]++;
      }
      data.numberOfComparisons++;
    }
  }

  for (int i = 0; i < size; i++) {
    arrayCopy[countingArray[i]] = array[i];
  }

  free(countingArray);
  countingArray = NULL;

  for (int i = 0; i < size; i++) {
    array[i] = arrayCopy[i];
    data.numberOfSwaps++;
  }

  free(arrayCopy);
  arrayCopy = NULL;

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}
