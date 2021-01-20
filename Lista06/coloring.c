#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define DIM 9

void show(int [DIM][DIM]);
void color(int);
void coloringArea(int [DIM][DIM], int, int, int);
void boundaryFill(int [DIM][DIM], int, int, int, int);

int main() {
    int i, j, n, method, b;
    int img[DIM][DIM] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0, 0},
                         {0, 0, 0, 1, 1, 1, 0, 0, 0},
                         {0, 0, 1, 1, 1, 1, 1, 0, 0},
                         {0, 1, 1, 1, 1, 1, 1, 1, 0},
                         {0, 0, 2, 0, 0, 0, 2, 0, 0},
                         {0, 0, 2, 0, 0, 0, 2, 0, 0},
                         {0, 0, 2, 2, 2, 2, 2, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    while (1) {
        show(img);
        printf("\n\nNova cor (ou -1 para sair)? ");
        scanf("%d", &n);
        if (n<0) break;
        do {
            printf("Posição? ");
            scanf("%d %d", &i, &j);
        } while (i<0 || i>=DIM || j<0 || j>=DIM);
        
        do {
          printf("1. Flood-fill.\n");
          printf("2. Boundary-fill\n");
          printf("which method? ");
          scanf("%d", &method);
          switch (method)
          {
          case 1:
            coloringArea(img, i, j, n);
            break;

          case 2:
            printf("Cor de borda? ");
            scanf(" %c", &b);
            boundaryFill(img, i, j, n, b);
            break;
          
          default:
            break;
          }
        } while (method != 1 || method != 2);
    }

    return 0;
}

void color(int color) {
    switch (color) {
        case 0 : printf("\033[107m  \033[m"); break; //white
        case 1 : printf("\033[102m  \033[m"); break; //green
        case 2 : printf("\033[100m  \033[m"); break; //gray
        case 3 : printf("\033[103m  \033[m"); break; //yellow
        case 4 : printf("\033[106m  \033[m"); break; //Light cyan
    }
}

void show(int img[DIM][DIM]) {
    int i, j;

    printf("   0 1 2 3 4 5 6 7 8 \n");
    for (i = 0; i < DIM; i++) {
        printf("%d ", i);
        for (j = 0; j < DIM; j++)
            color(img[i][j]);
        printf("\n");
    }
}

int *pixel(int i, int j) {
    int *p = (int*) malloc(sizeof(int));
    *p = i * DIM + j;
    return p;
}

void coloringArea(int img[DIM][DIM], int i, int j, int n) {
    Queue *q = Queue_create(DIM*DIM);
    int p, a = img[i][j];

    img[i][j] = n;
    Queue_push(q, pixel(i, j));
    
    while (!Queue_isEmpty(q) && a != n) {
        p = *((int*)Queue_pop(q));
        i = p / DIM;
        j = p % DIM;

        if (img[i][j+1] == a) { 
            img[i][j+1] = n; 
            Queue_push(q, pixel(i, j+1));
        }
        if (img[i+1][j] == a) { 
            img[i+1][j] = n; 
            Queue_push(q, pixel(i+1, j));
        }
        if (i > 0)
            if (img[i-1][j] == a) { 
                img[i-1][j] = n; 
                Queue_push(q, pixel(i-1, j));
            }
        if (j > 0)
            if (img[i][j-1] == a) { 
                img[i][j-1] = n; 
                Queue_push(q, pixel(i, j-1));
            } 
    }
    Queue_destroy(q);
}

void boundaryFill(int img[DIM][DIM], int i, int j, int n, int b){
    Queue *q = Queue_create(DIM*DIM);
    int p, a = img[i][j];

    img[i][j] = n;
    Queue_push(q, pixel(i, j));
    
    while (!Queue_isEmpty(q) && a != n) {
        p = *((int*)Queue_pop(q));
        i = p / DIM;
        j = p % DIM;

        if (img[i][j+1] != b && img[i][j+1] != n) { 
            img[i][j+1] = n; 
            Queue_push(q, pixel(i, j+1));
        }
        if (img[i+1][j] != b && img[i+1][j] != n) { 
            img[i+1][j] = n; 
            Queue_push(q, pixel(i+1, j));
        }
        if (i > 0)
            if (img[i-1][j] != b && img[i-1][j] != n) { 
                img[i-1][j] = n; 
                Queue_push(q, pixel(i-1, j));
            }
        if (j > 0)
            if (img[i][j-1] != b && img[i][j-1] != n) { 
                img[i][j-1] = n; 
                Queue_push(q, pixel(i, j-1));
            } 
    }
    Queue_destroy(q);
}