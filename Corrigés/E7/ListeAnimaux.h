// ListeAnimaux.h

#pragma once
#include "Animal.h"

const int MAX_ANIMAUX = 100;

class ListeAnimaux
{
public :
    ListeAnimaux ();
    void ajouter (Animal* pAnim);
    void afficher () const;

private :
    Animal* animaux[MAX_ANIMAUX];   // tableau de pointeurs
    int nbAnimaux;                  // nombre d'elements ajoutes au tableau
};
