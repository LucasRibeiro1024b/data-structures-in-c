typedef struct Point Point;

Point *Point2d_create(float, float);
void Point2d_delete(Point*);
float Point2d_getX(Point*);
float Point2d_getY(Point*);
void Point2d_setX(Point*, float);
void Point2d_setY(Point*, float);
double Point2d_distance(Point*, Point*);