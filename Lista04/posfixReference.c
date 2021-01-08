#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "StackFloat.h"
#define SIZE 256

char *posfix(char *);
int   evaluate(char *);

int main() {
    char exp[SIZE];
    printf("Infixa: ");
    fflush(stdin);
    scanf("%[^\n]s", exp);
    printf("Posfixa: %s\n", posfix(exp));
    printf("= %d\n", evaluate(posfix(exp)));
    return 0;
}

int priority(char c) {
    switch (c) {
        case '(': return 0;    
        case '+': 
        case '-': return 1; 
        case '*': 
        case '/': return 2;
    }
    return -1;
}

char *posfix(char *in) {
    StackFloat *stk = StackFloat_create(SIZE);
    char *out = (char *) malloc(SIZE * sizeof(char));
    float conv;
    int i = 0, j = 0, x = 0;

    for (i = 0; in[i]; i++) {
        if ( in[i] == '(' ) {
            StackFloat_push(stk, (float)in[i]);
        }
        else if ( isdigit(in[i])) {
            out[j++] = in[i];
        }
        else if ( strchr("+*-/", in[i]) ) {
            out[j++] = ' ';
            while ( !StackFloat_isEmpty(stk) 
                        && priority(in[i]) <= priority(StackFloat_top(stk)) ) {
                out[j++] = (int) StackFloat_pop(stk);
            }
            StackFloat_push(stk, in[i]);
        }
        else if ( in[i] == ')' ) {
            while ( StackFloat_top(stk) != '(' )
                out[j++] = (int) StackFloat_pop(stk);
            StackFloat_pop(stk);
        }
    }

    while ( !StackFloat_isEmpty(stk) ) {
        out[j++] = (int) StackFloat_pop(stk);
    }
    out[j] = '\0';
    StackFloat_destroy(stk);
    return out;
}

int evaluate(char *expression) {
    StackFloat *stack = StackFloat_create(SIZE);
    int i, j, x, y, z;
    char *subExp = (char*) malloc(strlen(expression));
    
    for (i = 0; expression[i]; i++) {
        if ( isdigit(expression[i]) ) {
            for (j = 0; isdigit(expression[i]); j++, i++) {
                subExp[j] = expression[i];
            }
            subExp[j] = '\0';
            StackFloat_push(stack, atoi(subExp));
        }
        if ( strchr("+-*/", expression[i]) ) {
            y = StackFloat_pop(stack);
            x = StackFloat_pop(stack);
            switch (expression[i]) {
                case '+': StackFloat_push(stack, x+y); break;
                case '-': StackFloat_push(stack, x-y); break;
                case '*': StackFloat_push(stack, x*y); break;
                case '/': StackFloat_push(stack, x/y); break;
            }
        }
    }

    z = StackFloat_pop(stack);
    StackFloat_destroy(stack);
    free(subExp);
    subExp = NULL;
    return z;
}