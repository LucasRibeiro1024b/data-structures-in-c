#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct queue {
  int start, end, qtd;
  int size;
  void **elements;
};

Queue *Queue_create(int size){
  int i;
  Queue *q = (Queue*) malloc(sizeof(Queue));
  if (q != NULL) {
    q->start = 0;
    q->end = 0;
    q->qtd = 0;
    q->size = size;
    q->elements = malloc(size * sizeof(void*));
    for (i = 0; i < size; ++i)
      q->elements[i] = NULL;
  }

  return q;
}

void Queue_destroy(Queue *q) {
  if(q != NULL) {
    free(q->elements);
    free(q);
    q = NULL;
  }
}

int Queue_size(Queue *q){
  if (q == NULL)
    return -1;
  return q->qtd;
}

int Queue_isFull(Queue *q) {
  if (q == NULL)
    return -1;
  if (q->qtd == q->size)
    return 1;
  else
    return 0;
}

int Queue_isEmpty(Queue *q) {
  if (q == NULL)
    return -1;
  if (q->qtd == 0)
    return 1;
  else
    return 0;
}

int Queue_push(Queue *q, void *element){
  if (q == NULL)
    return -1;
  if (Queue_isFull(q))
    return 0;
  q->elements[q->end] = element;
  q->end = (q->end+1) % q->size;
  ++q->qtd;
  return 1;
}

void *Queue_pop(Queue *q) {
  void *element = NULL;

  if (q == NULL && !Queue_isEmpty(q)) {
    element = q->elements[q->start];
    q->start = (q->start+1) % q->size;
    --q->qtd;
  }

  return element;
}

int Queue_search(Queue *q, void *element) {
  if (q == NULL || Queue_isEmpty(q))
    return 0;
  element = q->elements[q->start];
}

void *Queue_print(Queue *q, void (*print)(void *)){
  int i;

  if (q != NULL && print != NULL) {
    for (i = q->start; i % q->size == q->end; ++i)
      print(q->elements[i]);

    printf("\n");
  }
};