// Ratio.cpp

#include <iostream>
#include <cstdlib>
#include "Ratio.h"
using namespace std;

Ratio::Ratio (long nu, long de)
{
    if (de == 0) {
        cout << "denominateur nul" << endl;
        exit (0);
    }

    // on met le signe sur le numerateur
    if (de < 0) {
        nume = -nu;
        deno = -de;
    }
    else {
        nume = nu;
        deno = de;
    }

    reduire(); 
}

ostream& operator<<  (ostream& flux, const Ratio& ra)
{
    flux << ra.nume;
    if (ra.deno != 1)
        flux << "/" << ra.deno;

    return flux;
}

Ratio Ratio::operator+ (const Ratio& ra2) const
{
    long numeResult = nume * ra2.deno + ra2.nume * deno;
    long denoResult = deno * ra2.deno;
    Ratio result (numeResult, denoResult);  // le constructeur reduit result
    return result;
}

Ratio Ratio::operator- (const Ratio& ra2) const
{
    long numeResult = nume * ra2.deno - ra2.nume * deno;
    long denoResult = deno * ra2.deno;
    Ratio result (numeResult, denoResult);
    return result;
}

Ratio Ratio::operator* (const Ratio& ra2) const
{
    long numeResult = nume * ra2.nume;
    long denoResult = deno * ra2.deno;
    Ratio result (numeResult, denoResult);
    return result;
}

Ratio Ratio::operator/ (const Ratio& ra2) const
{
    long numeResult = nume * ra2.deno;
    long denoResult = deno * ra2.nume;
    Ratio result (numeResult, denoResult);
    return result;
}

Ratio& Ratio::operator+= (const Ratio& ra2)
{
    nume = nume * ra2.deno + ra2.nume * deno;
    deno = deno * ra2.deno;
    reduire();
    // on aurait pu appeler l'operateur + :
    // *this = *this + ra2;
    return *this;
}

Ratio& Ratio::operator-= (const Ratio& ra2)
{
    nume = nume * ra2.deno - ra2.nume * deno;
    deno = deno * ra2.deno;
    reduire();
    return *this;
}

Ratio& Ratio::operator*= (const Ratio& ra2)
{
    nume = nume * ra2.nume;
    deno = deno * ra2.deno;
    reduire();
    return *this;
}

Ratio& Ratio::operator/= (const Ratio& ra2)
{
    nume = nume * ra2.deno;
    deno = deno * ra2.nume;
    reduire();
    return *this;
}

bool Ratio::operator== (const Ratio& ra2) const
{
    return nume * ra2.deno == ra2.nume * deno;
}

bool Ratio::operator!= (const Ratio& ra2) const
{
    return nume * ra2.deno != ra2.nume * deno;
    // on aurait pu appeler l'operateur == precedent :
    // return !(*this == ra2);
}

bool Ratio::operator< (const Ratio& ra2) const
{
    return nume * ra2.deno < ra2.nume * deno;
}

bool Ratio::operator<= (const Ratio& ra2) const
{
    return nume * ra2.deno <= ra2.nume * deno;
}

bool Ratio::operator> (const Ratio& ra2) const
{
    return nume * ra2.deno > ra2.nume * deno;
}

bool Ratio::operator>= (const Ratio& ra2) const
{
    return nume * ra2.deno >= ra2.nume * deno;
}

float Ratio::toFloat () const
{
    // on force la division reelle
    return (float)nume / (float)deno;
}

void Ratio::reduire ()
{
    // on calcule le pgcd avec des valeurs positives
    long nu = nume;
    if (nume < 0)
        nu = -nume;

    long lePgcd = pgcd (nu, deno);
    nume = nume / lePgcd;
    deno = deno / lePgcd;
}

// on utilise l'algorithme : pgcd (x,y) = pgcd (y,reste de x/y)
long Ratio::pgcd (long x, long y)
{
    long valPgcd;

    if (x % y == 0)
        valPgcd = y;
    else
        valPgcd = pgcd (y, x % y);

    return valPgcd;
}
