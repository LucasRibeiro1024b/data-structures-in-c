typedef struct Tree Tree;

Tree *Tree_create(void *value, Tree *left, Tree *right);
void Tree_destroy(Tree *tree);

void *Tree_getValue(Tree *tree);
Tree *Tree_getLeft(Tree *tree);
Tree *Tree_getRight(Tree *tree);

void Tree_setValue(Tree *tree, void *value);
void Tree_setLeft(Tree *tree, void *value);
void Tree_setRight(Tree *tree, void *value);

void Tree_print (Tree *tree, void (*print)(void*));
