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
    q->end = 0;
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
    return -1;
  if (Queue_isFull(queue))
    return 0;
  
  queue->elements[queue->end] = element;
  queue->end = (queue->end+1) % queue->size;
  ++queue->qtt;

  return 1;
}

void *Queue_pop(Queue *queue) {
  void *poppedElement = NULL;

  if (queue == NULL || Queue_isEmpty(queue)){
    return poppedElement;
  }
  
  poppedElement = queue->elements[queue->start];
//  printf("start before pop: %d\n", queue->start);

  queue->start = (queue->start+1) % queue->size;
  --queue->qtt;
  
//  printf("start after pop: %d\n", queue->start);
  return poppedElement;
}

void Queue_print(Queue *queue, void (*print)(void *)){
  int i = queue->start;

  if (queue != NULL && print != NULL) {
    while (i % queue->size != queue->end){
      print(queue->elements[i]);
      printf("%d %d %d\n", queue->start, queue->size, queue->end);
      ++i;
    }

    printf("\n");
  }
};