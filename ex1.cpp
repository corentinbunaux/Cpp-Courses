#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Personne
{
private:
    string nom;
    int age;
public:
    Personne(string &s, int &a){
        this->nom = s;
        this->age = a;
    }
    friend ostream &operator<<(ostream &flux, const Personne &p);
};
ostream &operator<<(ostream &flux, const Personne &p)
{
    flux << "Nom : " << p.nom << " et âge : " << p.age << endl;
    return flux;
}

vector <Personne> LireFic();
void afficheListPers(vector <Personne> listPers);

int main(void){
    afficheListPers(LireFic());
    return 0;
}

vector <Personne> LireFic(){
    vector <Personne> listPers;
    ifstream monFic("file.txt");
    string name;
    int age;
    while(!monFic.fail()){
        monFic >> name >> age;
        if(!monFic.fail()){
        Personne someone(name,age);
        listPers.push_back(someone);
        }
    }
    return listPers;
}

void afficheListPers(vector <Personne> listPers){
    for(int i=0;i<listPers.size();i++){
        cout << listPers[i] << endl;
    }
}

