// Polygone.cpp
#include <iostream>
#include <math.h>
#include "Point.h"
#include "Polygone.h"
using namespace std;

Polygone::Polygone(int nbPts, const Point* tabPts)
{
    creerPolygone(nbPts, tabPts); 
}

Polygone::~Polygone()
{
    delete [] points;
}

Polygone::Polygone(const Polygone& poly2)
{
    creerPolygone(poly2.nbPoints, poly2.points);
}

void Polygone::creerPolygone(int nbPts, const Point* tabPts)
{
    nbPoints = nbPts;

    points = new Point[nbPts];
    for (int i = 0; i < nbPts; i++)
        points[i] = tabPts[i];
}

void Polygone::afficher() const
{
    cout << "polygone :" << endl;

    for (int i = 0; i < nbPoints; i++)
        points[i].afficher();
    points[0].afficher();

    cout << endl;
}

float Polygone::perimetre() const
{
    float perim = 0;

    for (int i = 0; i < nbPoints - 1; i++)
        perim +=  points[i].distance(points[i + 1]);
    perim += points[nbPoints - 1].distance(points[0]);

    return perim;
}

Polygone Polygone::enveloppeConvexe() const
{
    Point* R = new Point[nbPoints];
    int nbR = 0;

    Point p0 = pointGauche();

    Point p = p0;
    do {
        R[nbR++] = p;
        Point q = pointAutreQue(p);
        for (int i = 0; i < nbPoints; i++) {
            Point u = points[i];
            float xp = p.getX(), yp = p.getY(),
                  xq = q.getX(), yq = q.getY(),
                  xu = u.getX(), yu = u.getY();
            if ((xq - xp) * (yu - yp) - (xu - xp) * (yq -yp ) < 0)
                q = u;
        }
        p = q;
    } while(!p.egalA(p0));

    Polygone enveloppe(nbR, R);
    delete [] R;
    return enveloppe;
}

Point Polygone::pointGauche() const
{
    Point ptGauche = points[0];

    for (int i = 1; i < nbPoints;i++) {
        Point p  = points[i];
        if (p.getX() < ptGauche.getX()
            || (p.getX() == ptGauche.getX() && p.getY() > ptGauche.getY()))
            ptGauche = p;
    }

    return ptGauche;
}

Point Polygone::pointAutreQue(const Point& pt) const
{
    if (points[0].egalA(pt))
        return points[1];
    else
        return points[0];
}
