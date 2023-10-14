// e8.cpp

#include <iostream>
#include "Terrestre.h"
#include "Marin.h"
#include "Amphibie.h"
using namespace std;

int main()
{
    Terrestre terre1 (100, 4);
    Marin mer1 (30, 5);
    Amphibie amphi1 (60, 20, 10, 2);

    terre1.afficher();
    mer1.afficher();
    amphi1.afficher();

    return 0;
}
