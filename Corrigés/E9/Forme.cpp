// Forme.cpp

#include <iostream>
#include "Forme.h"
using namespace std;

Forme::Forme()
{
    suiv = 0;
}

void Forme::afficher() const
{
    afficherType();
    cout << "perimetre=" << perimetre() << " surface=" << surface() << endl;
}
