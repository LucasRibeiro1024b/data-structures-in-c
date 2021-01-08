typedef struct StackFloat StackFloat;

StackFloat *StackFloat_create(int size);
void  StackFloat_destroy(StackFloat *stack);
int   StackFloat_isEmpty(StackFloat *stack);
int   StackFloat_isFull(StackFloat *stack);
void  StackFloat_push(StackFloat *stack, float element);
float StackFloat_pop(StackFloat *stack);
float StackFloat_top(StackFloat *stack);