#include <iostream>
using namespace std;

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

const int ANNEE_DE_BASE = 2020;

void InitDate(Date &date, int J, int M, int A = ANNEE_DE_BASE);
void AfficheDate(Date &date);
bool EqualDate(Date &date1, Date &date2);
int Surcharge(Date &date, int J, int M, int A);

int main(void)
{
    Date *date;
    date = new Date;
    InitDate(*date, 1, 1);

    Date *date2;
    date2 = new Date;
    InitDate(*date2, 2, 1);
    // AfficheDate(*date);

    bool IsEqual = EqualDate(*date, *date2);
    // cout << IsEqual;

    int IsEqual2 = Surcharge(*date, 6, 4, 2020);
    // cout << IsEqual2;

    return 0;
}

void InitDate(Date &date, int J, int M, int A)
{
    date.annee = A;
    date.mois = J;
    date.jour = J;
}

void AfficheDate(Date &date)
{
    cout << date.jour << "\t" << date.mois << "\t" << date.annee;
}

bool EqualDate(Date &date1, Date &date2)
{
    if (date1.annee == date2.annee)
    {
        if (date1.mois == date2.mois)
        {
            if (date1.jour == date2.jour)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int Surcharge(Date &date, int J, int M, int A)
{
    return date.annee == A && date.mois == M && date.jour == J;
}