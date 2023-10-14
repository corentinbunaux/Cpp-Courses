// e1.cpp

#include <iostream>
using namespace std;

struct Date
{
    int jour, mois, annee;
};

struct ListeDates
{
	int nbdates;
	Date* dat;
};

const int ANNEE_BASE = 2000;

void init(Date& dat, int j, int m, int a = ANNEE_BASE);
void afficher(const Date& dat);
bool comparer(const Date& dat1, const Date& dat2);
bool comparer(const Date& dat, int j, int m, int a);

void init(ListeDates& liste, int nb);
void afficher(const ListeDates& liste);
void modifier(ListeDates& liste, int indice, const Date& nouvDate);
void liberer(ListeDates& liste);

void init(Date& dat, int j, int m, int a)
{
    dat.jour = j;
    dat.mois = m;
    dat.annee = a;
}

void afficher(const Date& dat)
{
    cout << dat.jour << "/" << dat.mois << "/" << dat.annee << endl;
}

bool comparer(const Date& dat1, const Date& dat2)
{
    if (dat1.annee == dat2.annee && dat1.mois == dat2.mois && dat1.jour == dat2.jour)
        return true;
    else
        return false;
}

bool comparer(const Date& dat, int j, int m, int a)
{
    if (dat.annee == a && dat.mois == m && dat.jour == j)
        return true;
    else
        return false;
}

void init(ListeDates& liste, int nb)
{
    liste.nbdates = nb;
    liste.dat = new Date[nb];

    for (int i = 0; i < nb; i++)
        init(liste.dat[i], 1, 1, ANNEE_BASE + i);
}

void afficher(const ListeDates& liste)
{
    cout << endl;
    for (int i = 0; i < liste.nbdates; i++)
        afficher(liste.dat[i]);
}

void modifier(ListeDates& liste, int indice, const Date& nouvDate)
{
    if (indice >= 0 && indice < liste.nbdates)
        liste.dat[indice] = nouvDate;
}

void liberer(ListeDates& liste)
{
    delete[] liste.dat;
    liste.nbdates = 0;
}

int main()
{
    int j1, m1, j2, m2, a2;

    cout << "saisir jour/mois de annee ref: ";
    cin >> j1 >> m1;
    cout << "saisir une date : ";
    cin >> j2 >> m2 >> a2;

    Date date1, date2;
    init(date1, j1, m1);
    init(date2, j2, m2, a2);

    afficher(date1);
    afficher(date2);

    if (comparer(date1,date2) == true)
        cout << "date1/date2 egales" << endl;
    if (comparer(date1, j2, m2, a2) == true)
        cout << "date1/(j2,m2,a2) egales" << endl;

    ListeDates liste;
    init(liste, 10);
    afficher(liste);

    modifier(liste, 2, date1);
    modifier(liste, 5, date2);
    modifier(liste, 20, date1); // indice incorrect
    afficher(liste);

    liberer(liste);

    return 0;
}
