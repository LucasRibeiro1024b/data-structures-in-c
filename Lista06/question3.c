#include <stdio.h>
#include <stdlib.h>

void intImage(int I[9][9], char *s){
  FILE *fpointer;
  int a[9][9];
  int i = 0, j, k;

  if ((fpointer = fopen(s, "r")) != NULL){
    for (i = 0; i < 9; ++i)
      for (j = 0; j < 9; ++j)
        fscanf(fpointer, "%d", a[i][j]);

    for (i = 0; i < 9; ++i)
      for (j = 0; j < 9; ++j)
        I[i][j] = a[i][j];
  } else {
    printf("Something went wrong.\n");
  }
}

int main() {
  int p[9][9], i, j;
  char *str = malloc(sizeof(char));

  scanf("%s", str);

  intImage(p, str);

  for(i = 0; i < 9; ++i){
    for(j = 0; j < 9; ++j)
      printf("%2d", p[i][j]);
    printf("\n");
  }

  return 0;
}