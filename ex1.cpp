#include <iostream>
#include <cstring>
using namespace std;

enum Couleurs
{
    blanche,
    rouge,
    bleue,
    noire,
    grise
};

class Vehicule
{
private:
    char *nom;
    int puissance, roues;
    Couleurs couleur = grise;

public:
    Vehicule(const char *name, int power, int wheels, Couleurs color)
    {
        nom = new char[strlen(name) + 1];
        strcpy(nom, name);
        this->puissance = power;
        this->roues = wheels;
        this->couleur = color;
    }
    Vehicule(int roues)
    {
        this->roues = roues;
    }

    ~Vehicule()
    {
        delete[] nom;
    }

    void printVehicule()
    {
        cout << "Nom du véhicule : " << this->nom << endl;
        cout << "Puissance du véhicule : " << this->puissance << " ch" << endl;
        cout << "Nombre de roues : " << this->roues << endl;
        switch (this->couleur)
        {
        case blanche:
            cout << "Couleur : Blanche" << endl;
            break;
        case rouge:
            cout << "Couleur : Rouge" << endl;
            break;
        case bleue:
            cout << "Couleur : Bleue" << endl;
            break;
        case noire:
            cout << "Couleur : Noire" << endl;
            break;
        case grise:
            cout << "Couleur : Grise" << endl;
            break;
        default:
            cout << "Couleur inconnue" << endl;
            break;
        }
    }
};

class Moto : public Vehicule
{
private:
    int cylindree;

public:
    Moto(const char *name, int power, Couleurs color, int cyl) : Vehicule(name, power, 2, color)
    {
        this->cylindree = cyl;
    }
    void printMoto(void)
    {
        this->printVehicule();
        cout << "Cylindrée : " << this->cylindree << endl;
    }
};

int main(void)
{
    Vehicule Bibi("Bibi", 110, 4, blanche);
    Bibi.printVehicule();

    Moto moto("Yamaha", 200, bleue, 150);
    moto.printMoto();

    return 0;
}