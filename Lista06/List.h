typedef struct List List;

List *List_create();
void  List_destroy(List *list);
void  List_insert(List *list, void *value);
void *List_find(List *list, void *value, int(*compare)(void*, void*));
void *List_remove(List *list, void *value, int(*compare)(void*, void*));
int List_length(Node *n);
int   List_getLength(List *list);
void  List_print(List *list, void(*print)(void*));