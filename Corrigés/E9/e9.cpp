// e9.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Point.h"
#include "Segment.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Carre.h"
#include "ListeFormes.h"
using namespace std;

void filtrerFicPoints(const char* nomFic, float distMax,
                      const char* nomFicDest);

void filtrerFicPoints(const char* nomFic, float distMax, const char* nomFicDest)
{
    Point P0(0, 0);
    ifstream fic(nomFic);
    ofstream ficDest(nomFicDest);
    int numPoint = 0;

    while (!fic.fail()) {
        float x, y;
        fic >> x >> y;
        if (!fic.fail()) {
            Point p(x, y);
            float dist = p.distance(P0);
            if (dist < distMax) {
                ficDest << setfill('0') << setw(3) << numPoint << ": "
                    << " (" << x << ", " << y << ")"
                    << " d=" << fixed << setprecision(2) << dist << endl;
                numPoint++;
            }
        }
    }
}

int main()
{
    filtrerFicPoints("points.txt", 40, "points2.txt");

    Point P1(12, 6), P2(15, 6);

    Cercle ce(P1, 3.2);
    ce.afficher();

    Segment Sa(P1, P2);

    Rectangle re(Sa, 8);
    re.afficher();

    Carre ca(Sa);
    ca.afficher();


    cout << "LISTE DE FORMES :" << endl;
    ListeFormes lf;
    lf.ajouter(&ce);
    lf.ajouter(&re);
    lf.ajouter(&ca);
    lf.afficher();
    lf.afficherMax();

    return 0;
}
