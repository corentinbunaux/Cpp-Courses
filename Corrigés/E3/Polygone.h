// Polygone.h
#pragma once
#include "Point.h"

class Polygone
{
public :
    Polygone(int nbPts, const Point* tabPts);
    ~Polygone();
    Polygone(const Polygone& poly2);
    void afficher() const;
    float perimetre() const;
    Polygone enveloppeConvexe() const;

private :
    int nbPoints;
    Point* points;

    void creerPolygone(int nbPts, const Point* tabPts);
    Point pointGauche() const;
    Point pointAutreQue(const Point& pt) const;
};
