#include <iostream>
#include <cstring>
using namespace std;

class Deborde
{
private:
    long vdeb;
    char msg[100];

public:
    Deborde(long vd, const char *m)
    {
        vdeb = vd;
        strcpy(msg, m);
    }
    long getVal() const { return vdeb; }
    void afficherMsg() const
    {
        cout << msg << endl;
    }
};

class SHORT
{
private:
    short val;

public:
    SHORT(long v)
    {
        if (v > 32767)
        {
            Deborde deb1(v, "débordement positif");
            throw deb1;
        }
        else if (v < -32767)
        {
            Deborde deb2(v, "débordement négatif");
            throw deb2;
        }
        else
        {
            val = (short)v;
        }
    }
    friend ostream &operator<<(ostream &flux, const SHORT &s);

    friend SHORT operator+(const SHORT &s1, const SHORT &s2)
    {
        if (s1.val + s2.val > 32767)
        {
            Deborde deb(s1.val + s2.val, "débordement positif");
            throw deb;
            return 0;
        }
        else
        {
            return s1.val + s2.val;
        }
    }
    friend SHORT operator-(const SHORT &s1, const SHORT &s2)
    {
        if (s1.val - s2.val < -32767)
        {
            Deborde deb(s1.val - s2.val, "débordement négatif");
            throw deb;
            return 0;
        }
        else
        {
            return s1.val - s2.val;
        }
    }
    friend SHORT operator*(const SHORT &s1, const SHORT &s2)
    {
        if (s1.val * s2.val > 32767)
        {
            Deborde deb(s1.val * s2.val, "débordement positif");
            throw deb;
            return 0;
        }
        else
        {
            return s1.val * s2.val;
        }
    }
    friend SHORT operator/(const SHORT &s1, const SHORT &s2)
    {
        if (!s1.val)
        {
            Deborde deb(s1.val / s2.val, "division par 0");
            throw deb;
            return 0;
        }
        else
        {
            return s1.val / s2.val;
        }
    }
};
ostream &operator<<(ostream &flux, const SHORT &s)
{
    flux << s.val << endl;
    return flux;
}

int main(void)
{
    try
    {
        SHORT s(40);
    }
    catch (Deborde ex)
    {
        cout << ex.getVal() << endl;
        ex.afficherMsg();
    }
    return 0;
}