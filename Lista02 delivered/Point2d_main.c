#include <stdio.h>
#include "point2d.h";

int main() {
    Point *p1 = Point2d_create(1, 4);
    Point *p2 = Point2d_create(3, 7);
    
    printf("p1 = (%f, %f)\n", Point2d_getX(p1), Point2d_getY(p1));
    printf("p2 = (%f, %f)\n", Point2d_getX(p2), Point2d_getY(p2));
    
    Point2d_setX(p1, 0);
    Point2d_setY(p1, 5);
    
    printf("p1 = (%f, %f)\n", Point2d_getX(p1), Point2d_getY(p1));
    
    printf("Distancia  = %f\n", Point2d_distance(p1, p2));
    // saida esperada: 'Distancia  = 3.605551'
    
    return 0;
}

