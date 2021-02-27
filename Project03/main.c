#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main () {
  Graph *G = Graph_create(5);
  printf("Created a adjacency matrix with 5 vertices.\n");

  Graph_insertEdge(G, 0, 1);
  Graph_insertEdge(G, 0, 3);
  Graph_insertEdge(G, 1, 2);
  Graph_insertEdge(G, 2, 3);
  Graph_insertEdge(G, 3, 4);
  Graph_insertEdge(G, 4, 0);
  printf("Inserted 6 edges into the adj matrix.\n");

  Graph_show(G);

  printf("Inserted 2 vertices more.\n");
  Graph_insertVertex(G, 7);

  Graph_insertEdge(G, 4, 5);
  Graph_insertEdge(G, 5, 6);
  Graph_insertEdge(G, 6, 0);

  Graph_show(G);

  Graph_removeEdge(G, 4, 5);
  Graph_removeEdge(G, 5, 6);
  Graph_removeEdge(G, 6, 0);
  printf("Removed 3 Edges.\n");

  Graph_show(G);

  Graph_removeVertex(G, 5);
  printf("Removed 2 vertices.\n");

  Graph_show(G);

  printf("Matrix visualization:\n");
  Graph_showMatrix(G);

  Graph_destroy(G);
  return 0;
}

/*
b = malloc(sizeof(int*));
b[0] = malloc(sizeof(int*));
b[0][0] = 0;
b[0] = realloc(b[0], 2 * sizeof(int*));
b[0][1] = 1;

printf("%d\n", b[0][0]);
printf("%d\n", b[0][1]);
*/
