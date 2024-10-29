#include "../merge.h"

void merge(int left[], int sizeLeft, int right[], int sizeRight, int *v, Data *data);

Data mergeSort(int *array, int size) {
  INIT_DATA(data);

  data.start = clock();

  if(size == 1) return data;

  int middle = size / 2;
  int left[middle], right[size - middle];

  int l = 0, r = 0;
  for (int i = 0; i < size; i++){
    if(i < middle){
        left[l] = array[i];
        l++;
    }
    else{
        right[r] = array[i];
        r++;
    }
  }

  data = mergeSort(left, middle);
  data = mergeSort(right, size - middle);
  merge(left, middle, right, size - middle, array, &data);

  data.end = clock();
  data.time = (double)(data.end - data.start) / CLOCKS_PER_SEC;

  return data;
}

void merge(int left[], int sizeLeft, int right[], int sizeRight, int *v, Data *data){
  int i=0, l=0, r=0;

  while((l < sizeLeft) && (r < sizeRight)){
    if(left[l] < right[r]){
        v[i] = left[l];
        l++;
    }
    else{
        v[i] = right[r];
        r++;
    }
    data->numberOfComparisons++;
    i++;
  }

  while(l < sizeLeft){
    v[i] = left[l];
    l++;
    i++;
  }
  while(r < sizeRight){
    v[i] = right[r];
    r++;
    i++;
  }

  return;
}