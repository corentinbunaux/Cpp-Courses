// e10.cpp

#include <iostream>
#include <string>
#include "Ensemble.h"
#include "String.h"
using namespace std;

int main ()
{
    Ensemble<int> e1;
    e1.ajouter(10);
    e1.ajouter(15);
    e1.ajouter(10);
    e1.afficher();

    Ensemble<string> e2;
    string s1("salut"), s2("bonjour");
    e2.ajouter(s1);
    e2.ajouter(s2);
    e2.ajouter("salut");
    e2.afficher();

    Ensemble<String> e3;
    String s3("salut"), s4("bonjour");
    e3.ajouter(s3);
    e3.ajouter(s4);
    e3.ajouter("salut");
    e3.afficher();

    return 0;
}
