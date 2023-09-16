#include <iostream>
using namespace std;

#define NOMBRE_ELEM 5

class Ensemble
{
public:
    Ensemble()
    {
        for (int i = 0; i < NOMBRE_ELEM; i++)
        {
            tab[i] = -1;
        }
    }
    void Add(int number)
    {
        for (int i = 0; i < NOMBRE_ELEM; i++)
        {
            if (tab[i] == -1)
            {
                tab[i] = number;
                return;
            }
        }
    }
    void Del(int number)
    {
        for (int i = 0; i < NOMBRE_ELEM; i++)
        {
            if (tab[i] == number)
            {
                tab[i] = -1;
                return;
            }
        }
    }
    bool IsIn(int number)
    {
        for (int i = 0; i < NOMBRE_ELEM; i++)
        {
            if (tab[i] == number)
            {
                return true;
            }
        }
        return false;
    }
    void Print() const
    {
        for (int i = 0; i < NOMBRE_ELEM; i++)
        {
            cout << tab[i] << endl;
        }
    }
    bool IsEqual(Ensemble &e2) const
    {
        for (int i = 0; i < NOMBRE_ELEM; i++)
        {
            if (!e2.IsIn(tab[i]))
            {
                return false;
            }
        }
        return true;
    }

    Ensemble Intersect(Ensemble &e2) const
    {
        Ensemble ens;
        for (int i = 0; i < NOMBRE_ELEM; i++)
        {
            for (int j = 0; j < NOMBRE_ELEM; j++)
            {
                if (tab[i] == e2.tab[j])
                {
                    ens.Add(tab[i]);
                }
            }
        }
        return ens;
    }

private:
    int tab[NOMBRE_ELEM];
};

int main(void)
{
    Ensemble e1;
    Ensemble e2;

    e1.Add(1);
    e2.Add(2);
    e2.Add(1);

    Ensemble intersect = e1.Intersect(e2);
    intersect.Print();
    return 0;
}