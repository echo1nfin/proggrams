#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

struct Point {
    double x;
    double y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double square(Point p1, Point p2, Point p3)
{
    double d1 = distance(p1, p2);
    double d2 = distance(p2, p3);
    double d3 = distance(p3, p1);
    double p = (d1 + d2 + d3)/2;
    return sqrt(p*(p - d1)*(p - d2)*(p - d3));
}

double square1(int numPoints, ...) {
    va_list args;
    va_start(args, numPoints);

    double maxDistance = 0;
    pair<Point, Point> maxDiagonal;
    Point temp_point;
    
    Point points[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        points[i] = va_arg(args, Point);
    }

    va_end(args);

    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 2; j < numPoints; ++j) {
            double d = distance(points[i], points[j]);
            if (d > maxDistance) {
                maxDistance = d;
                maxDiagonal = {points[i], points[j]};
                temp_point = points[j-1];
            }
        }
    }

    return square(temp_point, maxDiagonal.first, maxDiagonal.second);
}

int main() {
    Point p1 = {-13, 7};
    Point p2 = {1, 0};
    Point p3 = {4, 0};
    Point p4 = {5, 2};
    
    cout << scientific << square1(4, p1, p2, p3, p4) << endl;

    return 0;
}
