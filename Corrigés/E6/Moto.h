// Moto.h

#pragma once
#include "Vehicule.h"

class Moto : public Vehicule
{
public :
    Moto (const char* no, Couleur coul, int pui, int cyl);
    void afficher () const;

private :
    int cylindree;
};
