// Ensemble.h

#pragma once
#include <iostream>
using namespace std;

const int TAILLE = 100;

template <class T>
class Ensemble
{
public :
    Ensemble ();
    void ajouter (T val);
    bool contient (T val) const;
    void afficher () const;

private :
    T elem[TAILLE];
    int nb;
};

template <class T>
Ensemble<T>::Ensemble ()
{
    nb = 0;
}

template <class T>
void Ensemble<T>::ajouter (T val)
{
    if (nb < TAILLE && !contient(val)) {
        elem[nb] = val;
        nb++;
    }
}

template <class T>
bool Ensemble<T>::contient (T val) const
{
    int i = 0;

    while (val != elem[i] && i < nb)
        i++;

    if (i < nb)
        return true;
    else
        return false;
}

template <class T>
void Ensemble<T>::afficher () const
{
    for (int i = 0; i < nb; i++)
        cout << elem[i] << " ";

    cout << endl;
}
