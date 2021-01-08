/*
Questão 1
Crie uma estrutura Car com os membros: brand, model, value, km_l e km_h. Crie uma função que retorne o ponteiro para um vetor de N elementos tipo 'struct Car' alocado dinamicamente.
  Caso N seja negativo ou igual a zero, um ponteiro nulo deverá ser retornado.

Use a função para criar um vetor de tamanho 5, preencha suas informações e imprima o vetor.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* brand;
  char* model;
  double value;
  int km_l;
  int km_h;
} Car;

Car *createPtrToCar(int N){
  Car *carsPtr;
  
  if (N < 1) {
    return NULL;
  }

  carsPtr = (Car *) malloc(N * sizeof(Car));

  int i;
  for (i = 0; i < N; ++i) {
    carsPtr[i].brand = (char *) malloc(50 * sizeof(char));
    carsPtr[i].model = (char *) malloc(50 * sizeof(char));
  }

  return carsPtr;
}


int main () {
  Car *listOfCars;
  int n;

  scanf("%d", &n);

  listOfCars = createPtrToCar(n);

  listOfCars[0].brand = "WesternStar";
  listOfCars[0].model = "OptimusPrime";
  listOfCars[0].value = 42000;
  listOfCars[0].km_l = 240;
  listOfCars[0].km_h = 50;

  listOfCars[1].brand = "Chevrolet";
  listOfCars[1].model = "Bumblebee";
  listOfCars[1].value = 24000;
  listOfCars[1].km_l = 340;
  listOfCars[1].km_h = 100;

  listOfCars[2].brand = "Lamborghini";
  listOfCars[2].model = "HotRod";
  listOfCars[2].value = 500000;
  listOfCars[2].km_l = 420;
  listOfCars[2].km_h = 120;

  listOfCars[3].brand = "Mercedes-Benz";
  listOfCars[3].model = "Hound";
  listOfCars[3].value = 30000;
  listOfCars[3].km_l = 200;
  listOfCars[3].km_h = 80;

  listOfCars[4].brand = "Chevrolet";
  listOfCars[4].model = "Crosshairs";
  listOfCars[4].value = 30000;
  listOfCars[4].km_l = 200;
  listOfCars[4].km_h = 80;

  int i;
  for (i = 0; i < n; ++i) {
    printf("Brand: %s\n", listOfCars[i].brand);
    printf("Model: %s\n", listOfCars[i].model);
    printf("Value: %.2lf\n", listOfCars[i].value);
    printf("km/L: %d\n", listOfCars[i].km_l);
    printf("km/L: %d\n", listOfCars[i].km_h);
    printf("\n");
  }

  free(listOfCars);
  return 0;
}