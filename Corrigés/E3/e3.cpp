// e3.cpp

#include <iostream>
#include "Point.h"
#include "Segment.h"
#include "Polygone.h"
using namespace std;

int main()
{
    Point A(1, 2), B(8, 5), C(20, 30), D(8, 5);
    A.setX(3);
    A.setY(4);
    cout << A.getX() << "," << A.getY() << endl;
    if (B.egalA(D) && !B.egalA(C))
        cout << "egalA ok" << endl;
    cout << "distance : " << A.distance(B) << endl;

    Segment S1(A, B);
    S1.afficher();

    cout << "translation en ";
    C.afficher();
    S1.translation(C);
    S1.afficher();

    Point pts[4] = { Point(0,0), Point(0,4), Point(2,2), Point(4,2) };
    Polygone pol(4, pts);
    pol.afficher();
    cout << "perimetre : " << pol.perimetre() << endl;

    Polygone pol1(pol);
    pol1.afficher();

    Polygone env = pol.enveloppeConvexe();
    env.afficher();

    return 0;
}

