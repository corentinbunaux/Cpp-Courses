#include <iostream>
#include <math.h>
using namespace std;

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
    float enveloppe()
    {
        Point p0 = min_X();
    }
};

int main(void)
{
    /*Partie 1*/
    /*
    Point p(3.14, 6.48);
    p.Print();

    p.SetX(2.1);
    p.SetY(2.2);

    cout << p.GetX() << p.GetY() << endl;

    Point p2(6.48, 3.14);
    cout << p.IsEqual(p2) << endl;
    cout << p.Distance(p2) << endl;
    */

    /*Partie 2*/
    /*
    Point p1(0, 0), p2(1, 2), p3(4, 6);
    Segment seg(p1, p2);
    seg.Print();
    seg.Translate(p3);
    */

    /*Partie 3*/
    /*
    Point pts[4] = {Point(0, 0), Point(0, 4), Point(2, 2), Point(4, 2)};
    Polygone pol(4, pts);
    pol.Print();
    cout << "Périmètre : " << pol.Perimetre() << endl;
    */
    /*Partie 4*/
    /*
    Point pts[4] = {Point(0, 0), Point(0, 4), Point(2, 2), Point(4, 2)};
    Polygone pol(4, pts);
    */
    return 0;
}
