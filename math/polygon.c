#include <stdio.h>
#include <math.h>

typedef struct { double x, y; } Point;

enum { LEFT = 1, RIGHT = -1, COLLINEAR = 0 };

#define EPS 1e-9

Point subtract(Point a, Point b) {
    return (Point){ a.x - b.x, a.y - b.y };
}

double get_cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// > 0: O->A->B turns counter-clockwise, < 0: clockwise, 0: collinear
double orientation(Point O, Point A, Point B) {
    return get_cross_product(subtract(A, O), subtract(B, O));
}

double area(Point a, Point b, Point c) {
    return fabs(get_cross_product(subtract(b, a), subtract(c, a))) / 2.0;
}

// Shoelace formula: any triangle, any position, either winding
double area_of_triangle(Point a, Point b, Point c) {
    return fabs(get_cross_product(a, b) +
                get_cross_product(b, c) +
                get_cross_product(c, a)) / 2.0;
}

// Any simple polygon, either winding
double area_of_polygon(const Point vertices[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        Point p1 = vertices[i];
        Point p2 = vertices[(i + 1) % n];
        sum += get_cross_product(p1, p2);
    }
    return fabs(sum) / 2.0;
}

int get_direction(Point a, Point b, Point c) {
    double cross = get_cross_product(subtract(b, a), subtract(c, a));
    if (fabs(cross) < EPS) return COLLINEAR;
    return (cross > 0) ? LEFT : RIGHT;
}

int main(void) {
    Point sq[] = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };
    printf("Polygon area: %.2f\n", area_of_polygon(sq, 4));   // 12.00
    printf("Triangle area: %.2f\n", area_of_triangle(sq[0], sq[1], sq[2])); // 6.00
    printf("Direction: %d\n", get_direction(sq[0], sq[1], sq[2])); // 1 (LEFT)
    return 0;
}
