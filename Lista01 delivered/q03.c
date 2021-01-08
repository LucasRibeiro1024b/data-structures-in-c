/*Questão 3
Escreva uma função que receba os valores inteiros e positivos M e N por parâmetro e retorne um ponteiro para uma matriz M × N alocada dinamicamente.
  Essa matriz deverá ter todas as posições inicializadas com zero.
*/

#include <stdio.h>
#include <stdlib.h>

int **initMatrix(int, int);
void showMatrix(int **, int, int);

int main() {
  int M, N, **matrix;

  scanf("%d %d", &M, &N);
  matrix = initMatrix(M, N);

  showMatrix(matrix, M, N);

  free(matrix);
  return 0;
}

int **initMatrix(int a, int b) {
  int **initMatrix, i, j;
  initMatrix = (int **) malloc(sizeof(int**) * a);

  for (i = 0; i < a; ++i) {
    initMatrix[i] = (int *) malloc(sizeof(int*) * b);
  }

  for (i = 0; i < a; ++i)
    for (j = 0; j < b; ++j) {
      initMatrix[i][j] = 0;
//      printf("%d ", initMatrix[i][j]);
    }

  return initMatrix;
}

void showMatrix(int **m, int a, int b){
  int i, j;

  for (i = 0; i < a; ++i) {
    for (j = 0; j < b; ++j)
      printf("%d ", m[i][j]);
    printf("\n");
  }
}