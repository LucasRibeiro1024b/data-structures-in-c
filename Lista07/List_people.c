#include "stdlib.h"
#include "stdio.h"
#include "LinkedList.h"

typedef struct Pessoa {
  int idade;
  char nome[20];
} Pessoa;

void print(void *v) {
  Pessoa *p = (Pessoa*) v;
  printf("(%d, %s) ", p->idade, p->nome);
}

int compare(void *a, void *b) {
  int *i = (int*) a;
  Pessoa *p = (Pessoa*) b;
  return *i == p->idade;
}

int main() {
  Pessoa p[] = {{14, "jose"}, {23, "maria"}, {67, "joao"}};
  List *l = List_create();
  int i, idade = 23;
  for (i=0; i<3; i++)
    List_insert(l, &p[i]);
  List_print(l, print);
  print(List_find(l, &idade, compare));
  return 0;
}
