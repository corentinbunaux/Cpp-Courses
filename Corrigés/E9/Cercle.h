// Cercle.h

#pragma once
#include "Forme.h"
#include "Point.h"

class Cercle : public Forme
{
public:
    Cercle(const Point& cen, double ray);
    double perimetre() const;
    double surface() const;
    void afficherType() const;

private:
    Point centre;
    double rayon;
};
