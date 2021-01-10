#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initImage(int I[9][9]){
  int i, j;
  for (i = 0; i < 9; ++i)
    for (j = 0; j < 9; ++j)
      I[i][j] = 1;

}

void showImage(int I[9][9]){
  int i, j;
  for (i = 0; i < 9; ++i){
    for (j = 0; j < 9; ++j)
      printf("%3d", I[i][j]);
    printf("\n");
  }
}

int main(){
  int i[9][9], i, j;

  initImage(i);

  showImage(i);

  return 0;
}