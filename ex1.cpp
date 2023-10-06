#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Personne
{
private:
    string nom;
    int age;

public:
    Personne() {}
    Personne(string &s, int &a) : nom(s), age(a) {}
    friend ostream &operator<<(ostream &flux, const Personne &p);
    bool operator()(const Personne &p1, const Personne &p2)
    {
        if (p1.age < p2.age)
        {
            return 1;
        }
        else if (p1.age > p2.age)
        {
            return 0;
        }
        else
        {
            if (p1.nom < p2.nom)
            {
                return 1;
            }
            return 0;
        }
    }
};
ostream &operator<<(ostream &flux, const Personne &p)
{
    flux << "Nom : " << p.nom << " et âge : " << p.age << endl;
    return flux;
}

vector<Personne> LireFic();
void afficheListPers(vector<Personne> listPers);
void affiche_with_iterator(vector<Personne> listPers);
map<string, Personne> LireFic_map();
void affiche_with_iterator_map(map<string, Personne> listPers);
bool isInMap(const string &name, map<string, Personne> listPers);

int main(void)
{
    /*ex1*/
    // afficheListPers(LireFic());

    /*ex2*/
    // affiche_with_iterator(LireFic());

    /*ex3*/
    // affiche_with_iterator_map(LireFic_map());
    // cout << isInMap("toto",LireFic_map());

    /*ex4*/
    // vector<Personne> PersVect = LireFic();
    // sort(PersVect.begin(), PersVect.end(), Personne());
    // afficheListPers(PersVect);

    /*ex5*/
    return 0;
}

vector<Personne> LireFic()
{
    vector<Personne> listPers;
    ifstream monFic("file.txt");
    string name;
    int age;
    while (!monFic.fail())
    {
        monFic >> name >> age;
        if (!monFic.fail())
        {
            Personne someone(name, age);
            listPers.push_back(someone);
        }
    }
    return listPers;
}

void afficheListPers(vector<Personne> listPers)
{
    for (int i = 0; i < listPers.size(); i++)
    {
        cout << listPers[i] << endl;
    }
}

void affiche_with_iterator(vector<Personne> listPers)
{
    vector<Personne>::iterator it;
    for (it = listPers.begin(); it != listPers.end(); it++)
    {
        cout << *it << endl;
    }
}

map<string, Personne> LireFic_map()
{
    map<string, Personne> listPers;
    ifstream monFic("file.txt");
    string name;
    int age;
    while (!monFic.fail())
    {
        monFic >> name >> age;
        if (!monFic.fail())
        {
            Personne someone(name, age);
            pair<string, Personne> elem(name, someone);
            listPers.insert(elem);
        }
    }
    return listPers;
}

void affiche_with_iterator_map(map<string, Personne> listPers)
{
    map<string, Personne>::iterator it;
    for (it = listPers.begin(); it != listPers.end(); it++)
    {
        cout << "Clé : " << it->first << endl;
        cout << "Personne : " << it->second << endl;
    }
}

bool isInMap(const string &name, map<string, Personne> listPers)
{
    map<string, Personne>::iterator it;
    for (it = listPers.begin(); it != listPers.end(); it++)
    {
        if (it == listPers.find(name))
        {
            return 1;
        }
    }
    return 0;
}