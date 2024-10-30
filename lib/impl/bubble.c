#include "../bubble.h"

Data bubbleSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  int swapped = 0;
  size--;

  do{
    swapped = 0;
    
    for (int i = 0; i < size; i++) {
      if (array[i] > array[i + 1]) {
        swap(&array[i], &array[i + 1]);
        swapped = 1;

        data.numberOfSwaps++;
      }

      data.numberOfComparisons++;
    }
  }while(swapped);

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}
