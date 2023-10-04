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
    return 0;
}

