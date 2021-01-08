typedef struct Queue Queue;

Queue *Queue_create(int size);
void   Queue_destroy(Queue *queue);
int    Queue_quantity(Queue *queue);
int    Queue_isEmpty(Queue *queue);
int    Queue_isFull(Queue *queue);
int    Queue_push(Queue *queue, void *element);
void  *Queue_pop(Queue *queue);
void  *Queue_begin(Queue *queue);
void  *Queue_end(Queue *queue);

void   Queue_print(Queue *queue, void(*print)(void*));