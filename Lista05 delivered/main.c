#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

typedef struct Pessoa {
    char nome[120];
    int idade;
} Pessoa;

void printPessoa(void *elemento) {
    Pessoa *pess = (Pessoa *) elemento;
    printf("[%s, %d]\n", pess->nome, pess->idade);
}

int main() {
    Pessoa p[4] = {{"paulo", 33}, {"jesus", 2020}, {"joão", 56}, {"beatriz", 23}};
    Pessoa pAux[4];
    int i;
    Stack *s = Stack_create(4);

    for (i=0; i<4; i++) {
        Stack_push(s, &p[i]);
        Stack_print(s, printPessoa);
    }
    
    for (i=0; i<4; i++)
        pAux[i] = *((Pessoa *) Stack_pop(s));
    
    for (i=0; i<4; i++)
        printf("%s, %d\n", pAux[i].nome, pAux[i].idade);

    return 0;
}