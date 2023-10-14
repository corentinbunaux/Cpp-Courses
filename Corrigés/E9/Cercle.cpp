// Cercle.cpp

#include <iostream>
#include <math.h>
#include "Point.h"
#include "Forme.h"
#include "Cercle.h"
using namespace std;

/* dans la liste d'initialisation on appelle le constructeur de la classe mere
   Forme et de l'objet membre centre (constructeur par copie de Point)
*/
Cercle::Cercle(const Point& cen, double ray)
    : Forme(), centre(cen)
{
    rayon = ray;
}

double Cercle::perimetre() const
{
    return 2 * M_PI * rayon;
}

double Cercle::surface() const
{
    return M_PI * rayon * rayon;
}

void Cercle::afficherType() const
{
    cout << "cercle" << endl;
}
