// Carre.h

#pragma once
#include "Rectangle.h"
#include "Segment.h"

/* la classe Carre herite des fonctions perimetre et surface de Rectangle et
   n'a pas necessite à les redefinir
*/
class Carre : public Rectangle
{
public:
    Carre(const Segment& cote);
    void afficherType() const;
};
