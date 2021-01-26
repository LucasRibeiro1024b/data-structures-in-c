#include "stdlib.h"
#include "stdio.h"
#include "List.h"

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
  Pessoa q[] = {{52, "Armil"}, {33, "Caramelo"}, {12, "Mr.Beam"}};
  Pessoa c = {23, "Jorgin"}, d = {45, "Kravski"};
  List *l = List_create(), *m = List_create(), *nl;
  int i, idade = 23;

  for (i=0; i<3; i++){
    List_insertBegin(l, &p[i]);
    List_insertBegin(m, &q[i]);
  }

  List_print(l, print);

  print(List_find(l, &idade, compare));
  printf("\n");
  List_insertBegin(l, &c);
  List_insertEnd(l, &d);

  List_print(l, print);

  nl = List_concatenate(l, m);

  List_print(nl, print);

  return 0;
}
