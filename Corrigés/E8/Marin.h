// Marin.h

#pragma once
#include "Vehicule.h"

class Marin : public Vehicule
{
public :
    Marin (int vmax, int tir);
    void afficher () const;

    void f () {}    // on definit f sinon la classe serait abstraite

private :
    int tirant;
};
