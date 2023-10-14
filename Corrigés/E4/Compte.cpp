// Compte.cpp

#include <iostream>
#include "String.h"
#include "Compte.h"
using namespace std;

float Compte::taux = 3.5;
Compte*  Compte::tete = 0;  // liste vide initialement;
                            // remarque : en C++ on peut utiliser 0 pour NULL

/* dans la liste d'initialisation, appel du constructeur de l'objet membre nom
 */
Compte::Compte(const char* no, float montantIni)
    : nom(no)
{
    montant = montantIni;

    /* insertion du compte, c'est a dire de l'objet courant, en tete de
     * liste
     */
    suiv = tete;    // le compte est chaine sur l'ancienne tete
    tete = this;    // il devient la nouvelle tete
}

// le destructeur supprime le compte de la liste
Compte::~Compte()
{
    Compte* prec = 0;
    Compte* compte = tete;

    /* parcours de la liste a la recherche du compte, tout en gardant trace de
     * son precedent
     */
    while (compte != this) {    // on compare les adresses
        prec = compte; 
        compte = compte->suiv;
    }
    // on sort necessairement de la boucle en ayant trouve le compte

    /* on supprime le compte de la liste en chainant son precedent sur son
     * suivant, ou en chainant la tete de liste sur son suivant s'il n'a pas de
     * precedent
     */
    if (prec != 0)
        prec->suiv = compte->suiv;
    else
        tete = compte->suiv;
}

void Compte::verser(float montantVerse)
{
    montant += montantVerse;
}

void Compte::actualiser()
{
    montant *= (1 + taux / 100);
}

void Compte::afficher() const
{
    nom.afficher();
    cout << "montant : " << montant << endl;
}

void Compte::modifierTaux(float nouveauTaux)
{
    taux = nouveauTaux;
}

void Compte::afficherTous()
{
    // parcours du chainage pour afficher chacun des comptes
    Compte* compte = tete;
    while (compte != 0) {
        compte->afficher();
        compte = compte->suiv;
    }
}

void Compte::actualiserTous()
{
    // parcours du chainage pour actualiser chacun des comptes
    Compte* compte = tete;
    while (compte != 0) {
        compte->actualiser();
        compte = compte->suiv;
    }
}
