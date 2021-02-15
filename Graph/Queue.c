#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

struct Queue {
    int size;
    int begin;
    int end;
    void **elements;
};

Queue *Queue_create(int size) {
    int index;
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->size  = size;
        queue->begin = -1;
        queue->end   = -1;
        queue->elements = malloc(size * sizeof(void *));
        for (index = 0; index < size; index++)
            queue->elements[index] = NULL;
    }
    return queue;
}

void Queue_destroy(Queue *queue) {
    int index;
    if (queue != NULL) {
        free(queue->elements);
        free(queue);
        queue = NULL;
    }
}

int Queue_isEmpty(Queue *queue) {
    if (queue != NULL)
        return queue->begin == -1;
    return 1;
}

int Queue_next(Queue *queue, int index) {
	if (queue != NULL && index >= 0)
		return (index + 1) % queue->size;
	else		
		return 0;
}

int Queue_isFull(Queue *queue) {
    if (queue != NULL)
        return Queue_next(queue, queue->end) == queue->begin;
    else
        return 0;
}

void Queue_push(Queue *queue, void *element) {
    if (queue != NULL && element != NULL) {
        if (Queue_isEmpty(queue)) {
            queue->begin = Queue_next(queue, queue->end);
            queue->end = queue->begin;
            queue->elements[queue->end] = element;
        }
        else if (!Queue_isFull(queue)) {
            queue->end = Queue_next(queue, queue->end);
            queue->elements[queue->end] = element;
        }
    }
}

void  *Queue_pop(Queue *queue) {
    void *beginElement = NULL;

    if (queue != NULL) {
        if (!Queue_isEmpty(queue)) {
            beginElement = queue->elements[queue->begin];
            queue->elements[queue->begin] = NULL;

            if (queue->begin == queue->end)
                queue->begin = queue->end = -1;
            else 
                queue->begin = Queue_next(queue, queue->begin);
        }
    }

    return beginElement;
}

void *Queue_begin(Queue *queue) {
    if (queue != NULL)
        if (!Queue_isEmpty(queue))
            return queue->elements[queue->begin];

    return NULL;
}

void *Queue_end(Queue *queue) {
    if (queue != NULL)
        if (!Queue_isEmpty(queue))
            return queue->elements[queue->end];

    return NULL;
}

void Queue_print(Queue *queue, void (*print)(void *)) {
    int i;
    
    if (queue != NULL && print != NULL) {
        i = queue->begin;
        while ( 1 ) {
            print(queue->elements[i]);
            if (i == queue->end)
                break;
            i = Queue_next(queue, i);
        }
        printf("\n");
    }
}