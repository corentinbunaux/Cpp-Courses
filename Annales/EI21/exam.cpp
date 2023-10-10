#include <iostream>
using namespace std;

class Monome
{
private:
    float coeff;
    int degre;
public:
    Monome(){}
    Monome(const float& c, const int& d) : coeff(c), degre(d){}
    float getCoeef() const{
        return coeff;
    }
    float getDegre() const{
        return degre;
    }
    friend ostream &operator<<(ostream &flux, const Monome &m){
        !m.degre ? flux << m.coeff << endl : flux << m.coeff << "X^" << m.degre << endl;
        return flux;
    }
};

class Poly
{
private:
    float *coeff;
    int degre = 0;
public:
    Poly(const int& d) : degre(d){
        coeff = new float[d];
        for(int i=0;i<d;i++){
            coeff[i] = 0;
        }
    }
    Poly(const float *tab){
        
    }
    ~Poly(){
        delete coeff;
    }
};


int main(void){
    return 0;
}