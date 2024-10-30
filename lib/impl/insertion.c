#include "../insertion.h"

Data insertionSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  for(int i = 1; i < size; i++){
    int actual = array[i];
    int j = i - 1;

    while(j >= 0){
      if(array[j] > actual){
        array[j + 1] = array[j];
        data.numberOfSwaps++;
        data.numberOfComparisons++;

        j--;
      }
      else {
        data.numberOfComparisons++;
        break;
      }
    }

    array[j + 1] = actual;
    data.numberOfSwaps++;
  }

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;
  return data;
}
