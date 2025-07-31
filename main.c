#include "stack.h"

void test_stack(void) {
  printf("\n=== Testing Stack ===\n");

  Stack *stack = stack_create(3);
  TEST("create stack", stack != NULL);
  TEST("stack is empty", stack_is_empty(stack));

  // Test push
  TEST("push 10", stack_push(stack, 10));
  TEST("push 20", stack_push(stack, 20));
  TEST("push 30", stack_push(stack, 30));
  TEST("stack is full", stack_is_full(stack));
  TEST("push when full fails", !stack_push(stack, 40));

  // Test peek and pop
  int value;
  TEST("peek top", stack_peek(stack, &value) && value == 30);
  TEST("pop", stack_pop(stack, &value) && value == 30);
  TEST("size after pop", stack_size(stack) == 2);

  stack_print(stack);
  stack_destroy(stack);

  printf("\n✓ Stack tests completed\n");
}

int main(void) { test_stack(); }
