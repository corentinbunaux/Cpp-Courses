// Moto.cpp

#include <iostream>
#include "Vehicule.h"
#include "Moto.h"
using namespace std;

Moto::Moto (const char* no, Couleur coul, int pui, int cyl)
    : Vehicule (no, coul, pui, 2)
{
    cylindree = cyl;
}

void Moto::afficher () const
{
    Vehicule::afficher();
    cout << cylindree << " cm3" << endl;
}
