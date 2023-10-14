// Vehicule.h

#pragma once

enum Couleur {ROUGE, VERT, BLEU};

class Vehicule
{
public :
    Vehicule (const char* no, Couleur coul, int pui, int nbr = 4);
    void afficher () const;
    //virtual void afficher () const;

private :
    char nom[20];
    int puiss;
    int nbRoues;
    Couleur couleur;
};
