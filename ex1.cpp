#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
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

class Point
{
public:
    Point();
    Point(float x0, float y0);
    float getX() const          { return x; }
    float getY() const          { return y; }
    void setX(float nouvX)      { x = nouvX; }
    void setY(float nouvY)      { y = nouvY; }
    void afficher() const;
    bool egalA(const Point& point2) const;
    float distance(const Point& point2) const;

private:
    float x, y;
};
Point::Point()
{
    x = 0;
    y = 0;
}
Point::Point(float x0, float y0)
{
    x = x0;
    y = y0;
}
void Point::afficher() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}
bool Point::egalA(const Point& point2) const
{
    if (x == point2.x && y == point2.y)
        return true;
    else
        return false;
}
float Point::distance(const Point& point2) const
{
    float dx = x - point2.x;
    float dy = y - point2.y;
    return sqrt(dx * dx + dy * dy);
}

list<Point> LireFic_list();
void affiche_list(list<Point> listPts);

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
    affiche_list(LireFic_list());
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

list<Point> LireFic_list()
{
    list<Point> listPts;
    ifstream monFic("points.txt");
    float abs, ord;
    while (!monFic.fail())
    {
        monFic >> abs >> ord;
        if (!monFic.fail())
        {
            Point pt(abs, ord);
            listPts.push_back(pt);
        }
    }
    return listPts;
}

void affiche_list(list<Point> listPts)
{
    list<Point>::iterator it;
    for (it = listPts.begin(); it != listPts.end(); it++)
    {
        it->afficher();
    }
}