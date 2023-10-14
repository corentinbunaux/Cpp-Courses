// Animal.h

#pragma once
#include <iostream>
#include <cstring>
using namespace std;

/* la classe Animal ne peut definir le contenu de la fonction parler(),
 * celle-ci est donc declaree virtuelle pure et la classe est abstraite;
 */
class Animal
{
public :
    Animal (const char* no, const char* ca)
    {
        strcpy (nom, no);
        strcpy (carac, ca);
    }

    void afficher () const    { cout << nom << ", " << carac << endl; }
    virtual void parler () const = 0;

private :
    char nom[50];
    char carac[50];
};
