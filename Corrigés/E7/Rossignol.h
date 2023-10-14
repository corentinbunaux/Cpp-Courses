// Rossignol.h

#pragma once
#include <iostream>
#include "Animal.h"
#include "Oiseau.h"
using namespace std;

class Rossignol : public Oiseau
{
public :
    Rossignol (const char* no)
        : Oiseau(no)
    { }

    void parler () const    { cout << "chante" << endl; }

private :
};
