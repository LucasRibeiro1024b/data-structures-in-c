#include <stdio.h>
#include "lista.c"

int main() {
  GraphL G =  GRAPHinitL(12);

/*
0: 1 4
1: 2 5
2: 3 
3: 7
4: 8
5: 4
6: 5 10 2
7: 11 6
8: 9
9: 5 8
10: 9
11: 10
*/

  GRAPHinsertArcL(G, 0, 4);
  GRAPHinsertArcL(G, 0, 1);
  GRAPHinsertArcL(G, 1, 5);
  GRAPHinsertArcL(G, 1, 2);
  GRAPHinsertArcL(G, 2, 3);
  GRAPHinsertArcL(G, 3, 7);
  GRAPHinsertArcL(G, 4, 8);
  GRAPHinsertArcL(G, 5, 4);
  GRAPHinsertArcL(G, 6, 2);
  GRAPHinsertArcL(G, 6, 10);
  GRAPHinsertArcL(G, 6, 5);
  GRAPHinsertArcL(G, 7, 6);
  GRAPHinsertArcL(G, 7, 11);
  GRAPHinsertArcL(G, 9, 8);
  GRAPHinsertArcL(G, 9, 5);
  GRAPHinsertArcL(G, 10, 9);
  GRAPHinsertArcL(G, 11, 10);

  GRAPHdfsRLParent(G);

  for (int i = 0; i < G->V; i++)
    printf("%d ", pa[i]);
  printf("\n");

  return 0;
}