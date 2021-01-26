#include <stdlib.h>
#include <stdio.h>
#include "List.h"

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

void List_destroy(List *list) {
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

void List_insertBegin(List* list, void *value) {
  Node *node = NULL;

  if (list && value) {
    node = malloc(sizeof(Node));
    node->value = value;
    node->next = list->first;
    list->first = node;
  }
}

void List_insertEnd(List* list, void *value) {
  Node *node = NULL, *aux = malloc(sizeof(Node));

  if (list && value) {
    if (List_getLength(list) == 0){
      list->first = malloc(sizeof(Node));
      list->first->value = value;
      list->first->next = NULL;
    }
    else {
      node = list->first;
      while(node->next)
        node = node->next;
      node->next = malloc(sizeof(Node));
      node->next->value = value;
      node->next->next = NULL;
    }
  }
}

void *List_removeBegin(List* list) {
  Node *node = NULL, *first;
  void *aux = NULL;

  if (list && list->first) {
    aux = first->value;
    first = list->first;
    list->first = first->next;
    free(first);
    return aux;
  }
}

void *List_removeEnd(List* list) {
  Node *node = NULL, *ant;
  void *aux = NULL;

  if (list) {
    node = list->first;

    while(node) {
      ant = node;
      node = node->next;

      if (node->next == NULL) {
        ant->next = NULL;
        aux = node->value;
        free(node);
        return aux;
      }
    }
  }
}

void *List_findAndRemove(List* list, void *value, int (*compare)(void*, void*)) {
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

void *List_find(List* list, void *value, int (*compare)(void*, void*)) {
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

int List_getLength(List *list) {
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

void  List_print(List *list, void (*print)(void *)) {
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

List *List_concatenate(const List *list_a, const List *list_b) {
  List *newList = List_create();
  Node *node = malloc(sizeof(node));

  node = list_a->first;
  newList->first = node;

  while (node->next){
    node = node->next;
  }

  node->next = list_b->first;

  return newList;
}
