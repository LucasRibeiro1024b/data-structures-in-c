typedef struct Stack Stack;

Stack *Stack_create(int size);
void   Stack_destroy(Stack *stk);
int    Stack_isEmpty(Stack *stk);
int    Stack_isFull(Stack *stk);
void   Stack_push(Stack *stk, void *element);
void  *Stack_pop(Stack *stk);
void  *Stack_top(Stack *stk);

void   Stack_print(Stack *stack, void (*print)(void *));