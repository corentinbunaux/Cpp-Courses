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
    SHORT operator+(SHORT &s)
    {
        if (val + s.val > 32767)
        {
            Deborde deb(val + s.val, "débordement positif");
            throw deb;
            return 0;
        }
        else
        {
            return this->val + s.val;
        }
    }
    SHORT operator-(SHORT &s)
    {
        if (val - s.val < -32767)
        {
            Deborde deb(val - s.val, "débordement négatif");
            throw deb;
            return 0;
        }
        else
        {
            return this->val - s.val;
        }
    }
    SHORT operator*(SHORT &s)
    {
        if (val * s.val > 32767)
        {
            Deborde deb(val * s.val, "débordement positif");
            throw deb;
            return 0;
        }
        else
        {
            return this->val * s.val;
        }
    }
    SHORT operator/(SHORT &s)
    {
        if (!s.val)
        {
            Deborde deb(this->val / s.val, "division par 0");
            throw deb;
            return 0;
        }
        else
        {
            return this->val / s.val;
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