// e2.cpp
#include <iostream>
using namespace std;

const int TAILLE = 100;    // nb max d'elements dans un ensemble

bool estPremier(int x);

class Ensemble
{
public:
    Ensemble();
    void ajouter(int x);
    void retirer(int x);
    bool contient(int x) const;
    bool estEgal(const Ensemble& ens2) const;
    Ensemble intersection(const Ensemble& ens2) const;
    Ensemble nbPremiers() const;
    void afficher() const;

private:
    int elem[TAILLE];   // elements de l'ensemble
    int nbElem;         // nb d'elements presents dans l'ensemble

    int chercher(int x) const; // cherche x dans l'ensemble, retourne son
                               // indice dans elem ou -1 si non trouve
};

Ensemble::Ensemble()
{
    nbElem = 0;
}

void Ensemble::ajouter(int x)
{
    if (nbElem < TAILLE) {
        if (!contient(x)) {
            elem[nbElem] = x;
            nbElem++;
        }
    }
}

void Ensemble::retirer(int x)
{
    int indice_x;

    indice_x = chercher(x);
    if (indice_x >= 0) {
        // pour retirer x on peut decaler les elements suivants ou le remplacer
        // par le dernier element (solution retenue)
        elem[indice_x] = elem[nbElem - 1];
        nbElem--;
    }
}

bool Ensemble::contient(int x) const
{
    if (chercher(x) >= 0)
        return true;
    else
        return false;
}

bool Ensemble::estEgal(const Ensemble& ens2) const
{
    // les ensembles sont egaux s'ils ont meme nb d'elements et si l'un des
    // deux contient chaque element de l'autre
    bool egaux;

    if (nbElem != ens2.nbElem)
        egaux = false;
    else {
        int i = 0;
        while (i < nbElem && ens2.contient(elem[i]))
            i++;
        egaux = (i ==  nbElem);
    }

    return egaux;
}

void Ensemble::afficher() const
{
    for (int i = 0; i < nbElem; i++)
        cout << elem[i] << " ";
    cout << endl;
}

Ensemble Ensemble::intersection(const Ensemble& ens2) const
{
    Ensemble inter;

    for (int i = 0; i < nbElem; i++)
        if (ens2.contient(elem[i]))
            inter.ajouter(elem[i]);

    return inter;
}

Ensemble Ensemble::nbPremiers() const
{
    Ensemble premiers;

    for (int i = 0; i < nbElem; i++)
        if (estPremier(elem[i]))
            premiers.ajouter(elem[i]);

    return premiers;
}

int Ensemble::chercher(int x) const
{
    int i = 0;
    while (i < nbElem && x != elem[i])
        i++;

    if (i < nbElem)
        return i;
    else
        return -1;
}

bool estPremier(int x)
{
    if (x < 2)
        return false;

    bool diviseurTrouve = false;

    // on teste la divisibilite de x avec tous les nombres <= sa racine
    for (int n = 2; !diviseurTrouve && n * n <= x; n++)
        if (x % n == 0)
            diviseurTrouve = true;

    return !diviseurTrouve;
}

int main()
{
    Ensemble e1;

    e1.ajouter(2);
    e1.ajouter(8);
    e1.ajouter(6);
    e1.ajouter(5);
    e1.ajouter(2);
    e1.afficher();

    e1.retirer(8);
    e1.retirer(5);
    e1.afficher();

    Ensemble e2, e3;
    e2.ajouter(2);
    e2.ajouter(6);
    e3.ajouter(6);
    e3.ajouter(2);

    if (e1.contient(6) || !e1.contient(5))
        cout << "contient ok" << endl;

    e3.ajouter(7);

    if (e1.estEgal(e2) && !e1.estEgal(e3))
        cout << "estEgal ok" << endl;

    Ensemble e4, e5, e6;
    // multiples de 2 (e4) et de 3 (e5)
    for (int i = 1; i < 10; i++) {
        e4.ajouter(2 * i);
        e5.ajouter(3 * i);
    }
    e4.afficher();
    e5.afficher();
    e6 = e4.intersection(e5);
    e6.afficher();

    Ensemble e7, e8;
    // e7 : les 20 premiers nb entiers
    for (int i = 1; i < 20; i++)
        e7.ajouter(i);
    e8 = e7.nbPremiers();
    e8.afficher();

    return 0;
}

