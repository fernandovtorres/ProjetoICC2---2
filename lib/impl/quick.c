#include "../quick.h"

void quicksort(int v[], int start, int end, Data *data);
int median(int a, int b, int c, Data *data);

Data quickSort(int *array, int size) {
  INIT_DATA(data);
  data.start = clock();

  quicksort(array, 0, size - 1, &data);

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}

void quicksort(int v[], int start, int end, Data *data){
  if(end <= start) return;

  int middle = (start + end) / 2;

  int pivot = median(v[start], v[middle], v[end], data);

  int aux = v[end];
  v[end] = v[pivot];
  v[pivot] = aux;
  pivot = end;
  data->numberOfSwaps++;

  int i = start-1;
  int j = start;

  while(j < end){
    if(v[j] <= v[end]){
      i++;

      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      data->numberOfSwaps++;
    }

    data->numberOfComparisons++;
    j++;
  }
  
  i++;

  aux = v[pivot];
  v[pivot] = v[i];
  v[i] = aux;
  data->numberOfSwaps++;

  quicksort(v, start, i-1, data);
  quicksort(v, i+1, end, data);
}

int median(int a, int b, int c, Data *data){
  if ((a > b) ^ (a > c)){ //XOR
    data->numberOfComparisons += 2;
    return a;
  }
  else if ((b < a) ^ (b < c)){
    data->numberOfComparisons += 4;
    return b;
  }
  else{
    data->numberOfComparisons += 4;
    return c;
  }
}
