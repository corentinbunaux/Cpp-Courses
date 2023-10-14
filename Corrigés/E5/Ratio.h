// Ratio.h

#pragma once
#include <iostream>
using namespace std;

class Ratio
{
public :
    Ratio (long nu, long de = 1);

    friend ostream& operator<<  (ostream& flux, const Ratio& ra);

    Ratio operator+ (const Ratio& ra2) const;
    Ratio operator- (const Ratio& ra2) const;
    Ratio operator* (const Ratio& ra2) const;
    Ratio operator/ (const Ratio& ra2) const;

    Ratio& operator+= (const Ratio& ra2);
    Ratio& operator-= (const Ratio& ra2);
    Ratio& operator*= (const Ratio& ra2);
    Ratio& operator/= (const Ratio& ra2);

    bool operator== (const Ratio& ra2) const;
    bool operator!= (const Ratio& ra2) const;
    bool operator< (const Ratio& ra2) const;
    bool operator<= (const Ratio& ra2) const;
    bool operator> (const Ratio& ra2) const;
    bool operator>= (const Ratio& ra2) const;

    float toFloat() const;  // conversion en reel

private :
    long nume;    // numerateur
    long deno;    // denominateur

    void reduire ();    // reduit la fraction nume/deno

    /* retourne le pgcd de x et y;
     * fonction statique car n'a pas besoin d'un objet Ratio pour etre appelee
     */
    static long pgcd (long x, long y);
};
