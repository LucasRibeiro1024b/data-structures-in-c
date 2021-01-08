#include <stdlib.h>
#include "Queue.h"
#define MAX 14

struct Queue {
  int start, end, qtd;
  void *datas[MAX];
};

Queue *Queue_Create(){
  Queue *q = (Queue*) malloc(sizeof(Queue));
  if (q != NULL) {
    q->start = 0;
    q->end = 0;
    q->qtd = 0;
//    q->datas = (Student*) malloc(sizeof(Student) * MAX);
  }

  return q;
}

void Queue_delete(Queue *q) {
  free(q);
}

int Queue_size(Queue *q){
  if (q == NULL)
    return -1;
  return q->qtd;  
}

int Queue_isFull(Queue *q) {
  if (q == NULL)
    return -1;
  if (q->qtd == MAX)
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

int Queue_Push(Queue *q, Student al){
  if (q == NULL) return -1;
  if (Queue_isFull(q)) return 0;
  q->datas[q->end] = al;
  q->end = (q->end+1)%MAX;
  ++q->qtd;
  return 1;
}

int Queue_Pop(Queue *q) {
  if (q == NULL || Queue_isEmpty(q))
    return 0;
  q->start = (q->start+1)%MAX;
  --q->qtd;
  return 1;
}

int Queue_Search(Queue *q, Student al) {
  if (q == NULL || Queue_isEmpty(q))
    return 0;
  al = q->datas[q->start];
}