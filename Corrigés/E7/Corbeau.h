// Corbeau.h

#pragma once
#include <iostream>
#include "Animal.h"
#include "Oiseau.h"
using namespace std;

class Corbeau : public Oiseau
{
public :
    Corbeau (const char* no)
        : Oiseau(no)
    { }

    void parler () const    { cout << "croasse" << endl; }

private :
};
