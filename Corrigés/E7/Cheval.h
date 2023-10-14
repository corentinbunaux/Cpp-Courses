// Cheval.h

#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Cheval : public Animal
{
public :
    Cheval (const char* no)
        : Animal(no,"galope")
    { }

    void parler () const    { cout << "hennit" << endl; }

private :
};
