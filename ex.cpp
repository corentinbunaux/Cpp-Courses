#include <iostream>
using namespace std;

class Vehicule
{
private:
    int vitesse_max;

protected: // impossible de créer d'instances dans le main
    Vehicule(int speed)
    {
        this->vitesse_max = speed;
    }
    virtual void affiche()
    {
        cout << "Vitesse max : " << this->vitesse_max << endl;
    }
};

class Terrestre : public Vehicule
{
private:
    int nb_roues;

public:
    Terrestre(int speed, int wheels) : Vehicule(speed)
    {
        this->nb_roues = wheels;
    }
    void affiche()
    {
        Vehicule::affiche();
        cout << "Nombre roues : " << this->nb_roues << endl;
    }
};

class Marin : public Vehicule
{
private:
    int tirant;

public:
    Marin(int speed, int tir) : Vehicule(speed)
    {
        this->tirant = tir;
    }
    void affiche()
    {
        Vehicule::affiche();
        cout << "Tirant d'eau : " << this->tirant << endl;
    }
};

class Amphibie : public Marin, Terrestre
{
public:
    Amphibie(int wheels, int tir, int speed_t, int speed_m) : Marin(speed_m, tir), Terrestre(speed_t, wheels) {}
    void affiche()
    {
        Terrestre::affiche();
        Marin::affiche();
    }
};

int main(void)
{
    Terrestre voiture(130, 4);
    voiture.affiche();

    cout << endl;

    Marin bateau(6, 48);
    bateau.affiche();

    cout << endl;

    Amphibie a(2, 47, 180, 190);
    a.affiche();

    return 0;
}