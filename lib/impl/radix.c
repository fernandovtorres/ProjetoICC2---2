#include "../radix.h"
#include <stdlib.h>

Data radixSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  int maxNumber = 0;
  for(int i = 0; i < size; i++){
    maxNumber = maxBetween(maxNumber, array[i]);
  }

  for(int digit = 1; maxNumber / digit > 0; digit *= 10){
    int *countingArray = calloc(10, sizeof(int));
    int *arrayCopy = malloc(size * sizeof(int));

    if((!countingArray) || (!arrayCopy)){
      exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size; i++){
      countingArray[(array[i] / digit) % 10]++;
    }

    for(int i = 1; i < 10; i++){
      countingArray[i] += countingArray[i - 1];
    }

    for(int i = size - 1; i >= 0; i--){
      arrayCopy[countingArray[(array[i] / digit) % 10] - 1] = array[i];
      countingArray[(array[i] / digit) % 10]--;
    }

    free(countingArray);
    countingArray = NULL;

    for(int i = 0; i < size; i++){
      array[i] = arrayCopy[i];
    }

    free(arrayCopy);
    arrayCopy = NULL;
  }

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}
