#include <stdio.h>
#include <stdlib.h>
#include "Stack.h";

typedef struct Person {
  char name[120];
  int age;
} Person;

void printPerson(void *element){
  Person *p = (Person *) element;
  printf("[%s, %d]\n", p->name, p->age);
}

int main() {
  Person p[4] = {{"Paulo", 33}, {"Jesus", 2020}, {"Joao", 56}, {"Beatriz", 23}};
  Person pAux[4];
  Stack *s = Stack_create(4);
  int i;

  for (i = 0; i < 4; ++i){
    Stack_push(s, &p[i]);
    Stack_print(s, printPerson);
  };

  for (i = 0; i < 4; ++i){
    pAux[i] = *((Person*) Stack_pop(s));
  }

  for (i = 0; i < 4; ++i) {
    printf("%s, %d\n", pAux[i].name, pAux[i].age);
  }

  return 0;
}