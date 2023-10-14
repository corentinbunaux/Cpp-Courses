// Amphibie.cpp

#include <iostream>
#include "Terrestre.h"
#include "Marin.h"
#include "Amphibie.h"
using namespace std;

Amphibie::Amphibie (int vmaxTer, int vmaxMar, int nbr, int tir)
    : Terrestre(vmaxTer, nbr), Marin(vmaxMar, tir)
{
}

void Amphibie::afficher () const
{
    cout << "Amphibie :" << endl;
    Terrestre::afficher();
    Marin::afficher();
}
