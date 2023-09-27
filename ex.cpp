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
    int puissance;
    Couleurs couleur = grise;

public:
    Vehicule(const char *name, int power, Couleurs color)
    {
        nom = new char[strlen(name) + 1];
        strcpy(nom, name);
        this->puissance = power;
        this->couleur = color;
    }

    ~Vehicule()
    {
        delete[] nom;
    }

    void printVehicule()
    {
        cout << "Nom du véhicule : " << this->nom << endl;
        cout << "Puissance du véhicule : " << this->puissance << " ch" << endl;
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

int main(void)
{
    Vehicule Bibi("Bibi", 110, blanche);
    Bibi.printVehicule();
    return 0;
}