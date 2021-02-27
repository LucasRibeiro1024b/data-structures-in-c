#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

//Começo da sessão de Estrutura de Dados

struct node {
  vertex w;
  link next;
};

struct graphL {
  int V, A;
  link* adj;
};

struct analise {
  bool avanco, retorno, cruzado;
};

static int visited[1000];
static int cnt;
static int contEspacos;
int pre[1000];
vertex pa[1000];

GraphL GRAPHinitL(int V) {
  GraphL G = malloc(sizeof(GraphL));

  G->V = V;
  G->A = 0;
  G->adj = malloc(V * sizeof(link));

  for (vertex v = 0; v < V; ++v)
    G->adj[v] = NULL;

  return G;
};

static link NEWnodeL(vertex w, link next) {
  link a = malloc(sizeof(link));
  a->w = w;
  a->next = next;

  return a;
};

void GRAPHinsertArcL(GraphL G, vertex v, vertex w) {

  for (link a = G->adj[v]; a != NULL; a = a->next)
    if (a->w == w)
      return;

  G->adj[v] = NEWnodeL(w, G->adj[v]);
  G->A++;
};

void GRAPHremoveArcL(GraphL G, vertex v, vertex w) {
  link aux;

  if (G->adj[v]->w == w) {
    aux = G->adj[v];
    G->adj[v] = G->adj[v]->next;
    free(aux);
  }
  else
    for (link a = G->adj[v]; a != NULL; a = a->next)
      if (a->next->w == w) {
        aux = a->next;

        if (a->next->next == NULL)
          a->next = NULL;
        else 
          a->next = a->next->next;

        free(aux);
      }

};
void GRAPHshowL(GraphL G) {
  for (vertex v = 0; v < G->V; ++v) {
    printf("%2d:", v);

    for (link a = G->adj[v]; a != NULL; a = a->next)
      printf(" %2d", a->w);

    printf("\n");
  }
};

//Calcula o grau de entrada de um vértice
int GRAPHinDegVertexL(GraphL G, vertex v) {
  vertex i;
  link a;
  int cont = 0;

  for (i = 0; i < G->V; ++i)
    if (i != v)
      for (a = G->adj[i]; a != NULL; a = a->next)
        if (a->w == v)
          cont++;
      
  return cont;
};

//Calcula o grau de saída de um vértice
int GRAPHoutDegVertexL(GraphL G, vertex v) {
  int cont = 0;
  link a;

  for (a = G->adj[v]; a != NULL; a = a->next)
    cont++;

  return cont;
};

//Cria um vetor com os graus de entrada de cada vértice
vertex* GRAPHinDegsVectorL(GraphL G) {
  vertex* inDeg = malloc(G->V * sizeof(vertex));
  vertex i;

  for (i = 0; i < G->V; i++)
    inDeg[i] = GRAPHinDegVertexL(G, i);

  return inDeg;
};

//Cria um vetor com os graus de saída de cada vértice
vertex* GRAPHoutDegsVectorL(GraphL G) {
  vertex* inDeg = malloc(G->V * sizeof(vertex));
  vertex i;

  for (i = 0; i < G->V; i++)
    inDeg[i] = GRAPHoutDegVertexL(G, i);

  return inDeg;
};

//Descobre se o vértice é um sorvedouro ou não
bool GRAPHvertexIsSinkL(GraphL G, vertex v) {
  return GRAPHinDegVertexL(G, v) != 0 && GRAPHoutDegVertexL(G, v) == 0;
};

//Descobre se o vértice é uma fonte ou não
bool GRAPHvertexIsSourceL(GraphL G, vertex v) {
  return GRAPHinDegVertexL(G, v) == 0 && GRAPHoutDegVertexL(G, v) != 0;
};


//Retorna um vetor de booleanos dos sorvedouros
bool* GRAPHsinksVectorL(GraphL G) {
  bool* sink = malloc(G->V * sizeof(bool));
  vertex i;

  for (i = 0; i < G->V; i++)
    sink[i] = GRAPHvertexIsSinkL(G, i);

  return sink;
};

//retorna um vetor de booleanos das fontes
bool* GRAPHsourcesVectorL(GraphL G) {
  bool* source = malloc(G->V * sizeof(bool));
  vertex i;

  for (i = 0; i < G->V; i++)
    source[i] = GRAPHvertexIsSourceL(G, i);

  return source;
};

bool GRAPHequalL(GraphL G, GraphL H) {
  return G == H;
};

int** GRAPHlistToMatrixL(GraphL G) {
  int** M = malloc(G->V * sizeof(int*)), i, j;

  for (i = 0; i < G->V; i++)
    M[i] = malloc(G->V * sizeof(int));

  for (i = 0; i < G->V; ++i)
    for (j = 0; j < G->V; ++j)
      M[i][j] = 0;

  for (i = 0; i < G->V; ++i)
    for (link a = G->adj[i]; a != NULL; a = a->next)
      M[i][a->w] = 1;
    
  return M;
};

bool GRAPHvPointsWL(GraphL G, vertex v, vertex w) {
  link a;

  for (a = G->adj[v]; a != NULL; a = a->next)
    if (a->w == w)
      return true;

  return false;
};

bool GRAPHisUndirectedL(GraphL G) {
  bool Und;
  link a;
  vertex v;

  for (v = 0; v < G->V; ++v)
    for (a = G->adj[v]; a != NULL; a = a->next)
      if (GRAPHvPointsWL(G, v, a->w) && GRAPHvPointsWL(G, a->w, v))
        Und = true;
      else {
        Und = false;
        break;
      }
  
  return Und;
};

bool* UGRAPHoutDegL(GraphL G) {
  return GRAPHsourcesVectorL(G);
};

bool GRAPHbowExistsL(GraphL G, vertex v, vertex w) {
  link a;

  for (a = G->adj[v]; a != NULL; a = a->next)
    if (a->w == w)
      return true;

  return false;
};

//Começo da sessão de Grafos aleatórios

vertex randVL(GraphL G) {
  return (rand() / (RAND_MAX + 1.0)) * G->V;
};

GraphL GRAPHrandL(int V, int A) {
  GraphL G = GRAPHinitL(V);
  vertex v, w;

  while (G->A < A) {
    v = randVL(G);
    w = randVL(G);

    if (v != w)
      GRAPHinsertArcL(G, v, w);
  }

  return G;
};

GraphL GRAPHrandERL(int V, int A) {
  double prob = (double) (A / (V * (V - 1)));
  GraphL G = GRAPHinitL(V);

  for (vertex v = 0; v < V; ++v)
    for (vertex w = 0; w < V; ++w)
      if (v != w)
        if (rand() < prob * (RAND_MAX + 1.0))
          GRAPHinsertArcL(G, v, w);

  return G;   
};

//FIM GRAFOS ALEATÓRIOS

//COMEÇO CAMINHOS PASSEIOS

bool GRAPHcheckWalkL(GraphL G, vertex *V, int size) {
  vertex i;
  bool eVerdadeiro = true;

  for (i = 0; i < size - 1; i++) 
    if (!GRAPHbowExistsL(G, V[i], V[i + 1])) {
      eVerdadeiro = false;
      break;
    }

  return eVerdadeiro;
};

//Sessão Grafos Topológicos

bool isTopoNumberingL(GraphL G, int topo[]) {
  for (vertex v = 0; v < G->V; ++v)
    for (link a = G->adj[v]; a != NULL; a = a->next)
      if (topo[v] >= topo[a->w])
        return false;

  return true;
};

link GRAPHrootL(GraphL G) {
  link a;
  int i;

  for (i = 0; i < G->V; ++i)
    if (GRAPHvertexIsSourceL(G, i))
      return G->adj[i];

  return NULL;
};

bool GRAPHistournamentL(GraphL G) {

  for (vertex v = 0; v < G->V; v++)
    for (link a = G->adj[v]; a != NULL; a = a->next)
      if (GRAPHvPointsWL(G, a->w, v))
        return false;
        
  return true;
};

int* GRAPHparentsForestL(GraphL G) {
  int* p = (int*) malloc(G->V * sizeof(int));
  int i;

  for (i = 0; i < G->V; i++)
    p[i] = i;

  for (i = 0; i < G->V; i++)
      for (link a = G->adj[i]; a != NULL; a = a->next)
        p[a->w] = i;
     
  return p;
};

link GRAPHpaiDeUmVerticeFloresta(GraphL G, vertex v) {
  return G->adj[v];
};

int GRAPHProfundidadeDeUmVerticeL(int* p, vertex v) {
  int cont = 0, i = v, j;
  link a;

  while (p[i] != i) {
    i = p[i];
    cont++;
  }

  return cont;
};

int GRAPHverificarDadosCaminho(GraphL G, int* seq, int size) {
  int i;
  int* repeticoes = (int*) malloc(G->V * sizeof(int));
  bool simples, caminho;

  simples = caminho = true;

  for (i = 0; i < G->V; i++) 
    repeticoes[i] = 0;

  for (i = 0; i < size - 1; i++)
    if (GRAPHvPointsWL(G, seq[i], seq[i + 1])) {
      repeticoes[i]++;
      
      if (i == size - 2) {
        if (GRAPHvPointsWL(G, seq[size - 2], seq[size - 1])) {
          repeticoes[seq[size - 1]]++;

          if (repeticoes[seq[size - 1]] > 1) {
            simples = false;
            break;
          }
        }
      }
      else if (repeticoes[i] > 1) {
        simples = false;
        break;
      }
    }
    else {
      caminho = false;
      break;
    }

  if (caminho && !simples)
    return 0;
  else if (caminho && simples)
    return 1;
  else 
    return -1;
};

static void reachR(GraphL G, vertex v) {
  visited[v] = 1;

  for (link a = G->adj[v]; a != NULL; a = a->next)
    if (visited[a->w] == 0)
      reachR(G, a->w);
};

bool GRAPHLreach(GraphL G, vertex s, vertex t) {
  for (vertex v = 0; v < G->V; ++v)
    visited[v] = 0;

  reachR(G, s);

  return visited[t] == 1;
};


static void dfsRL(GraphL G, vertex v) {
  pre[v] = cnt++;

  for (link a = G->adj[v]; a != NULL; a = a->next) {
    vertex w = a->w;

    if (pre[w] == -1) {
      for (int i = 0; i < contEspacos; i++)
        printf(" ");
      printf("%d-%d dsfR(G, %d)\n", v, w, w);

      contEspacos += 2;
      pa[w] = v;
      dfsRL(G, w);

      for (int i = 0; i < contEspacos; i++)
        printf(" ");
      printf("%d\n", w);

      contEspacos -= 2;
    }
  }
};

void GRAPHdfsL(GraphL G) {
  cnt = 0;
  contEspacos = 0;

  for (vertex v = 0; v < G->V; ++v) {
    pre[v] = -1;
    pa[v] = 0;
  }

  for (vertex v = 0; v < G->V; ++v)
    if (pre[v] == -1 && G->adj[v] != NULL) {
      printf("%d dsfR(G, %d)\n", v, v);
      pa[v] = v;
      dfsRL(G, v);

      printf("%d\n", v);

      contEspacos = 0;
    }
};

static void dfsRLParent( GraphL G, vertex u, vertex v) {
  pre[v] = cnt++;
  pa[v] = u;

  for (link a = G->adj[v]; a != NULL; a = a->next)
    if (pre[a->w] == -1)
      dfsRLParent( G, v, a->w);
};

void GRAPHdfsRLParent( GraphL G) {
  cnt = 0;
  
  for (vertex v = 0; v < G->V; ++v)
    pre[v] = -1;

  for (vertex v = 0; v < G->V; ++v)
    if (pre[v] == -1)
      dfsRLParent( G, v, v);
};