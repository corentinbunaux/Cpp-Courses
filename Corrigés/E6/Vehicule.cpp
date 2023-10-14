// Vehicule.cpp

#include <iostream>
#include <cstring>
#include "Vehicule.h"
using namespace std;

Vehicule::Vehicule (const char* no, Couleur coul, int pui, int nbr)
{
    strcpy (nom, no);
    puiss = pui;
    nbRoues = nbr;
    couleur = coul;
}

void Vehicule::afficher () const
{
    /* couleur etant de type enum son affichage donne une valeur numerique,
       d'ou la conversion en une chaine 
     */
    const char* chaineCouleur;
    switch (couleur)
    {
    case ROUGE :
        chaineCouleur = "rouge";
        break;
    case BLEU :
        chaineCouleur = "bleu";
        break;
    case VERT :
        chaineCouleur = "vert";
        break;
    }

    cout << nom << ", " << chaineCouleur << ", " << puiss << " CV"
         << ", " << nbRoues << " roues" << endl;
}
