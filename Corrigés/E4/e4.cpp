// e4.cpp

#include <iostream>
#include "String.h"
#include "Compte.h"
using namespace std;

int main()
{
    /*** test partie I ***/

    /* certains comptes sont crees par new pour pouvoir les supprimer par
     * delete
     */
    Compte* cpt1 = new Compte ("xy1", 1200);
    Compte cpt2 ("xy2");
    Compte* cpt3 = new Compte ("xy3", 600);
    Compte cpt4 ("xy4");
    Compte* cpt5 = new Compte ("xy5");

    cpt1->verser (100);
    cpt2.verser (200);
    cpt3->verser (50);
    cpt4.verser (10);
    cpt5->verser (20);

    cpt1->actualiser();
    cpt2.actualiser();
    cpt3->actualiser();
    cpt4.actualiser();
    cpt5->actualiser();

    cpt1->afficher();
    cpt2.afficher();
    cpt3->afficher();
    cpt4.afficher();
    cpt5->afficher();

    cout << endl << "taux a 2%" << endl;
    Compte::modifierTaux (2.0);

    cpt1->actualiser();
    cpt2.actualiser();
    cpt3->actualiser();
    cpt4.actualiser();
    cpt5->actualiser();

    cpt1->afficher();
    cpt2.afficher();
    cpt3->afficher();
    cpt4.afficher();
    cpt5->afficher();


    /*** test partie II ***/

    cout << endl << "affichage par la liste :" << endl;
    Compte::afficherTous();

    // on detruit des comptes => ils sont retires du chainage
    cout << endl << "on retire 5, 1, 3" << endl;
    delete cpt5;
    delete cpt1;
    delete cpt3;

    cout << endl << "taux a 5%" << endl;
    Compte::modifierTaux (5.0);

    Compte::actualiserTous();
    Compte::afficherTous();

    return 0;
}
