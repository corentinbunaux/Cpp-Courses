#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class String
{
private:
    char *ch;

public:
    String(const String &s)
    {
        ch = new char[strlen(s.ch)];
        for (int i = 0; i < strlen(s.ch); i++)
        {
            ch[i] = s.ch[i];
        }
    }
    String(const char *chaine)
    {
        ch = new char[strlen(chaine)];
        for (int i = 0; i < strlen(chaine); i++)
        {
            ch[i] = chaine[i];
        }
    }
    ~String();
    void print()
    {
        for (int i = 0; i < strlen(ch); i++)
        {
            cout << ch[i];
        }
        cout << endl;
    }
    void toUpper()
    {
        for (int i = 0; i < strlen(ch); i++)
        {
            ch[i] = toupper(ch[i]);
        }
    }
    bool isEqual(const String &s2)
    {
        return (strcmp(ch, s2.ch) == 0) ? true : false;
    }
};

class Compte
{
private:
    String *nom;
    float montant = 0, taux;
    Compte *suiv;
    static Compte *tete;

public:
    Compte(const char *nom)
    {
        this->nom = new String(nom);
        suiv = tete;
        tete = this;
    }
    ~Compte()
    {
    }
    void setTaux(float n_taux)
    {
        taux = n_taux;
    }
    void versement(float versement)
    {
        montant += versement;
    }
    void actualise()
    {
        montant += (montant * (taux / 100));
    }
    void affiche()
    {
        cout << "Nom de compte : ";
        nom->print();
        cout << "Montant : " << this->montant << endl;
        cout << "Taux : " << this->taux << " %" << endl;
    }
    void affiche_all()
    {
        while (tete)
        {
            tete->affiche();
            tete = tete->suiv;
        }
    }
    void actualise_all()
    {
        while (tete)
        {
            tete->actualise();
            tete = tete->suiv;
        }
    }
};

Compte *Compte::tete = nullptr;

int main(void)
{
    /*Partie 1*/
    /*
    char *phrase = "coucou";
    String *s = new String(phrase);
    String *s2 = new String(*s);
    cout << s->isEqual(*s2) << endl;
    */

    /*Partie 2*/
    /*
    char *nom = "Coco";
    Compte *compte = new Compte(nom);
    compte->setTaux(4);
    compte->versement(1000);
    compte->affiche();
    compte->actualise();
    compte->affiche();
    */

    /*Partie 3*/
    char *nom1 = "Coco";
    char *nom2 = "Rem";
    char *nom3 = "Dyl";
    Compte *compte1 = new Compte(nom1);
    Compte *compte2 = new Compte(nom2);
    Compte *compte3 = new Compte(nom3);

    compte3->affiche_all();

    return 0;
}