#ifndef UTIL_H
#define UTIL_H
#include <time.h>
#define INIT_DATA(X)                                                           \
  Data X = {.numberOfComparisons = 0, .numberOfSwaps = 0, .time = 0}
typedef struct data_ {
  unsigned long long numberOfComparisons;
  unsigned long long numberOfSwaps;
  clock_t start, end;
  double time;
} Data;
void swap(int *a, int *b);
int maxBetween(int a, int b);
int sort(char *string);
#endif
