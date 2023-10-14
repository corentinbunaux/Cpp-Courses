// Rectangle.cpp

#include <iostream>
#include "Segment.h"
#include "Forme.h"
#include "Rectangle.h"
using namespace std;

/* dans la liste d'initialisation on appelle le constructeur de la classe mere
   Forme et de l'objet membre segLargeur (constructeur par copie de Segment)
*/
Rectangle::Rectangle(const Segment& segLarg, double haut)
    : Forme(), segLargeur(segLarg)
{
    hauteur = haut;
}

double Rectangle::perimetre() const
{
    return 2 * (segLargeur.longueur() + hauteur);
}

double Rectangle::surface() const
{
    return segLargeur.longueur() * hauteur;
}

void Rectangle::afficherType() const
{
    cout << "rectangle" << endl;
}
