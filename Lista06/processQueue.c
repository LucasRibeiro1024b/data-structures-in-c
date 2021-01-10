#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define TIME 3
#define SIZE 4

typedef struct Process {
  int id;
  int time;
} Process;

void print(void* element){
  Process *pro = (Process*) element;
  printf("Process[%d] -> %d\n", pro->id, pro->time);
}

int main() {
    Process *p, procs[SIZE] = {{1,7},{2,5},{3,9},{4,6}};
    Queue *q = Queue_create(SIZE);
    int i;

    for (i = 0; i < SIZE; i++){
        Queue_push(q, &procs[i]);
    }

    Queue_print(q, print);

    while (!Queue_isEmpty(q)) {
        p = Queue_pop(q);
        p->time -= TIME;
        Queue_print(q, print);

        if (p->time > TIME)
            Queue_push(q, p);
        else
            printf("Processo %d concluído\n", p->id);
            //2 4 1 3
            //3 1 4 2 is the conclucion order of the process
        
    }

    Queue_destroy(q);
    return 0;
}