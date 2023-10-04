// e2.cpp
#include <iostream>
using namespace std;

const int TAILLE = 100;

bool estPremier(int x);

template <class T>
class Ensemble
{
public:
    Ensemble(){
            nbElem = 0;
    }
    void ajouter(int x){
            if (nbElem < TAILLE) {
        if (!contient(x)) {
            elem[nbElem] = x;
            nbElem++;
        }
    }
    }
    void retirer(int x){
            int indice_x;

    indice_x = chercher(x);
    if (indice_x >= 0) {
        elem[indice_x] = elem[nbElem - 1];
        nbElem--;
    }
    }
    bool contient(int x) const{
            if (chercher(x) >= 0)
        return true;
    else
        return false;
    }
    bool estEgal(const Ensemble& ens2) const{
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
    Ensemble intersection(const Ensemble& ens2) const{
            Ensemble inter;

    for (int i = 0; i < nbElem; i++)
        if (ens2.contient(elem[i]))
            inter.ajouter(elem[i]);

    return inter;
    }
    Ensemble nbPremiers() const{
            Ensemble premiers;

    for (int i = 0; i < nbElem; i++)
        if (estPremier(elem[i]))
            premiers.ajouter(elem[i]);

    return premiers;
    }
    void afficher() const{
            for (int i = 0; i < nbElem; i++)
        cout << elem[i] << " ";
    cout << endl;
    }

private:
    int elem[TAILLE]; 
    int nbElem;         

    int chercher(int x) const{
            int i = 0;
    while (i < nbElem && x != elem[i])
        i++;

    if (i < nbElem)
        return i;
    else
        return -1;
    }
};

bool estPremier(int x)
{
    if (x < 2)
        return false;
    bool diviseurTrouve = false;
    for (int n = 2; !diviseurTrouve && n * n <= x; n++)
        if (x % n == 0)
            diviseurTrouve = true;

    return !diviseurTrouve;
}

int main()
{
    return 0;
}

