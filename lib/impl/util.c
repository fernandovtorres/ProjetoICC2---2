#include "../util.h"
void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
  return;
}

int maxBetween(int a, int b) { return a > b ? a : b; }
