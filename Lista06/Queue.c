#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

struct Queue{
  int start, end, qtt, size;
  void **elements;
};

Queue *Queue_create(int size) {
  int i;
  Queue *q = (Queue*) malloc(sizeof(Queue));
  if (q != NULL) {
    q->start = 0;
    q->end = -1;
    q->qtt = 0;
    q->size = size;
    q->elements = malloc(sizeof(void*) * q->size);

    for (i = 0; i < q->size; ++i){
      q->elements[i] = NULL;
    }
  }

  return q;
}

void Queue_destroy(Queue *queue){
  if (queue != NULL) {
    free(queue->elements);
    free(queue);
    queue = NULL;
  }
}

int Queue_quantity(Queue *queue){
  if (queue == NULL)
    return -1;
  return queue->qtt;
}

int Queue_isEmpty(Queue *queue) {
  if (queue == NULL)
    return -1;
  if (queue->qtt == 0)
    return 1;
  else
    return 0;
}

int Queue_isFull(Queue *queue) {
  if (queue == NULL)
    return -1;
  if (queue->qtt == queue->size)
    return 1;
  else
    return 0;
}

int Queue_push(Queue *queue, void *element){
  if (queue == NULL)
    return 0;
  if (Queue_isFull(queue))
    return 0;
  
  queue->end = (queue->end+1) % queue->size;
  queue->elements[queue->end] = element;
  ++queue->qtt;

  return 1;
}

void *Queue_pop(Queue *queue) {
  void *poppedElement = NULL;

  if (queue == NULL || Queue_isEmpty(queue)){
    return poppedElement;
  }
  
  poppedElement = queue->elements[queue->start];
  queue->start = (queue->start+1) % queue->size;
  --queue->qtt;
  
  return poppedElement;
}

void Queue_print(Queue *queue, void (*print)(void *)){
  int i = queue->start, j;

  if (queue != NULL && print != NULL) {
    if (queue->start == -1 && queue->end == -1)
      printf("Queue is underflow\n");
    if (queue->start > queue->end){
      for (i = queue->start; i < queue->end; i++)
        print(queue->elements[i]);
      for (j = 0; j <= queue->end; j++)
        print(queue->elements[i]);
    } else {
      for(i = queue->start; i <= queue->end; i++)
        print(queue->elements[i]);
    }
    printf("\n");
  }
};