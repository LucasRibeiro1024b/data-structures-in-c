#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

struct Graph {
  int nVertices;
  int nEdges;
  int **adj;
};

Graph *Graph_create(int v) {
  Graph *g;
  g = malloc(sizeof(Graph*));
  g->nVertices = v;
  g->nEdges = 0;
  g->adj = matrixInit(v);
  return g;
}

int **matrixInit(int v) {
  int **m, i, j;

  m =  malloc(sizeof(int*) * v);
  for (i = 0; i < v; ++i)
    m[i] = malloc(sizeof(int*) * v);

  for (i = 0; i < v; ++i)
    for (j = 0; j < v; ++j)
      m[i][j] = 0;

  return m;
}

void Graph_destroy(Graph *G) {
  int i, j, s = G->nEdges;
  free(G->adj);
  free(G);
}

void Graph_insertEdge(Graph *G, int v, int w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->nEdges++;
   }
}

void Graph_removeEdge(Graph *G, int v, int w) {
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->nEdges--;
   }
}

void Graph_show(Graph *G) {
  int v, w;
  for (v = 0; v < G->nVertices; ++v) {
    printf("%2d:", v);
    for (w = 0; w < G->nVertices; ++w)
      if (G->adj[v][w] == 1)
        printf( " %2d", w);
    printf( "\n");
  }
  printf("\n");
}

void Graph_insertVertex(Graph *G, int v) {
  int i, j, s = G->nVertices;

  G->adj = realloc(G->adj, sizeof(int*) * v);

  for (i = s; i < v; ++i)
    G->adj[i] = malloc(sizeof(int*) * v);

  for (i = 0; i < s; ++i)
    for (j = s; j < v; ++j)
      G->adj[i][j] = 0;

  for (i = s; i < v; ++i)
    for (j = 0; j < v; ++j)
      G->adj[i][j] = 0;

  G->nVertices = v;
}

void Graph_removeVertex(Graph *G, int v) {
  int i, s = G->nVertices;
  G->nVertices = v;
}

void Graph_showMatrix(Graph *G) {
  int i, j, s = G->nVertices;

  printf(" ");
  for (i = 0; i < s; ++i)
    printf("%2d", i);
  printf("\n");

  for (i = 0; i < s; ++i) {
    printf("%d", i);
    for (j = 0; j < s; ++j)
      printf("%2d", G->adj[i][j]);
    printf("\n");
  }
/*
    1 2 3 4
  1 0 0 0 0
  2 0 0 0 0
  3 0 0 0 0
  4 0 0 0 0
*/
}
