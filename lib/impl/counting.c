#include "../counting.h"
#include <stdlib.h>

Data countingSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  int maxNumber = 0;
  for (int i = 0; i < size; i++)
    maxNumber = maxBetween(maxNumber, array[i]);

  int *countingArray = calloc(maxNumber + 1, sizeof(int));
  int *arrayCopy = malloc(size * sizeof(int));

  if (!countingArray || !arrayCopy) {
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < size; i++) {
    countingArray[array[i]]++;
  }

  for (int i = 1; i <= maxNumber; i++) {
    countingArray[i] += countingArray[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    arrayCopy[countingArray[array[i]] - 1] = array[i];
    countingArray[array[i]]--;
  }

  free(countingArray);
  countingArray = NULL;

  for (int i = 0; i < size; i++) {
    array[i] = arrayCopy[i];
  }

  free(arrayCopy);
  arrayCopy = NULL;

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}
