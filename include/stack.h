#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct {
  int *data;
  int top;
  int capacity;
} Stack;

Stack *stack_create(int capacity);
void stack_destroy(Stack *stack);

bool stack_push(Stack *stack, T value);
bool stack_pop(Stack *stack, T *value);
bool stack_peek(const Stack *stack, T *value);

bool stack_is_empty(const Stack *stack);
bool stack_is_full(const Stack *stack);
size_t stack_size(const Stack *stack);
void stack_print(const Stack *stack);

#endif
