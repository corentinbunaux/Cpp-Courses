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

int main(void)
{
    ListeDates list_dates;
    InitListDates(list_dates, 3);
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
        list_dates.dat[i].jour = ANNEE_DE_BASE;
    }
}

void PrintListDates(ListeDates &list_dates)
{
    for (int i = 0; i < list_dates.nbdates; i++)
    {
        cout << list_dates.dat[i].jour << list_dates.dat[i].mois << list_dates.dat[i].annee;
        cout << "\n";
    }
}