typedef struct Graph Graph;
typedef struct Vertex Vertex;
typedef struct Edge Edge;

struct Graph {
    int size;
    Vertex *first;
    int (*compar)(void*, void*);
};

struct Vertex {
    void   *value;
    Vertex *next;
    Edge   *edge;
    int vizited;
    int degre;
};

struct Edge {
    Vertex *end;
    Edge   *next;
};

Graph *Graph_create(int (*compar)(void*,void*));
void   Graph_destroy(Graph *g);
void   Graph_insert(Graph *g, void *value);
void   Graph_edge(Graph *g, void *value1, void *value2);
void  *Graph_search(Graph *g, void *value);
void  *Graph_remove(Graph *g, void *value);

Vertex **Graph_dfs(Graph *g, void *startValue);
Vertex **Graph_bfs(Graph *g, void *value);