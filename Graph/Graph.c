#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queue.h"

Graph *Graph_create(int (*compar)(void*,void*)) {
	Graph *g = NULL;

	if (compar) {
		g = malloc(sizeof(Graph));
		g->size = 0;
		g->compar = compar;
		g->first = NULL;
	}

	return g;
}

void Graph_destroy(Graph *g) {
	Edge *e, *tmp_e;
	Vertex *v, *tmp_v;

	if (g) {
		v = g->first;
		while (v) {
			e = v->edge;
			while (e) {
				tmp_e = e->next;
				free(e);
				e = tmp_e;
			}
			tmp_v = v->next;
			free(v);
			v = tmp_v;
		}
	}
}

static Vertex *newVertex(void *value) {
	Vertex *new_v = NULL;
	if (value) {
		new_v = malloc(sizeof(Vertex));
		new_v->value = value;
		new_v->edge = NULL;
		new_v->next = NULL;
		new_v->vizited = 0;
		new_v->degre = 0;
	}
	return new_v;
}

void Graph_insert(Graph *g, void *value) {
	Vertex *tmp;

	if (g && value) {
		if (g->size == 0)
			g->first = newVertex(value);
		else {
			tmp = g->first;
			g->first = newVertex(value);
			g->first->next = tmp;
		}
		g->size++;
	}
}

static Vertex *findVertex(Graph *g, void *value) {
	Vertex *v;
	if (g && value) {
		v = g->first;
		while (v) {
			if (g->compar(v->value, value) == 0)
				break;
			v = v->next;
		}
	}
	return v;
}

static Edge *findEdge(Graph *g, void *val1, void *val2) {
	Vertex *v = NULL;
	Edge   *e = NULL;
	
	if (g && val1 && val2) {
		if (v = findVertex(g, val1)) {
			e = v->edge;
	
			while (e) {
				if (g->compar(e->end->value, val2) == 0)
					return e;
				e = e->next;
			}
		}
	}

	return NULL;
}

static Edge *newEdge(Vertex *end) {
	Edge *new_e = NULL;
	if (end) {
		new_e = malloc(sizeof(Edge));
		new_e->next = NULL;
		new_e->end = end;
	}
	return new_e;
}

void Graph_edge(Graph *g, void *val1, void *val2) {
	Vertex *vert1 = NULL;
	Vertex *vert2 = NULL;
	Edge   *tmp_e = NULL;
	
	if (g && val1 && val2) {
		vert1 = findVertex(g, val1);
		vert2 = findVertex(g, val2);

		if (vert1 && vert2) {
			if (vert1->edge) {
				tmp_e = vert1->edge;
				vert1->edge = newEdge(vert2);
				vert1->edge->next = tmp_e;
			}
			else
				vert1->edge = newEdge(vert2);
			vert1->degre += 1;
		}
	}
}

static Vertex *notVizited(Edge *edge) {
	Edge *e = NULL;
	if (edge) {
		e = edge;
		while (e) {
			if (e->end->vizited == 0)
				return e->end;
			e = e->next;
		}
	}
	return NULL;
}

static void dfs(Vertex *v, Vertex **path, int *count) {
	Vertex *k = NULL;

	if (v) {
		v->vizited = 1;
		path[*count] = v;
		
		while (k = notVizited(v->edge)) {
			*count += 1;
			dfs(k, path, count);
		}
	}
}

Vertex **Graph_dfs(Graph *g, void *startValue) {
	Vertex **path = NULL;
	Vertex *v = NULL;
	int i, count = 0;

	if (g && startValue) {
		if (v = findVertex(g, startValue)) {

			path = malloc(g->size * sizeof(Vertex*));

			for (i=0; i<g->size; i++)
				path[i] = NULL;

			dfs(v, path, &count);
		}
	}
	
	return path;
}

Vertex **Graph_bfs(Graph *g, void *startValue) {
	Vertex **path = NULL;
	Vertex *v = NULL, *k = NULL;
	Queue  *q = NULL;
	int i, count = 0;

	if (g && startValue) {
		if (v = findVertex(g, startValue)) {
			
			path = malloc(g->size * sizeof(Vertex*));			
			for (i=0; i<g->size; i++)
				path[i] = NULL;

			q = Queue_create(g->size);

			v->vizited = 1;
			path[count++] = v;
			Queue_push(q, v);

			while (!Queue_isEmpty(q)) {
				v = Queue_begin(q);
				
				while (k = notVizited(v->edge)) {
					k->vizited = 1;
					path[count++] = k;
					Queue_push(q, k);
				}
				
				Queue_pop(q);
			}
		}
	}
	
	return path;
}

void *Graph_search(Graph *g, void *value);
void *Graph_remove(Graph *g, void *value);


















