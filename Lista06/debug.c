#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef struct class {
  int time, id;
} Class;

void print(void *element){
  Class *c = (Class*) element;
  printf("%d %d\n", c->id, c->time);
}


int main(){
  Class c[3] = {{1, 1}, {2, 3}, {3, 5}};
  Queue *queue = Queue_create(3);
  int i, *a, popped[5] = {0, 1, 2, 3, 4};

  for (i = 0; i < 4; ++i)
    Queue_push(queue, &c[i]);

  Queue_print(queue, print);

  Queue_destroy(queue);
  return 0;
}