#include "StackFloat.h"
#include <stdlib.h>
#include <stdio.h>

struct StackFloat {
  int top;
  int size;
  float **elements;
};

StackFloat *StackFloat_create(int size)
{
  StackFloat *stackFloat;
  int i;

  stackFloat = (StackFloat*) malloc(sizeof(StackFloat));
  if (stackFloat != NULL) {
    stackFloat->top = -1;
    stackFloat->size = size;
    stackFloat->elements = malloc(sizeof(float*) * stackFloat->size);

    for (i = 0; i < size; ++i) {
      stackFloat->elements[i] = 0;
    }

    return stackFloat;
  }
};

void StackFloat_destroy(StackFloat *stack)
{
  if (stack != NULL) {
    free(stack->elements);
    free(stack);
    stack = NULL;
  }
};

int StackFloat_isEmpty(StackFloat *stack)
{
  if (stack != NULL)
    return stack->top == -1;
  return 1;
};

int StackFloat_isFull(StackFloat *stack)
{
  if (stack != NULL)
    return stack->top == stack->size -1;
  return 1;
};

void StackFloat_push(StackFloat *stack, float element){
  if (stack != NULL && !StackFloat_isFull(stack)) {
    stack->elements[++stack->top] = element;
  }
};

float StackFloat_pop(StackFloat *stack){
  float topElement;
  if (stack != NULL && !StackFloat_isEmpty(stack)){
    topElement = stack->elements[++stack->top];
    --stack->top;
  }
  return topElement;
};

float StackFloat_top(StackFloat *stack)
{
  if (stack != NULL && !StackFloat_isEmpty(stack)){
    return stack->elements[stack->top];
  }
};
