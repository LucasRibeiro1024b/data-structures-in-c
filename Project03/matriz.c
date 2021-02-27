#include <stdio.h>
#include <stdbool.h>
#include "matriz.h"
#include "lista.c"

struct graphM {
  int V, A, **adj;
};

static int** MATRIXintM(int r, int c, int val) {
  int** m = malloc(r * sizeof(int*));

  for (vertex i = 0; i < r; ++i)
    m[i] = malloc(c * sizeof(int));

  for (vertex i = 0; i < r; ++i)
    for (vertex j = 0; j < c; ++j)
      m[i][j] = val;

  return m;
};

GraphM GRAPHinitM(int V) {
  GraphM G = malloc(sizeof(GraphM));
  G->V = V;
  G->A = 0;

  G->adj = MATRIXintM(V, V, 0);

  return G;
};

void GRAPHinsertArcM(GraphM G, vertex v, vertex w) {
  if (G->adj[v][w] == 0) {
    G->adj[v][w] = 1;
    G->A++;
  }
};

void GRAPHremoveArcM(GraphM G, vertex v, vertex w) {
  if (G->adj[v][w] == 1) {
    G->adj[v][w] = 0;
    G->A--;
  }
};

void GRAPHshowM(GraphM G) {
  for (vertex v = 0; v < G->V; ++v) {
    printf("%2d:", v);

    for (vertex w = 0; w < G->V; ++w)
      if (G->adj[v][w] == 1)
        printf(" %2d", w);

    printf("\n");
  }
};

int GRAPHinDegVertexM(GraphM G, vertex v) {
  vertex i;
  int cont = 0;

  for (i = 0; i < G->V; ++i)
    if (i != v)
      if (G->adj[i][v] == 1)
        cont++;

  return cont;
};

int GRAPHoutDegVertexM(GraphM G, vertex v) {
  vertex i;
  int cont = 0;

  for (i = 0; i < G->V; ++i)
    if (G->adj[v][i] == 1)
      cont++;

  return cont;
};

int* GRAPHinDegVectorM(GraphM G) {
  int* inDeg = malloc(G->V * sizeof(int)), i;

  for (i = 0; i < G->V; ++i)
    inDeg[i] = GRAPHinDegVertexM(G, i);

  return inDeg;
};

int* GRAPHoutDegVectorM(GraphM G) {
  int *outDeg = malloc(G->V * sizeof(int)), i;

  for (i = 0; i < G->V; ++i)
    outDeg[i] = GRAPHoutDegVertexM(G, i);

  return outDeg;
};

bool GRAPHvertexIsSinkM(GraphM G, vertex v) {
  return GRAPHinDegVertexM(G, v) == 0 && GRAPHoutDegVertexM(G, v) != 0;
};

bool GRAPHvertexIsSourceM(GraphM G, vertex v) {
  return GRAPHinDegVertexM(G, v) != 0 && GRAPHoutDegVertexM(G, v) == 0;
};

bool* GRAPHsinksVectorM(GraphM G) {
  vertex i;
  bool* sink = malloc(G->V * sizeof(bool));

  for (i = 0; i < G->V; ++i)
    sink[i] = GRAPHvertexIsSinkM(G, i);  

  return sink;
};

bool* GRAPHsourcesVectorM(GraphM G) {
  vertex i;
  bool* source = malloc(G->V * sizeof(bool));

  for (i = 0; i < G->V; ++i)
    source[i] = GRAPHvertexIsSourceM(G, i);

  return source;
};

GraphL GRAPHconvertMatrixToListM(GraphM G) {
  GraphL H = GRAPHinitL(G->V);
  vertex i, j;

  for (i = 0; i < G->V; ++i)
    for (j = G->V - 1; j >= 0; j--)
      if (G->adj[i][j] == 1)
        GRAPHinsertArcL(H, i, j);
  
  return H;
};

static int contEspacos;

static void dfsRM( GraphM G, vertex v) 
{ 
   pre[v] = cnt++; 

   for (vertex j = 0; j < G->V; ++j) {
      if (G->adj[v][j] == 1) {
      vertex w = j;

      if (pre[w] == -1) {
        for (int i = 0; i < contEspacos; i++)
          printf(" ");

        printf("%d-%d dsfR(G, %d)\n", v, w, w);

        contEspacos += 2;

        dfsRM( G, w); 

        for (int i = 0; i < contEspacos; i++)
          printf(" ");

        printf("%d\n", w);

        contEspacos -= 2;
      }
      }
   }
};

void GRAPHdfsM( GraphM G) { 
   cnt = 0;
   contEspacos = 0;

   for (vertex v = 0; v < G->V; ++v) 
      pre[v] = -1;

   for (vertex i = 0; i < G->V; ++i)
      if (pre[i] == -1 && GRAPHoutDegVertexM(G, i) != 0) {
        printf("%d dsfR(G, %d)\n", i, i);

        dfsRM(G, i);

        printf("%d\n", i);

        contEspacos = 0;
      }
};

