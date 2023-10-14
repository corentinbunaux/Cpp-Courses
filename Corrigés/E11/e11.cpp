// e11.cpp

#include <iostream>
#include "Deborde.h"
#include "DivZero.h"
#include "SHORT.h"
using namespace std;

int main ()
{
    long x, y;
    cout << "saisir deux valeurs : ";
    cin >> x >> y;

    try
    {
        cout << "debut du bloc try" << endl;
        SHORT s1(x), s2(y);

        cout << "somme = "     << s1 + s2 << endl;
        cout << "diff = "      << s1 - s2 << endl;
        cout << "produit = "   << s1 * s2 << endl;
        cout << "quotient = "  << s1 / s2 << endl;
        cout << "suite du bloc try" << endl;
    }
    catch (Deborde excep)
    {
        cout << endl;
        excep.afficherMsg();
        cout << excep.getVal() << endl;
    }
    catch (DivZero excep)
    {
        cout << endl;
        excep.afficherMsg();
    }
    cout << "suite du main" << endl;

    return 0;
}
