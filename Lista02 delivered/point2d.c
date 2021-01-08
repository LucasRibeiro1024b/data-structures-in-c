#include "point2d.h";
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
  float x, y;
};

Point *Point2d_create(float x, float y){
  Point *point2d;
  point2d = (Point*) malloc(sizeof(Point));
  Point2d_setX(point2d, x);
  Point2d_setY(point2d, y);
  return point2d;
};

void Point2d_delete(Point* p) {
  free(p);
};

float Point2d_getX(Point* p) {
  return p->x;
};

float Point2d_getY(Point* p) {
  return p->y;
};

void Point2d_setX(Point* p, float x) {
  p->x = x;
};

void Point2d_setY(Point* p, float y) {
  p->y = y;
};

double Point2d_distance(Point* p1, Point* p2) {
  double a, b;

  a = p2->x - p1->x;
  a = pow(a, 2);
  b = p2->y - p1->y;
  b = pow(b, 2);

  return sqrt(a + b);
};