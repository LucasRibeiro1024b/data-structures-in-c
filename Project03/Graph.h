typedef struct Graph Graph;

Graph *Graph_create(int v);
void Graph_destroy(Graph *G);
int **matrixInit(int v);
void Graph_insertEdge(Graph *G, int v, int w);
void Graph_removeEdge(Graph *G, int v, int w);
void Graph_show(Graph *G);
void Graph_insertVertex(Graph *G, int v);
void Graph_removeVertex(Graph *G, int v);
void Graph_showMatrix(Graph *G);
