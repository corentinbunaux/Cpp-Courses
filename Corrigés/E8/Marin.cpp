// Marin.cpp

#include <iostream>
#include "Vehicule.h"
#include "Marin.h"
using namespace std;

Marin::Marin (int vmax, int tir)
    : Vehicule (vmax)
{
    tirant = tir;
}

void Marin::afficher () const
{
    Vehicule::afficher();
    cout << "tirant d'eau: " << tirant << endl;
}
