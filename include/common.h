#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int T;

#define TEST(name, condition)                                                  \
  do {                                                                         \
    printf("Testing %s...", name);                                             \
    if (condition) {                                                           \
      printf("✓ PASS\n");                                                      \
    } else {                                                                   \
      printf("✗ FAIL\n");                                                      \
    }                                                                          \
  } while (0)

#endif
