// ListeFormes.cpp

#include <iostream>
#include "Forme.h"
#include "ListeFormes.h"
using namespace std;

ListeFormes::ListeFormes()
{
    tete = 0;    // liste vide
}

void ListeFormes::ajouter(Forme* forme)
{
    // insertion en tete de liste de l'objet pointe par forme
    forme->setSuiv(tete);
    tete = forme;
}

void ListeFormes::afficher() const
{
    cout << "****" << endl;
    /* parcours du chainage */
    Forme* forme = tete;
    while (forme != 0) {
        forme->afficher();
        forme = forme->getSuiv();
    }
}

void ListeFormes::afficherMax() const
{
    double maxPerim = 0, maxSurf = 0;
    Forme* formeMaxPerim = 0;
    Forme* formeMaxSurf = 0;

    /* parcours du chainage */
    Forme* forme = tete;
    while (forme != 0) {
        double perim = forme->perimetre();
        double surf = forme->surface();
        if (perim >= maxPerim) {
            formeMaxPerim = forme;
            maxPerim = perim;
        }
        if (surf >= maxSurf) {
            formeMaxSurf = forme;
            maxSurf = surf;
        }
        forme = forme->getSuiv();
    }

    if (formeMaxPerim != 0) {
        cout << "perimetre max = " << maxPerim << " par" << endl;
        formeMaxPerim->afficher();
    }
    if (formeMaxSurf != 0) {
        cout << "surface max = " << maxSurf << " par" << endl;
        formeMaxSurf->afficher();
    }
}
