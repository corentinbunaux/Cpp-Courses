#include <iostream>
#include <math.h>
using namespace std;

class Monome
{
private:
    float coeff;
    int degre;

public:
    Monome() {}
    Monome(const float &c, const int &d) : coeff(c), degre(d) {}
    float getCoeef() const
    {
        return coeff;
    }
    float getDegre() const
    {
        return degre;
    }
    friend ostream &operator<<(ostream &flux, const Monome &m)
    {
        !m.degre ? flux << m.coeff << endl : flux << m.coeff << "X^" << m.degre << endl;
        return flux;
    }
};

class Poly
{
private:
    float *coeff;
    int degre = 0;

public:
    Poly(const int &d) : degre(d)
    {
        coeff = new float[d];
        for (int i = 0; i < d; i++)
        {
            coeff[i] = 0;
        }
    }
    Poly(const float *tab, int deg) : degre(deg)
    {
        coeff = new float[deg];
        for (int i = 0; i < deg; i++)
        {
            coeff[i] = tab[i];
        }
    }
    Poly(const Monome *m, int deg) : degre(deg)
    {
        coeff = new float[deg];
        for (int i = 0; i < deg; i++)
        {
            m[i].getCoeef() ? coeff[i] = m[i].getCoeef() : coeff[i] = 0;
        }
    }
    Poly(const Poly &p) : degre(p.degre)
    {
        coeff = new float[degre];
        for (int i = 0; i < degre; i++)
        {
            coeff[i] = p.coeff[i];
        }
    }
    ~Poly()
    {
        delete coeff;
    }
    Poly operator=(const Poly &p)
    {
        this->degre = p.degre;
        for (int i = 0; i < degre; i++)
        {
            this->coeff[i] = p.coeff[i];
        }
        return *this;
    }
    friend ostream &operator<<(ostream &flux, const Poly &p)
    {
        for (int i = 0; i < p.degre; i++)
        {
            if (p.coeff[i] && i)
            {
                flux << p.coeff[i] << "X^" << i << " ";
            }
            else if (p.coeff[i] && !i)
            {
                flux << p.coeff[i] << " ";
            }
        }
        flux << endl;
        return flux;
    }
    int getDegre() const
    {
        return degre;
    }
    float getCoeff(int deg) const
    {
        return coeff[deg - 1];
    }
    void setCoeff(int deg, float valCoeff)
    {
        coeff[deg - 1] = valCoeff;
    }
    int ajustDeg()
    {
        for (int i = degre; i > 0; i--)
        {
            if (!coeff[i])
            {
                degre--;
            }
            else
            {
                return 1;
            }
        }
        return 0; // error
    }
    float evaluer(float x) const
    {
        float res = 0;
        for (int i = 0; i < degre; i++)
        {
            res += coeff[i] * (pow(x, i));
        }
        return res;
    }
};

class Polynome
{
private:
    Poly p;
public:
    Polynome(const int &d) : p(d){}
    Polynome(const float *tab, int deg) : p(tab, deg){}
    Polynome(const Monome *m, int deg) : p(m,deg){}
    Polynome(const Poly &p) : p(p){}
    friend Polynome operator*(const float& r, Polynome &poly){
        for(int i=0;i<poly.p.getDegre();i++){
            poly.p.setCoeff(i,r*(poly.p.getCoeff(i)));
        }
        return poly;
    }
    friend Polynome operator+(const Polynome& p1, const Polynome& p2){
        int max_deg=0, min_deg=0;
        (p1.p.getDegre() > p2.p.getDegre()) ? max_deg = p1.p.getDegre() : max_deg = p2.p.getDegre();
        float tab_coeff[max_deg];
        for(int i=0;i<max_deg;i++){
            tab_coeff[i] = p1.p.getCoeff(i) + p2.p.getCoeff(i);
        }
        Polynome p3(tab_coeff, max_deg);
        return p3;
    }
    friend Polynome operator-(const Polynome& p1, const Polynome& p2){
        int max_deg=0, min_deg=0;
        (p1.p.getDegre() > p2.p.getDegre()) ? max_deg = p1.p.getDegre() : max_deg = p2.p.getDegre();
        float tab_coeff[max_deg];
        for(int i=0;i<max_deg;i++){
            tab_coeff[i] = p1.p.getCoeff(i) - p2.p.getCoeff(i);
        }
        Polynome p3(tab_coeff, max_deg);
        return p3;
    }
    float operator()(float x) const{
        return p.evaluer(x);
    }
};


int main(void)
{
    float t[5] = {2, 0, 0, -5, 3};
    Polynome p(t, 5);
    return 0;
}