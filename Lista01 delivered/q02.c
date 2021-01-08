/*Questão 2
Crie uma função que receba uma string e retorne o ponteiro para uma nova string invertida.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *invertedString(char *c) {
  char *iString;
  int len, i, j;

  len = strlen(c);

  printf("%d\n", len);

  iString = (char *) malloc(len * sizeof(char));

  for (i = 0, j = len - 1; i < len; i++, j--) {
    iString[i] = c[j];
  }
  iString[len] = '\0';

  free(iString);
  return iString;
}

int main() {
  char string_1[] = "any string match", *string_2;

  string_2 = invertedString(string_1);
  printf("%s <> %s\n", string_1, string_2);

  return 0;
}

