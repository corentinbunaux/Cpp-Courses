// Pigeon.h

#pragma once
#include <iostream>
#include "Animal.h"
#include "Oiseau.h"
using namespace std;

class Pigeon : public Oiseau
{
public :
    Pigeon (const char* no)
        : Oiseau(no)
    { }

    void parler () const    { cout << "roucoule" << endl; }

private :
};
