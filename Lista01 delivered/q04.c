/*Questão 4
Escreva uma função chamada 'map' que receba como parâmetro um vetor de números reais vet_real contendo N elementos, um número real K e um ponteiro para função ( float (*operation) (float a, float b) ).

A função deve retornar o ponteiro para um novo vetor B de N elementos alocado dinamicamente, em que B[ i ] = operation( A[ i ], k ).
*/

#include <stdio.h>
#include <stdlib.h>

float summation(float a, float b) {
  return a+b;
}

float subtraction(float a, float b){
  return a-b;
}

float multiplication(float a, float b) {
  return a*b;
}

float *map(float vet_real[], int N, float K, float (*operation) (float a, float b) ) {
  float *map;
  int sizeVet = sizeof(vet_real) / sizeof(float);
  int i;

  map = malloc(sizeof(float) * N);
  
  for (i = 0; i < N; ++i ) {
    map[i] = operation(vet_real[i], K);
  }

  return map;
}

void showResults(float *v, int t) {
  int i;
  for (i = 0; i < t; ++i) {
    printf("%5.2f", v[i]);
  }
  printf("\n");
}

int main() {
  int tam = 6;
  float vet[6] = {0, 1, 1, 2, 3, 5};
  float *returnedVet;

  returnedVet = map(vet, tam, 1, summation);

  showResults(returnedVet, tam);

  free(returnedVet);
  return 0;
}