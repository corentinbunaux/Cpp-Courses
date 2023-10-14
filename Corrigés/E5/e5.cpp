// e5.cpp

#include <iostream>
#include "Ratio.h"
using namespace std;

void suiteGeometrique(int q, int N);
void suitesUV(int N);

// sans ajouter d'operateur on peut faire des operations ou le deuxieme operande
// est un entier (r + 5); en effet celui-ci est le parametre de l'operateur et
// il est converti automatiquement en un objet Ratio grace au constructeur Ratio(long)

// une operation ou le premier operande est entier (5 + r) n'est pas acceptee,
// sauf si on ajoute une version fonction amie de l'operateur ou l'entier est
// en premier parametre
//    friend Ratio operator+ (long a, const Ratio& r)

// dans les suites on atteint rapidement (surtout dans u et v du IV) la limite
// d'un long et les valeurs deviennent incoherentes

void suiteGeometrique(int q, int N)
{
    int n = 1;
    Ratio u(1);     // terme courant de la suite
    Ratio qinv(1);  // puissance de 1/q

    while (n <= N) {
        cout << "n=" << n << " u=" << u << " " << u.toFloat() << endl;
        n++;
        qinv /= q;
        u += qinv;
    } 
}

void suitesUV(int N)
{
    int n = 0;
    Ratio u(2), v(0);   // termes courants des suites u et v;
                        // v non encore calcule
    Ratio epsilon(1);   // puissance de 1/4

    while (n <= N) {
        v = Ratio(2) / u;
        cout << "n=" << n << endl
                << "u=" << u << " " << u.toFloat() << endl
                << "v=" << v << " " << v.toFloat() << endl
                << "u-v=" << (u-v).toFloat() << endl
                << "epsilon=" << epsilon.toFloat() << endl;
        n++;
        u = (u + v) / 2;
        epsilon /= 4;
    } 
}

int main()
{
    Ratio r1(18,-4), r2(9);

    cout << r1 << " , " << r2 << endl;

    Ratio r3(3,5), r4(5), r5(-4,3), r6(2,3);

    cout << r1 + r3 << endl;
    cout << r1 - r4 << endl;
    cout << r1 * r5 << endl;
    cout << r1 / r6 << endl;

    r2 += r3;
    r2 -= r4;
    r2 *= r5;
    r2 /= r6;
    cout << r2 << endl;

    Ratio r7(-46,5);
    if (r2 == r7 && r2 != r1
        && r2 < r1 && r2 < r3 && r3 < r6 && r2 <= r7 && r2 <= r1
        && r1 > r2 && r3 > r2 && r6 > r3 && r2 >= r7 && r1 >= r2)
        cout << "comparaisons ok" << endl;

    r1 = Ratio(-3,2);
    r2 = Ratio(6,21);
    cout << r1 << " = " << r1.toFloat() << endl;
    cout << r2 << " = " << r2.toFloat() << endl;

    //Ratio r8(5,0);    // test erreur denominateur nul
    //cout << r8 << endl;

    cout << endl;
    suiteGeometrique(5, 20);

    cout << endl;
    suitesUV(10);

    return 0;
}
