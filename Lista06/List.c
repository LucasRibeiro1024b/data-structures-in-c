#include "List.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void *value;
  Node *next;
} Node;

struct List {
  int quantity;
  Node *first;
};

List *List_create() {
  List *list = malloc(sizeof(List));
  list->first = NULL;
  return list;
}

void List_destroy(List *list) {
  Node *node = NULL, *next;
  if (list != NULL) {
    node = list->first;
    while (node != NULL) {
      next = node->next;
      free(node);
      node = next;
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

void *List_find(List *list, void *value, int(*compare)(void*, void*)){
  Node *node = NULL;
  if (list && value && compare) {
    node = list->first;
    while(node){
      if(compare(value, node->value))
        return node->value;
      node = node->next;
    }
  }
}

void *List_remove(List *list, void *value, int(*compare)(void*, void*)){
  Node *node = NULL, *then;
  void *aux = NULL;
  
  if (list && value && compare) {
    node = list->first;
    while(node){
      if(compare(value, node->value)){
        aux = node->value;
        
        if(then != NULL)
          then->next = node->next;

        free(node);
        return aux;
      }
      then = node;
      node = node->next;
    }
  }
}

int List_length(Node *n){
  if(n == NULL)
    return 0;
  else
    return 1 + List_length(n->next); 
}

int List_getLength(List *list){
  Node *node = NULL;
  int length = 0;
  if(list){
    node = list->first;
    while (node){
      ++length;
      node = node->next;
    }
  }
  return length;
}

void List_print(List *list, void (*print)(void*)) {
  Node *node = NULL;
  if (list && print) {
    node = list->first;
    while(node != NULL) {
      print(node->value);
      node = node->next;
    }
    printf("\n");
  }
}