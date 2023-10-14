// Point.cpp

#include <iostream>
#include <math.h>
#include "Point.h"
using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(float x0, float y0)
{
    x = x0;
    y = y0;
}

void Point::afficher() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}

bool Point::egalA(const Point& point2) const
{
    if (x == point2.x && y == point2.y)
        return true;
    else
        return false;
}

float Point::distance(const Point& point2) const
{
    float dx = x - point2.x;
    float dy = y - point2.y;
    return sqrt(dx * dx + dy * dy);
}

