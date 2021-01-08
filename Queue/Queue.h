typedef struct queue Queue;

Queue *Queue_create(int size);
void   Queue_destroy(Queue *q);
int    Queue_size(Queue *q);
int    Queue_isFull(Queue *q);
int    Queue_isEmpty(Queue *q);
int    Queue_push(Queue *q, void *element);
void  *Queue_pop(Queue *q);
int    Queue_search(Queue *q, void *element);
void  *Queue_print(Queue *q, void (*print)(void *));