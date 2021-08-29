#include <iostream>
#include <math.h>

using namespace std;

struct point
{
    float x, y;
};

void print_point(point p)
{
    cout << "x: " << p.x << " y: " << p.y << endl;
}

struct triangle
{
    point a, b, c;
    float area;
};

float distance_btwn_points(point p, point q)
{
    return sqrt(pow((p.x - q.x), 2.0) + pow((p.y - q.y), 2.0));
}

void set_area(triangle &t)
{
    float bokA = distance_btwn_points(t.a, t.b);
    float bokB = distance_btwn_points(t.b, t.c);
    float bokC = distance_btwn_points(t.c, t.a);
    float p = (bokA + bokB + bokC) / 2;
    t.area = sqrt(p * (p - bokA) * (p - bokB) * (p - bokC));
}

void print_triangle(triangle t)
{
    cout << "Punkt a: ";
    print_point(t.a);
    cout << "Punkt b: ";
    print_point(t.b);
    cout << "Punkt c: ";
    print_point(t.c);
}

void print_triangle_area(triangle t)
{
    cout << t.area << endl;
}

int main(int argc, char const *argv[])
{
    triangle t = {{0, 1}, {2, 3}, {5, 10}};
    print_triangle(t);
    set_area(t);
    print_triangle_area(t);
    return 0;
}
