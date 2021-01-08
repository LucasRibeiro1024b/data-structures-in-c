#include <stdlib.h>
#include <stdio.h>
#include "StackInt.h";

struct StackInt {
    int top;
    int size;
    int *elements;
};

StackInt *StackInt_create(int size) {
  StackInt *stackInt;
  stackInt = (StackInt*) malloc(sizeof(StackInt));
  stackInt->top = -1;
  stackInt->size = size; 
  stackInt->elements = (int*) malloc(sizeof(int) * stackInt->size);
  return stackInt;
}

int StackInt_isFull(StackInt *stack) {
  return stack->top == stack->size - 1;
}

int StackInt_isEmpty(StackInt *stack) {
  return stack->top == -1;
}

void StackInt_destroy(StackInt *stack) {
  free(stack->elements);
  free(stack);
}

void StackInt_push(StackInt *stack, int element) {
  if (StackInt_isFull(stack))
    return;
  
  stack->elements[++stack->top] = element;
  printf("%d pushed to stack\n", element);
}

int StackInt_pop(StackInt *stack) {
  if (StackInt_isEmpty(stack))
    return;
  stack->top = --stack->top;
  return stack->elements[stack->top + 1];
}

int StackInt_top(StackInt *stack) {
  if (StackInt_isEmpty(stack))
    return;
  return stack->elements[stack->top];
}
