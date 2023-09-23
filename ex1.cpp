#include <iostream>
#include <math.h>
using namespace std;

void fonction(int q, int N);

class Rationnel
{
private:
    int num, den;
    int PGCD(int a, int b)
    {
        int pgcd = 1;
        (!(b % a)) ? pgcd = b : pgcd = PGCD(b, (b % a));
        return pgcd;
    }

public:
    Rationnel()
    {
        this->den = 1;
    }
    Rationnel(int nume, int deno)
    {
        this->num = nume;
        this->den = deno;
    }
    friend ostream &operator<<(ostream &flux, const Rationnel &r);
    Rationnel operator+(Rationnel &r)
    {
        Rationnel rat(num * r.den + den * r.num, den * r.den);
        return rat;
    }
    Rationnel operator+=(Rationnel &r)
    {
        *this = *this + r;
        return *this;
    }
    Rationnel operator-(Rationnel &r)
    {
        int nume = this->num * r.den - this->den * r.num, deno = this->den * r.den;
        Rationnel rat(nume, deno);
        return rat;
    }
    Rationnel operator*(Rationnel &r)
    {
        Rationnel rat(this->num * r.num, this->den * r.den);
        return rat;
    }
    Rationnel operator/(Rationnel &r)
    {
        Rationnel rat(this->num * r.den, this->den * r.num);
        return rat;
    }
    Rationnel operator/(int entier)
    {
        Rationnel rat(this->num, this->den * entier);
        return rat;
    }
    Rationnel operator-=(Rationnel &r)
    {
        *this = *this - r;
        return *this;
    }
    Rationnel operator/=(Rationnel &r)
    {
        *this = *this / r;
        return *this;
    }
    Rationnel operator*=(Rationnel &r)
    {
        *this = *this * r;
        return *this;
    }
    bool operator<=(Rationnel &r)
    {
        return (this->num) * r.den <= r.num * this->den;
    }
    bool operator>=(Rationnel &r)
    {
        return (this->num) * r.den >= r.num * this->den;
    }
    bool operator<(Rationnel &r)
    {
        return (this->num) * r.den < r.num * this->den;
    }
    bool operator>(Rationnel &r)
    {
        return (this->num) * r.den > r.num * this->den;
    }
    bool operator!=(Rationnel &r)
    {
        return (this->num) * r.den != r.num * this->den;
    }
    float toInt()
    {
        float n = num, d = den;
        return n / d;
    }
    void UnVn(Rationnel &v, int N)
    {
        cout << "u0 vaut : " << this->toInt() << endl;
        cout << "v0 vaut : " << v.toInt() << endl;

        for (int n = 1; n <= N; n++)
        {
            *this = (*this + v) / 2;
            v.num = 2 * (this->den);
            v.den = this->num;
            cout << "un - vn = " << (*this - v).toInt() << " < " << 1 / (pow(4, n)) << endl;
        }
    }
};

int main(void)
{
    /*Partie 2*/
    /*
    Rationnel un(2, 1);
    Rationnel vn(1, 1);
    un.UnVn(vn, 5);
    */
    return 0;
}

ostream &operator<<(ostream &flux, const Rationnel &r)
{
    (!r.num) ? flux << r.num << endl : flux << r.num << "/" << r.den << endl;
    return flux;
}

void fonction(int q, int N)
{
    float u = 1;
    for (int n = 1; n <= N + 1; n++)
    {
        cout << u << endl;
        u = u + (1 / pow(q, n));
    }
}