// Forme.h

#pragma once

class Forme
{
public:
    Forme();
    void setSuiv(Forme* formeSuiv)  { suiv = formeSuiv; }
    Forme *getSuiv() const          { return suiv; }
    virtual double perimetre() const = 0;
    virtual double surface() const = 0;
    virtual void afficherType() const = 0;
    void afficher() const;

private :
    Forme* suiv;
};
