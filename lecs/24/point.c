#include <stdio.h>
#include <math.h>

typedef struct Point {
    float x;
    float y;
} Point;


void print_point(Point p) {
    printf("x:%f y:%f\n", p.x, p.y);
}

int distance_from_origin(Point p) {
    return sqrt(p.x*p.x + p.y*p.y); 
}


void move_point(Point *p, float angle, float len) {
    p->x += len*cos(2*3.14*angle/360.0);
    p->y += len*sin(2*3.14*angle/360.0);
}

int main() {
    Point p = {.x = 5.0, .y = 10.0};


    print_point(p);
    move_point(&p, 90, 10);
    print_point(p);


}