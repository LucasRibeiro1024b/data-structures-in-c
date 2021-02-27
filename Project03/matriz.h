#define vertex int

typedef struct graphM *GraphM;
typedef struct node *link;
static int **MATRIXintM(int r, int c, int val);
GraphM GRAPHinitM(int V);
void GRAPHinsertArcM(GraphM G, vertex v, vertex w);
void GRAPHremoveArcM(GraphM G, vertex v, vertex w);
void GRAPHshowM(GraphM G);
int GRAPHinDegVertexM(GraphM G, vertex v);
int GRAPHoutDegVertexM(GraphM G, vertex v);
int* GRAPHinDegVectorM(GraphM G);
int* GRAPHoutDegVectorM(GraphM G);
bool GRAPHvertexIsSinkM(GraphM G, vertex v);
bool GRAPHvertexIsSourceM(GraphM G, vertex v);
bool* GRAPHsinksVectorM(GraphM G);
bool* GRAPHsourcesVectorM(GraphM G);
