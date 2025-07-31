#include "stack.h"

Stack *stack_create(int capacity) {
  if (capacity <= 0) {
    return nullptr;
  }

  Stack *stack = malloc(sizeof(Stack));
  if (!stack) {
    return nullptr;
  }

  stack->data = malloc(capacity * sizeof(T));
  if (!stack->data) {
    free(stack);
    return nullptr;
  }

  stack->top = -1;
  stack->capacity = capacity;

  return stack;
}

void stack_destroy(Stack *stack) {
  if (stack) {
    free(stack->data);
    free(stack);
  }
}

bool stack_is_empty(const Stack *stack) { return !stack || stack->top == -1; }

bool stack_is_full(const Stack *stack) {
  return stack && stack->top == stack->capacity - 1;
}

size_t stack_size(const Stack *stack) { return stack ? stack->top + 1 : 0; }

bool stack_push(Stack *stack, T value) {
  if (!stack || stack_is_full(stack)) {
    return false;
  }

  stack->data[++stack->top] = value;

  return true;
}

bool stack_pop(Stack *stack, T *value) {
  if (!stack || !value || stack_is_empty(stack)) {
    return false;
  }

  *value = stack->data[stack->top--];

  return true;
}

bool stack_peek(const Stack *stack, T *value) {
  if (!stack || !value || stack_is_empty(stack)) {
    return false;
  }

  *value = stack->data[stack->top];

  return true;
}

void stack_print(const Stack *stack) {
  if (!stack) {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack (size=%zu): [", stack_size(stack));

  for (int i = 0; i <= stack->top; i++) {
    printf("%d", stack->data[i]);
    if (i < stack->top)
      printf(", ");
  }

  printf("]\n");
}
