// Short.cpp

#include <iostream>
#include <climits>
#include "Deborde.h"
#include "DivZero.h"
#include "SHORT.h"
using namespace std;

SHORT::SHORT (long v)
{
    if (v > SHRT_MAX)
    {
        Deborde deb (v, "debordement par le haut");
        throw deb;
    }
    else if (v < SHRT_MIN)
    {
        Deborde deb (v, "debordement par le bas");
        throw deb;
    }
    else
        val = (short)v;
}

/* les operateurs n'ont pas besoin de tester explicitement le debordement : ils
 * font les calculs sur des "long" et retournent un objet SHORT resultat => le
 * constructeur de cet objet teste le debordement
 */

SHORT SHORT::operator+ (const SHORT& s2) const
{
    SHORT resultat (val + s2.val);
    return resultat;
}

SHORT SHORT::operator- (const SHORT& s2) const
{
    SHORT resultat (val - s2.val);
    return resultat;
}

SHORT SHORT::operator* (const SHORT& s2) const
{
    SHORT resultat (val * s2.val);
    return resultat;
}

SHORT SHORT::operator/ (const SHORT& s2) const
{
    if (s2.val == 0)
        throw DivZero("division par zero"); 
    SHORT resultat (val / s2.val);
    return resultat;
}

ostream& operator<< (ostream& flot, const SHORT& s)
{
    flot << s.val;
    return flot;
}
