// Vehicule.h

#pragma once

class Vehicule
{
public :
    Vehicule (int vmax);
    void afficher () const;

    /* on ne doit pas pouvoir creer directement des objets Vehicule
     * => la classe Vehicule doit etre abstraite
     * => elle doit avoir une fonction virtuelle pure
     */
    virtual void f () = 0;

private :
    int vitesseMax;
};
