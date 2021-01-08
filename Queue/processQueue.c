#include <stdio.h>
#include "Queue.h"
#define TIME 3
#define SIZE 4

struct Process {
  int id, time;
};

int main() {
    struct Process *p, procs[SIZE] = {{1,7},{2,5},{3,9},{4,6}};
    Queue *q = Queue_create(SIZE);

    int i;
    for (i = 0; i < SIZE; i++)
        Queue_push(q, &procs[i]);

    while (!Queue_isEmpty(q)) {
        p = Queue_pop(q);
        p->time -= TIME;
        
        if (p->time > TIME)
            Queue_push(q, p);
        else
            printf("Processo %d concluído\n", p->id);
    }
    Queue_destroy(q);
    return 0;
}