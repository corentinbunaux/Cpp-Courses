#include <iostream>
using namespace std;

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    int nbdates;
    Date *dat;
} ListeDates;

const int ANNEE_DE_BASE = 2020;

void InitListDates(ListeDates &list_dates, int number_dates);
void PrintListDates(ListeDates &list_dates);
void ModifyDate(ListeDates &list_dates);
void FreeListDates(ListeDates &list_dates);

int main(void)
{
    ListeDates list_dates;
    InitListDates(list_dates, 3);
    // ModifyDate(list_dates);
    // FreeListDates(list_dates);
    PrintListDates(list_dates);
    return 0;
}

void InitListDates(ListeDates &list_dates, int number_dates)
{
    list_dates.nbdates = number_dates;
    list_dates.dat = new Date[number_dates];
    for (int i = 0; i < number_dates; i++)
    {
        list_dates.dat[i].jour = 1;
        list_dates.dat[i].mois = 1;
        list_dates.dat[i].annee = ANNEE_DE_BASE;
    }
}

void PrintListDates(ListeDates &list_dates)
{
    if (!list_dates.nbdates)
    {
        cout << "Tableau vide";
    }
    else
    {
        for (int i = 0; i < list_dates.nbdates; i++)
        {
            cout << list_dates.dat[i].jour << "\t" << list_dates.dat[i].mois << "\t" << list_dates.dat[i].annee;
            cout << "\n";
        }
    }
}

void ModifyDate(ListeDates &list_dates)
{
    int position = 0, J, M, A;
    cout << "Position de la date à modifier : ";
    cin >> position;
    cout << "Nouvelle date\nJour : ";
    cin >> J;
    cout << "Mois : ";
    cin >> M;
    cout << "Année : ";
    cin >> A;
    list_dates.dat[position - 1].jour = J;
    list_dates.dat[position - 1].mois = M;
    list_dates.dat[position - 1].annee = A;

    cout << "Changement effectué";
}

void FreeListDates(ListeDates &list_dates)
{
    delete[] list_dates.dat;
    list_dates.nbdates = 0;
}