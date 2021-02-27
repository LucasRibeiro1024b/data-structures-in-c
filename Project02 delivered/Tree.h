typedef struct Tree Tree;

Tree *Tree_create(int *index, char *value, Tree *left, Tree *right);
void Tree_destroy(Tree *tree);



void Tree_addElement(Tree *tree, int index, char **value);

void Tree_print (Tree *tree, void (*print)(void*));
