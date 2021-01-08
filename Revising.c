#include <stdio.h>
#include <stdlib.h> //lib to deal with pointers

int main () {
//ARRAYS
  int array_a[12];
  int array_b[10], array_c[15];

  char array_d[10]; // that array can hold a string

  //vectors can have n dimensions
  int array_e[10][10]; //array with 2 dimensions

//POINTER
  int *contPtr, cont; //a pointer is marked with an *
  //pointers can point to any type of data, structures and objects

  int y = 5;
  int *yPtr;

  yPtr = &y; //store address of y in yPtr

  print("%d\n", *yPtr); //

//MALLOC
  char *cPtr;
  cPtr = malloc(1); //allocated 1 byte
  cPtr = malloc(sizeof(char)); //allocated a number of bytes that char occupy in memory
  free(cPtr);  

  return 0;
}