#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define MAXSTR 1000

void printP(void *p){
  int pp = (int) p;
  printf("%d\n", p);
}

int main(){
  Stack *stack = Stack_create(10);
  int i;
  for (i = 0; i < 10; ++i)
    Stack_push(stack, (void*)i);

  Stack_print(stack, printP);
  return 0;
}