#include "LinkedList.h"
#include "stdio.h"
#include <stdlib.h>

typedef struct Node Node;

struct Node {
  void *value;
  Node *next;
};

struct List {
  Node *first;
};

List *List_create() {
  List *l = malloc(sizeof(List));
  l->first = NULL;
  return l;
}

void List_destroy(List * list) {
  Node *node = NULL, *aux;

  if (list != NULL) {
    node = list->first;

    while (node != NULL) {
      aux = node->next;
      free(node);
      node = aux;
    }

    free(list);
  }
}

void List_insert(List *list, void *value) {
  Node *node = NULL;

  if (list && value) {
    node = malloc(sizeof(Node));
    node->value = value;
    node->next = list->first;
    list->first = node;
  }
}

void *List_find(List *list, void *value, int (*compare)(void *, void*)) {
  Node *node = NULL;

  if (list && value && compare) {
    node = list->first;

    while(node) {
      if (compare(value, node->value))
        return node->value;
      node = node->next;
    }
  }
}

void *List_remove(List* list, void *value, int (*compare)(void*, void*)) {
  Node *node = NULL, *ant;
  void *aux = NULL;

  if (list && value && compare) {
    node = list->first;

    while (node) {
      if (compare(value, node->value)) {
        aux = node->value;

        if (ant != NULL)
          ant->next = node->next;

        free(node);
        return aux;
      }
      ant = node;
      node = node->next;
    }
  }
}

int List_length(Node *node) {
  if (node == NULL)
    return 0;
  else
    return 1 + List_length(node->next);
}

int List_getLength(List *list){
  Node *node = NULL;
  int length = 0;
  if (list) {
    node = list->first;
    while(node) {
      ++length;
      node = node->next;
    }
  }

  return length;
}

void List_print(List *list, void (*print)(void *)) {
  Node *node = NULL;

  if (list && print) {
    node = list->first;

    while (node) {
      print(node->value);
      node = node->next;
    }

    printf("\n");
  }
}
