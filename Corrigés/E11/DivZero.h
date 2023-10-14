// DivZero.h

#pragma once
#include <iostream>
#include <cstring>
using namespace std;

// classe de l'exception de  division par zero
class DivZero
{
public :
    DivZero (const char* m)     { strcpy (msg, m); }
    void afficherMsg () const   { cout << msg << endl; }

private :
    char msg[100];  // message d'erreur
};
