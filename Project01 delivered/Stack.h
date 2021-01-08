typedef struct Stack Stack;

Stack *Stack_create(int size);
void  Stack_destroy(Stack *stack);
int   Stack_isEmpty(Stack *stack);
int   Stack_isFull(Stack *stack);
void  Stack_push(Stack *stack, void *element);
void *Stack_pop(Stack *stack);
void *Stack_top(Stack *stack);

void *Stack_print(Stack *stack, void (*print)(void *));