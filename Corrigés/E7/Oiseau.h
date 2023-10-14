// Oiseau.h

#pragma once
#include "Animal.h"

class Oiseau : public Animal
{
public :
    Oiseau (const char* no)
        : Animal(no,"vole")
    { }

    // la classe Oiseau ne peut pas definir le contenu de parler()
    // => classe abstraite

private :
};
