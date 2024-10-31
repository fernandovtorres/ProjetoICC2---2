#include "../lib/libs.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("Escreva como primeiro argumento o sort que deseja\n"
           "Escreva como segundo argumento: 1 caso queira mostrar o array "
           "ordenado\n"
           "                                0 caso não queira\n");
    return EXIT_FAILURE;
  }

  Data (*functionArray[])(int *, int) = {
      bubbleSort, countingSort, heapSort,      insertionSort, mergeSort,
      quickSort,  radixSort,    selectionSort, shellSort};
  INIT_DATA(data);

  int sortIndex, printModifier = 0, *array, size = 0;
  sortIndex = getSortIndex(argv[1]);
  if (argv[2])
    printModifier = atoi(argv[2]);

  if (sortIndex == -1) {
    printf("Escreva o nome dos sorts corretamente e em minusculo");
    return EXIT_FAILURE;
  }

  scanf(" %d", &size);

  array = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    int num;
    scanf(" %d", &num);
    array[i] = num;
  }

  data = (*functionArray[sortIndex])(array, size);
  printf("%llu %llu %f\n", data.numberOfComparisons, data.numberOfSwaps,
         data.time);

  if (printModifier) {
    for (int i = 0; i < size; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
  }

  free(array);
  array = NULL;
  return EXIT_SUCCESS;
}
