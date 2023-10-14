// Terrestre.h

#pragma once
#include "Vehicule.h"
#include "Terrestre.h"

class Terrestre : public Vehicule
{
public :
    Terrestre (int vmax, int nbr);
    void afficher () const;

    void f () {}    // on definit f sinon la classe serait abstraite

private :
    int nbRoues;
};
