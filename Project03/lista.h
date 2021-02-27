#define vertex int

//Começo da sessão de Estrutura de Dados
typedef struct node *link;
typedef struct graphL *GraphL;
typedef struct analise Analise;

GraphL GRAPHinitL(int V);
static link NEWnodeL(vertex w, link next);
void GRAPHinsertArcL(GraphL G, vertex v, vertex w);
void GRAPHremoveArcL(GraphL G, vertex v, vertex w);
void GRAPHshowL(GraphL G);
int GRAPHinDegVertexL(GraphL G, vertex v);
int GRAPHoutDegVertexL(GraphL G, vertex v);
vertex* GRAPHinDegsVectorL(GraphL G);
vertex* GRAPHoutDegsVectorL(GraphL G);
bool GRAPHvertexIsSinkL(GraphL G, vertex v);
bool GRAPHvertexIsSourceL(GraphL G, vertex v);
bool* GRAPHsinksVectorL(GraphL G);
bool* GRAPHsourcesVectorL(GraphL G);
bool GRAPHequalL(GraphL G, GraphL H);
bool GRAPHvPointsWL(GraphL G, vertex v, vertex w);
bool GRAPHisUndirectedL(GraphL G);
bool* UGRAPHoutDegL(GraphL G);
bool GRAPHbowExistsL(GraphL G, vertex v, vertex w);

//Começo da sessão de Grafos aleatórios

vertex randVL(GraphL G);
GraphL GRAPHrandL(int V, int A);
GraphL GRAPHrandERL(int V, int A);

//Sessão Caminho
bool GRAPHcheckWalkL(GraphL G, vertex *V, int size);

//Sessão Grafos Topológicos

bool isTopoNumberingL(GraphL G, int topo[]);
link GRAPHrootL(GraphL G);
bool GRAPHistournamentL(GraphL G);
int* GRAPHparentsForestL(GraphL G);
link GRAPHpaiDeUmVerticeFloresta(GraphL G, vertex v);
int GRAPHProfundidadeDeUmVerticeL(int* p, vertex v);
int GRAPHverificarDadosCaminho(GraphL G, int* seq, int size);
static void dfsRL(GraphL G, vertex v);
void GRAPHdfsL(GraphL G);