#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void print(void *value) {
  char c = *((char*) value);
  printf("%c", c);
}

int main() {
  char letters[] = "abcdef", c;

  Tree *t = NULL;
  t = Tree_create(&letters[0],
        Tree_create(&letters[1],
          NULL,
          Tree_create(&letters[3], NULL, NULL)
        ),
        Tree_create(&letters[2],
          Tree_create(&letters[4], NULL, NULL),
          Tree_create(&letters[5], NULL, NULL)
        ));

  Tree_print(t, print);
  printf("\n");
  c = *((char*) Tree_getValue(t));
  printf("%c\n", c);

  return 0;
}
