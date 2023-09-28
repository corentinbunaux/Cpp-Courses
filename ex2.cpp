#include <iostream>
#include <cstring>
using namespace std;
#define NOMBRE_OISEAUX 3

enum TypeOiseau
{
    Pigeon,
    Corbeau,
    Rossignol
};

class Animal
{
private:
    char *nom, *espece, *cri;
    TypeOiseau type;

public:
    Animal(char *name, char *specie, char *noise)
    {
        this->nom = new char[strlen(name) + 1];
        this->espece = new char[strlen(specie) + 1];
        this->cri = new char[strlen(noise) + 1];

        strcpy(this->nom, name);
        strcpy(this->espece, specie);
        strcpy(this->cri, noise);
    }
    Animal(TypeOiseau type)
    {
        this->type = type;
        this->espece = new char[7];
        strcpy(this->espece, "oiseau");
    }
    ~Animal()
    {
        delete[] this->nom;
        delete[] this->espece;
        delete[] this->cri;
    }
    void printAnimal()
    {
        cout << this->nom << endl;
        cout << this->espece << endl;
        cout << this->cri << endl;
        switch (this->type)
        {
        case Pigeon:
            cout << "Pigeon" << endl;
            break;
        case Corbeau:
            cout << "Corbeau" << endl;
            break;
        case Rossignol:
            cout << "Rossignol" << endl;
            break;
        default:
            cout << "Oiseau inconnu" << endl;
            break;
        }
    }
};

class Oiseau : public Animal
{
public:
    Oiseau(TypeOiseau type) : Animal(type) {}
};

class Chien : public Animal
{
public:
    Chien(char *nom) : Animal(nom, "Chien", "Woaf") {}
};

class ListeAnimaux
{
private:
    char *liste;

public:
    ListeAnimaux();
    ~ListeAnimaux();
    void ajouter(Animal &animal)
    {
    }
};

int main(void)
{
    Chien monChien("Newton");
    monChien.printAnimal();
    Oiseau monRossignol(Rossignol);
    monRossignol.printAnimal();
    return 0;
}
