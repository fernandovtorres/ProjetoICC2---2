#include "../selection.h"

Data selectionSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  int lowestPos = 0, aux;

  for(int i = 0; i < size - 1; i++){
    lowestPos = i;

    for(int j = i + 1; j < size; j++){
      if(array[j] < array[lowestPos]){
        lowestPos = j;
      }

      data.numberOfComparisons++;
    }

  if(lowestPos != i){
      aux = array[i];
      array[i] = array[lowestPos];
      array[lowestPos] = aux;
      data.numberOfSwaps++;
    }
  }

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}
