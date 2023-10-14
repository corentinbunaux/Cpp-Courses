// e6.cpp

#include <iostream>
#include "Vehicule.h"
#include "Moto.h"
using namespace std;

int main()
{
    Vehicule vehi1 ("xxx", BLEU, 10, 6);
    Vehicule vehi2 ("abcd", ROUGE, 5);
    vehi1.afficher();
    vehi2.afficher();

    Moto moto1 ("mm", VERT, 7, 1000);
    moto1.afficher();

    Vehicule* pvehi;
    Moto* pmoto;
    pvehi = &moto1;
    pmoto = &moto1;

    cout << endl << "avec un pointeur Vehicule* : " << endl;
    pvehi->afficher();

    cout << endl << "avec un pointeur Moto* : " << endl;
    pmoto->afficher();

    return 0;
}
