#include "../shell.h"

void shellsort(int v[], int size, int increments[], int numOfIncrements, Data *data);

Data shellSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  int increments[5] = {281, 77, 23, 8, 1}; //Sedgewick's sequence
  int numOfIncrements = 5;

  shellsort(array, size, increments, numOfIncrements, &data);

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}

void shellsort(int v[], int size, int increments[], int numOfIncrements, Data *data){
  int i, j, k, aux, h;
    
  for(k=0; k<numOfIncrements; k++){
    h = increments[k];

    for(i=h; i<size; i++){
      aux = v[i];

      for(j=i-h; j>=0 && v[j]>aux; j-=h){
        v[j+h] = v[j];
        data->numberOfComparisons++;
      }

      v[j+h] = aux;
      data->numberOfSwaps++;
    }
  }

  return;
}