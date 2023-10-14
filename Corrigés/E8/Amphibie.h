// Amphibie.h

#pragma once
#include "Terrestre.h"
#include "Marin.h"

class Amphibie : public Terrestre, public Marin
{
public :
    Amphibie (int vmaxTer, int vmaxMar, int nbr, int tir);
    void afficher () const;

private :
};
