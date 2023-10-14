// Segment.cpp

#include <iostream>
#include "Point.h"
#include "Segment.h"
using namespace std;

/* dans la liste d'initialisation, appel des constructeurs des objets membres
org et ext
1ere version : pour org et ext, appel du constructeur Point(int,int)
2eme version : pour org et ext, appel du constructeur par copie de Point
*/
Segment::Segment(const Point& pointA, const Point& pointB)
    : org(pointA.getX(), pointA.getY()), ext(pointB.getX(), pointB.getY())
    //: org(pointA), ext(pointB)    // 2eme version
{
}

void Segment::translation(const Point& nouvOrg)
{
    // calcul des deplacements sur x et sur y
    float dx = nouvOrg.getX() - org.getX();
    float dy = nouvOrg.getY() - org.getY();

    org = nouvOrg;

    ext.setX(ext.getX() + dx);
    ext.setY(ext.getY() + dy);
}

void Segment::afficher() const
{
    cout << "segment :" << endl;
    org.afficher();
    ext.afficher();
    cout << endl;
}
