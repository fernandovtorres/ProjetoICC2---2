#ifndef LIBS_H
#define LIBS_H
#include "bubble.h"
#include "counting.h"
#include "heap.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "radix.h"
#include "selection.h"
#include "shell.h"
#include "util.h"
typedef enum Sorts {
  BUBBLE,
  COUNTING,
  HEAP,
  INSERTION,
  MERGE,
  QUICK,
  RADIX,
  SELECTION,
  SHELL,
} sorts;
#endif
