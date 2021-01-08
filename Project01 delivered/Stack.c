#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Stack {
  int size;
  int top;
  void **elements;
};

Stack *Stack_create(int size){
  int i;
  Stack *stack = (Stack*) malloc(sizeof(Stack));
  if (stack != NULL) {
    stack->size = size;
    stack->top = -1;
    stack->elements = malloc(size * sizeof(void*));
    
    for (i = 0; i < size; ++i) {
      stack->elements[i] = NULL;
    }

    return stack;
  }
};

void  Stack_destroy(Stack *stack){
  if (stack != NULL) {
    free(stack->elements);
    free(stack);
    stack = NULL;
  }
};

int   Stack_isEmpty(Stack *stack){
  if (stack != NULL)
    return stack->top == -1;
  return 1;
};

int   Stack_isFull(Stack *stack){
  if (stack != NULL)
    return stack->top == stack->size -1;
  return 1;
};

void  Stack_push(Stack *stack, void *element){
  if (stack != NULL && element != NULL) {
    if (!Stack_isFull(stack)) {
      stack->elements[++stack->top] = element;
    }
  }
};

void *Stack_pop(Stack *stack){
  void *topElement = NULL;

  if (stack != NULL) {
    if (!Stack_isEmpty(stack)){
      topElement = stack->elements[stack->top];
      --stack->top;
    }
  }
  
  return topElement;
};

void *Stack_top(Stack *stack){
  void *topElement = NULL;

  if (stack != NULL) {
    if (!Stack_isEmpty(stack))
      topElement = stack->elements[stack->top];
  }

  return topElement;
};

void *Stack_print(Stack *stack, void (*print)(void *)){
  int i;

  if (stack != NULL && print != NULL) {
    for (i = stack->top; i >= 0; --i)
      print(stack->elements[i]);
    printf("\n");
  }

};
