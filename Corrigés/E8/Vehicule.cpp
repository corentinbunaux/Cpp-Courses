// Vehicule.cpp

#include <iostream>
#include "Vehicule.h"
using namespace std;

Vehicule::Vehicule (int vmax)
{
    vitesseMax = vmax;
}

void Vehicule::afficher () const
{
    cout << "vitesse max: " << vitesseMax << endl;
}
