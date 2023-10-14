// Segment.h

#pragma once
#include "Point.h"

class Segment
{
public:
    Segment(const Point& pA, const Point& pB);
    void translation(const Point& nouvOrg);
    void afficher() const;
    double longueur() const     { return org.distance(ext);  }

private:
    Point org, ext;
};
