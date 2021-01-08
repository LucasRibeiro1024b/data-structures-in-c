#include <stdio.h>
#include "StackInt.h"

int main() {
    char str[20], i;
    StackInt *stack = StackInt_create(20);
    
    printf("String: ");
    scanf("%[^\n]s", str);
    for (i = 0; str[i]; i++)
        StackInt_push(stack, str[i]);
    
    printf("String Inverted: ");
    while (!StackInt_isEmpty(stack))
        printf("%c", StackInt_pop(stack));
    printf("\n");
    StackInt_destroy(stack);
    return 0;
}