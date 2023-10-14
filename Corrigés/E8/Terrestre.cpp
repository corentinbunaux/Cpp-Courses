// Terrestre.cpp

#include <iostream>
#include "Vehicule.h"
#include "Terrestre.h"
using namespace std;

Terrestre::Terrestre (int vmax, int nbr)
    : Vehicule (vmax)
{
    nbRoues = nbr;
}

void Terrestre::afficher () const
{
    Vehicule::afficher();
    cout << nbRoues << " roues" << endl;
}
