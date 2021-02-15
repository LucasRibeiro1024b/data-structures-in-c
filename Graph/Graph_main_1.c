#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int comp(void *v1, void *v2) {
    int *a = (int*) v1;
    int *b = (int*) v2;
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int main() {
    int n[] = {0,1,2,3,4};
    int i;
    Graph *g = Graph_create(comp);
    Vertex *v, **vtx;
    Edge *e;

    for (i=4; i>=0; i--)
        Graph_insert(g, &n[i]);
    
    Graph_edge(g, &n[0], &n[1]);
    Graph_edge(g, &n[1], &n[3]);
    Graph_edge(g, &n[1], &n[2]);
    Graph_edge(g, &n[2], &n[4]);
    Graph_edge(g, &n[3], &n[4]);
    Graph_edge(g, &n[3], &n[0]);
    Graph_edge(g, &n[4], &n[1]);

    v = g->first;
    while (v) {
        printf("[%d]", *((int*)v->value));
        
        e = v->edge;
        while (e) {
            printf("->%d", *((int*)e->end->value));
            e = e->next;
        }

        printf("\n");
        v = v->next;
    }

    vtx = Graph_dfs(g, &n[0]);
    
    for (i=0; i<5; i++)
        if (vtx[i])
            printf("[%d]", *((int*)vtx[i]->value));
    printf("\n");

    return 0;
}