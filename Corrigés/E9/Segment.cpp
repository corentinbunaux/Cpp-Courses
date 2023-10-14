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
Segment::Segment(const Point& pA, const Point& pB)
    : org(pA.getX(), pA.getY()), ext(pB.getX(), pB.getY())
    //: org(pA), ext(pB)    // 2eme version
{
}

void Segment::translation(const Point& nouvOrg)
{
    // calcul des deplacements sur x et sur y
    float dx = nouvOrg.getX() - org.getX();
    float dy = nouvOrg.getY() - org.getY();

    org.setX(nouvOrg.getX());
    org.setY(nouvOrg.getY());

    ext.setX(ext.getX() + dx);
    ext.setY(ext.getY() + dy);

    /* on peut aussi modifier org et ext ainsi :
    org = nouvOrg;
    Point nouvExt (ext.getX() + dx, ext.getY() + dy);
    ext = nouvExt;
    */
}

void Segment::afficher() const
{
    cout << "segment" << endl;
    org.afficher();
    ext.afficher();
    cout << "----" << endl;
}
