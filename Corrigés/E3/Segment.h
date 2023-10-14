// Segment.h

#pragma once
#include "Point.h"

class Segment
{
public:
    Segment(const Point& pointA, const Point& pointB);
    void translation(const Point& nouvOrg);
    void afficher() const;

private:
    Point org, ext;
};
