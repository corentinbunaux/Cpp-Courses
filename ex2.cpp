#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

void readFic(float dist);

enum forme
{
    cercle,
    rectangle,
    carre
};

class Point
{
private:
    float x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(float abs, float ord)
    {
        x = abs;
        y = ord;
    }
    float GetX() const
    {
        return x;
    }
    float GetY() const
    {
        return y;
    }
    void SetX(float nouveauX)
    {
        x = nouveauX;
    }
    void SetY(float nouveauY)
    {
        y = nouveauY;
    }
    void Print()
    {
        cout << "Abscisse : " << x << endl;
        cout << "Ordonnée : " << y << endl;
    }
    bool IsEqual(Point &p2)
    {
        return x == p2.x && y == p2.y;
    }
    float Distance(Point &p2)
    {
        return sqrt(pow(x - p2.x, 2) + pow(y - p2.y, 2));
    }
};

class Segment
{
private:
    Point p1, p2;

public:
    Segment(Point &point1, Point &point2)
        : p1(point1.GetX(), point1.GetY()), p2(point2.GetX(), point2.GetY())
    {
    }
    void Print()
    {
        p1.Print();
        p2.Print();
    }
    void Translate(Point &new_origin)
    {
        Point new_end(0, 0);
        float d_x = p2.GetX() - p1.GetX(), d_y = p2.GetY() - p1.GetY();
        new_end.SetX(d_x + new_origin.GetX());
        new_end.SetY(d_y + new_origin.GetY());
        new_origin.Print();
        new_end.Print();
    }
    float Longueur()
    {
        return sqrt(pow(p1.GetX() - p2.GetX(), 2) + pow(p1.GetY() - p2.GetY(), 2));
    }
};

class Polygone
{
private:
    int nb_pts;
    Point tab_pts[];

public:
    Polygone(int number, Point *tab)
    {
        nb_pts = number;
        for (int i = 0; i < number; i++)
        {
            tab_pts[i].SetX(tab[i].GetX());
            tab_pts[i].SetY(tab[i].GetY());
        }
    }
    void Print()
    {
        for (int i = 0; i < nb_pts; i++)
        {
            tab_pts[i].Print();
        }
    }
    float Perimetre()
    {
        float somme = 0;
        for (int i = 1; i <= nb_pts; i++)
        {
            somme += tab_pts[i].Distance(tab_pts[i - 1]);
        }
        return somme;
    }
    Point min_X()
    {
        float min = tab_pts[0].GetX();
        for (int i = 1; i < nb_pts; i++)
        {
            if (tab_pts[i].GetX() < min)
            {
                min = tab_pts[i].GetX();
            }
        }
        for (int i = 0; i < nb_pts; i++)
        {
            if (tab_pts[i].GetX() == min)
            {
                return tab_pts[i];
            }
        }
    }
};

class Forme
{
private:
    Forme *suiv;
    forme form;
    double p = 0, s = 0;

public:
    Forme(forme form)
    {
        suiv = NULL;
        this->form = form;
    }
    void setSuiv(Forme *);
    Forme *getSuiv() const { return suiv; }
    virtual double perimetre() const = 0;
    virtual double surface() const = 0;
    virtual void afficherType() const = 0;
    void afficher() const
    {
        this->afficherType();
        cout << "Périmètre : " << this->p << endl;
        cout << "Surface : " << this->s << endl;
    }
};

class Cercle : public Forme
{
private:
    Point p;
    double rayon = 0;

public:
    Cercle(const Point &p, double r) : Forme(cercle)
    {
        this->p = p;
        this->rayon = r;
    }
    virtual double perimetre() const
    {
        return 6.28 * (this->rayon);
    }
    virtual double surface() const
    {
        return 3.14 * (pow(this->rayon, 2));
    }
    virtual void afficherType() const
    {
        cout << "cercle" << endl;
    }
};

int main(void)
{
    readFic(22);
    return 0;
}

void readFic(float dist)
{
    ifstream fic("points.txt");
    ofstream file("points2.txt");
    float abs = 0, ord = 0;
    int nb_pts = 0;
    while (!fic.fail())
    {
        fic >> abs >> ord;
        if (!fic.fail() && sqrt(pow(abs, 2) + pow(ord, 2)) <= dist)
        {
            file << setfill('0') << setw(3) << nb_pts << ": (" << abs << ", " << ord << ") d=" << fixed << setprecision(2) << sqrt(pow(abs, 2) + pow(ord, 2)) << endl;
            nb_pts++;
        }
    }
}