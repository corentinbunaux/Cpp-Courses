#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;

enum Unite
{
    RAD,
    DEG
};

enum TypeCoord
{
    CART,
    POL
};

class BasicAngle
{
private:
    double val;

public:
    BasicAngle() : val(0) {}
    BasicAngle(const double &a)
    {
        fmod(a, 2 * M_PI) > M_PI ? val = fmod(a, 2 * M_PI) - 2 * M_PI : (fmod(a, 2 * M_PI) < (-1) *M_PI ? val = fmod(a, 2 * M_PI) + 2 *M_PI : val = fmod(a, 2 * M_PI));
    }
    friend ostream &operator<<(ostream &flux, const BasicAngle &a)
    {
        flux << a.val;
        return flux;
    }
    double getRadians() const
    {
        return this->val;
    }
    void setRadian(double v)
    {
        fmod(v, 2 * M_PI) > M_PI ? val = fmod(v, 2 * M_PI) - 2 * M_PI : (fmod(v, 2 * M_PI) < (-1) *M_PI ? val = fmod(v, 2 * M_PI) + 2 *M_PI : val = fmod(v, 2 * M_PI));
    }
};

class Angle : public BasicAngle
{
public:
    Angle() : BasicAngle() {}
    Angle(const double &v) : BasicAngle(v) {}
    Angle(const double &v, const Unite &u) : BasicAngle(v)
    {
        if (u)
        {
            this->setRadian(v * 2 * M_PI / 360);
        }
    }
    double getDegre() const
    {
        return this->getRadians() * 360 / (2 * M_PI);
    }
    void setDegre(double v)
    {
        this->setRadian(v * 2 * M_PI / 360);
    }
    void affiche(Unite u) const
    {
        u ? cout << this->getDegre() << "DEG" << endl : cout << this->getRadians() << "RAD" << endl;
    }
    friend Angle operator+(const Angle &a1, const Angle &a2)
    {
        return a1.getRadians() + a2.getRadians();
    }
    friend Angle operator*(const Angle &a, const float &f)
    {
        return a.getRadians() * f;
    }
    double sinus() const
    {
        return sin(this->getRadians());
    }
    double cosinus() const
    {
        return cos(this->getRadians());
    }
    double tangeante() const
    {
        return tan(this->getRadians());
    }
    static Angle arcsin(double x)
    {
        Angle a(asin(x));
        return a;
    }
    static Angle arccos(double x)
    {
        Angle a(acos(x));
        return a;
    }
    static Angle tangeante(double x)
    {
        Angle a(atan(x));
        return a;
    }
    static Angle arctan2(double y, double x)
    {
        Angle a(atan2(y, x));
        return a;
    }
};

class Point
{
private:
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    Point(double r, Angle &a) : x(r * a.cosinus()), y(r * a.sinus()) {}
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    double getR() const
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    Angle getT() const
    {
        Angle a(acos(x / this->getR()));
        return a;
    }
    void setX(double newX)
    {
        x = newX;
    }
    void setY(double newY)
    {
        y = newY;
    }
    void setR(double newR)
    {
        x = newR * (this->getT().cosinus());
        y = newR * (this->getT().sinus());
    }
    void setT(const Angle &newT)
    {
        x = this->getR() * cos(newT.getRadians());
        y = this->getR() * sin(newT.getRadians());
    }
    void afficher(TypeCoord type_coord) const {
        type_coord ? cout << this->getR() << "exp(i" << this->getT() << ")" << endl : cout << "(" << this->getX() << "," << this->getY() << ")" << endl;
    }
    float dist(const Point& p1, const Point& p2){
        return(sqrt((pow(p1.getX() - p2.getX(),2))+(pow(p1.getY() - p2.getY(),2))));
    }
};

class Chemin
{
private:
    vector <Point> points;
public:
    Chemin(const char* nomFic, TypeCoord type_coord){
        ifstream file(nomFic);
        while(!file.fail()){
            Point p;
            if(!type_coord){
                double abs,ord;
                file >> abs >> ord;
                p.setX(abs);
                p.setY(ord);
            }
            else{
                double r;
                double val;
                file >> r >> val;
                Angle a(val);
                p.setR(r);
                p.setT(a);
            }
            if(!file.fail()){
                points.push_back(p);
            }
        }
    }
    void afficher(TypeCoord type_coord) const{
        for(int i=0;i<points.size();i++){
            points[i].afficher(type_coord);
        }
    }
};


int main(void)
{
    Chemin chem("points.txt", POL);
    chem.afficher(POL);
    return 0;
}