#include <iostream>
using namespace std;

int PGCD(int a, int b);

class Rationnel
{
private:
    int num, den;

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
        int nume = this->num * r.den + this->den * r.num, deno = this->den * r.den;
        Rationnel rat((nume / PGCD(nume, deno)), (deno / PGCD(nume, deno)));
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
    Rationnel operator<=(Rationnel &r) {}
    Rationnel operator>=(Rationnel &r) {}
    Rationnel operator<(Rationnel &r) {}
    Rationnel operator>(Rationnel &r) {}
    Rationnel operator!=(Rationnel &r) {}
};

int main(void)
{
    Rationnel r1(1, 3);
    Rationnel r2(1, 3);
    return 0;
}

ostream &operator<<(ostream &flux, const Rationnel &r)
{
    (!r.num) ? flux << r.num << endl : flux << r.num << "/" << r.den << endl;
    return flux;
}

int PGCD(int a, int b)
{
    int pgcd = 1;
    (!(b % a)) ? pgcd = b : pgcd = PGCD(b, (b % a));
    return pgcd;
}