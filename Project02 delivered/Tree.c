#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

struct Tree {
  int  *key;
  char *value;
  Tree *left;
  Tree *right;
};

Tree *Tree_create(int *index, char *value, Tree *left, Tree *right) {
  Tree *tree = NULL;

  if (value) {
    tree = (Tree*) malloc(sizeof(Tree));
    tree->key = index;
    tree->value = value;
    tree->left = left;
    tree->right = right;
  }

  return tree;
}

void Tree_destroy (Tree *tree) {
  if (tree) {
    Tree_destroy(tree->left);
    tree->left = NULL;

    Tree_destroy(tree->right);
    tree->right = NULL;

    free(tree);
  }
}

void Tree_addElement(Tree *tree, int index, char **value) {
    if (tree == NULL) {
      return(Tree_create(&index, value, NULL, NULL));
    }
    else {
      if (index < tree->index)
        tree->left = insert(tree->left, index, value);
      else
        node->right = insert(tree->right, index, value);

      return(tree);
    }
  }
}

void Tree_print(Tree *tree, void (*print)(void*)) {
  if (tree) {
    if(tree->value) {
      printf("<");
      print(tree->value);
      Tree_print(tree->left, print);
      Tree_print(tree->right, print);
      printf(">");
    }
  }
  else
    printf("<> ");
}
