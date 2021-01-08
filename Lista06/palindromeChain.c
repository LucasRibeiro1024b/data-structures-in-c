#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Queue.h"
#include "Stack.h"
#define SIZE 32

int main() {
    int i;
    char strA[SIZE], strB[SIZE], strC[SIZE], aux[SIZE];
    Queue *q = Queue_create(SIZE);
    Stack *s = Stack_create(SIZE);

    printf("Cadeia: ");
        scanf("%[^\n]s", strA);

    for (i = 0; strA[i]; i++)
      if (strA[i] != ' ')
        strA[i] = toupper(strA[i]);

    for (i = 0; strA[i]; i++)
      if (strA[i] != ' ') {
          Queue_push(q, &strA[i]);
          Stack_push(s, &strA[i]);
      }

    memset(strB, '\0', SIZE);
    memset(strC, '\0', SIZE);

    for (i = 0; !Stack_isEmpty(s); i++) {
        strB[i] = *((char*) Queue_pop(q));
        strC[i] = *((char*) Stack_pop(s));
    }
    
    if (strcmp(strB, strC) == 0)
        printf("Is a palindrome chain (%s == %s)\n", strB, strC);
    else
        printf("Isn't a palindrome chain (%s != %s)\n", strB, strC);
    
    Queue_destroy(q);
    Stack_destroy(s);

    return 0;
}