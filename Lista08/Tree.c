#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

struct Tree {
  void *value;
  Tree *left;
  Tree *right;
};

Tree *Tree_create(void *value, Tree *left, Tree *right) {
  Tree *tree = NULL;

  if (value) {
    tree = (Tree*) malloc(sizeof(Tree));
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

void *Tree_getValue(Tree *tree) {
  if(tree)
    return tree->value;
  else
    return NULL;
}

Tree *Tree_getLeft(Tree *tree) {
  if (tree)
    return tree->left;
  else
    return NULL;
}

Tree *Tree_getRight(Tree *tree) {
  if (tree)
    return tree->right;
  else
    return NULL;
}

void Tree_setValue(Tree *tree, void *value) {
  if (tree && value)
    tree->value = value;
}

void Tree_setLeft(Tree *tree, void *value) {
  if (tree && value)
    tree->left = Tree_create(value, NULL, NULL);
}

void Tree_setRight(Tree *tree, void *value) {
  if (tree && value)
    tree->right = Tree_create(value, NULL, NULL);
}

int Tree_height(Tree *tree) {
  if (tree == NULL)
    return 0;

  return MAX(Tree_height(tree->left), Tree_height(tree->right)) + 1;
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
