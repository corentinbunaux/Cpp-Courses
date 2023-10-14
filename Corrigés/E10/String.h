// String.h

#pragma once 
#include <iostream>
using namespace std;

class String
{
public :
    String();
    String(const char* ch2);
    String(const String& source);
    ~String();
    void afficher() const;
    void changerEnMaj();
    bool estEgal(const String& str2) const;
    String& operator= (const String& str2);
    friend ostream& operator<<(ostream& flux, const String& str);
    bool operator!= (const String& str2) const;

private :
    char* ch;
};
