#include "../util.h"
#include <string.h>
void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
  return;
}

int maxBetween(int a, int b) { return a > b ? a : b; }

int getSortIndex(char *string) {
  if (!strcmp(string, "bubble")) {
    return 0;
  } else if (!strcmp(string, "counting")) {
    return 1;
  } else if (!strcmp(string, "heap")) {
    return 2;
  } else if (!strcmp(string, "insertion")) {
    return 3;
  } else if (!strcmp(string, "merge")) {
    return 4;
  } else if (!strcmp(string, "quick")) {
    return 5;
  } else if (!strcmp(string, "radix")) {
    return 6;
  } else if (!strcmp(string, "selection")) {
    return 7;
  } else if (!strcmp(string, "shell")) {
    return 8;
  }
  return -1;
}
