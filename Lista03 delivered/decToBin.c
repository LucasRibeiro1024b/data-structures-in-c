#include <stdio.h>
#include "StackInt.h"

int main() {
    int number = 0;
    StackInt *stack = StackInt_create(20);
    
    printf("Decimal number: ");
    scanf("%d", &number);
    do {
        StackInt_push(stack, number % 2);
        number /= 2;
    } while (number != 0);
    
    printf("Binary number: ");
    while (!StackInt_isEmpty(stack))
        printf("%d", StackInt_pop(stack));
    printf("\n");
    StackInt_destroy(stack);
    return 0;
}