#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct People {
  int key;
  char value[25];
} People;

void display(People [], int n);
void insert(People [], int n, People c);
void fixUp(People [], int m);
void swap(People *, People *);
void buildUpMaxHeap(People [], int n);
void fixDown(People [], int n, int i);
People extractMax(People [], int *);

int main() {
  FILE *fpointer;
  People pQueue[TAM], sPeople, max;
  int size = 0, j, aux;

  if ((fpointer = fopen("data.csv", "r")) != NULL) {
    while ((fscanf(fpointer, "%d %s", &sPeople.key, &sPeople.value)) != EOF){
      insert(pQueue, size, sPeople);
      size++;
    }
  }
  else {
    printf("Something went wrong.\n");
  }

  display(pQueue, size);
  buildUpMaxHeap(pQueue, size);

  if ((fpointer = fopen("data.csv", "w+")) != NULL) {
    aux = size;
    for (j = 0; j < aux; ++j) {
      max = extractMax(pQueue, &size);
      fprintf(fpointer, "%d %s\n", max.key, max.value);
    }
  }
  else {
    printf("Something went wrong.\n");
  }

  rewind(fpointer);
  while ((fscanf(fpointer, "%d %s", &sPeople.key, &sPeople.value)) != EOF){
    insert(pQueue, size, sPeople);
    size++;
  }
  display(pQueue, size);

  fclose(fpointer);
  return 0;
}

void display(People A[TAM], int n) {
  int i;
  printf("\nDisplay:\n");
  for (i = 0; i < n; ++i)
    printf("%d %s\n", A[i].key, A[i].value);
  printf("\n");
}

void insert(People A[TAM], int n, People c) {
  A[n] = c;
  fixUp(A, n - 1);
}

void fixUp(People A[TAM], int m) {
  int i = m;
  while ((i >= 2) && (A[i / 2].key < A[i].key)){
    swap(&A[i/2], &A[i]);
    i = i/2;
  }
}

void swap(People *A, People *B) {
  People temp = *A;
  *A = *B;
  *B = temp;
}

void buildUpMaxHeap(People A[TAM], int n) {
  int i = (n - 1) / 2;
  for (i; i >= 0; --i)
    fixDown(A, n, i);
}

void fixDown(People A[TAM], int n, int i){
  int j = i, f;
  while ((2 * j) < n) {
    f = 2 * j;
    if ((f < n) && (A[f].key < A[f+1].key))
      f = f + 1;
    if (A[j].key >= A[f].key)
      j = n;
    else {
      swap(&A[j], &A[f]);
      j = f;
    }
  }
}

People extractMax(People A[TAM], int *n) {
  People max = A[0];
  A[0] = A[*n - 1];
  *n = *n - 1;
  fixDown(A, *n, 0);
  return max;
}
