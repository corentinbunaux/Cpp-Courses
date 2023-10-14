// Chien.h

#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Chien : public Animal
{
public :
    Chien (const char* no)
        : Animal(no,"reste fidele")
    { }

    void parler () const    { cout << "aboie" << endl; }

private :
};
