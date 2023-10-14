// ListeAnimaux.cpp

#include <iostream>
#include "Animal.h"
#include "Chien.h"
#include "Cheval.h"
#include "Oiseau.h"
#include "Pigeon.h"
#include "Corbeau.h"
#include "Rossignol.h"
#include "ListeAnimaux.h"
using namespace std;

ListeAnimaux::ListeAnimaux ()
{
    nbAnimaux = 0;
}

void ListeAnimaux::ajouter (Animal* pAnim)
{
    if (nbAnimaux < MAX_ANIMAUX) {
        animaux[nbAnimaux] = pAnim;
        nbAnimaux++;
    }
}

void ListeAnimaux::afficher () const
{
    for (int i = 0; i < nbAnimaux; i++) {
        cout << "**********" << endl;
        animaux[i]->afficher();
        animaux[i]->parler();
    }
}
