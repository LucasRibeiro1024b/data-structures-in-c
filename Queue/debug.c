#include <stdio.h>
#include "Queue.h"
#define SIZE 5

void print(int n){

}

int main() {
  Queue *q = Queue_create(SIZE);
  int i, queue[5] = {1, 2, 3, 4, 5};

  for (i = 0; i < SIZE; ++i)
    printf("%d\n", (i+1) % 5);

  return 0;
}