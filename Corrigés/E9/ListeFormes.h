// ListeFormes.h

#pragma once
#include "Forme.h"

class ListeFormes
{
public:
    ListeFormes();
    void ajouter(Forme* forme);
    void afficher() const;
    void afficherMax() const;

private :
  Forme* tete;
};
