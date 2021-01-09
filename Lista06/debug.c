#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void print(void *element){
  int c = *((int*) element);
  printf("%d\n", c);
}

int main(){
  Queue *queue = Queue_create(6);
  int i, *a, popped[5] = {0, 1, 2, 3, 4};

  for (i = 0; i < 5; ++i)
    Queue_push(queue, &popped[i]);

  Queue_print(queue, print);

  for (i = 0; i < 5; ++i){
    a = (int*) Queue_pop(queue);
    printf("%5d\n", *a);
  }
  printf("\n");

  Queue_print(queue, print);

  return 0;
}