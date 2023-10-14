// Deborde.h

#pragma once
#include <iostream>
#include <cstring>
using namespace std;

// classe de l'exception de debordement
class Deborde
{
public :
    Deborde (long v, const char* m)     { val = v; strcpy (msg, m); }
    long getVal () const                { return val; }
    void afficherMsg () const           { cout << msg << endl; }

private :
    long val;       // valeur ayant entraine le debordement
    char msg[100];  // message d'erreur
};
