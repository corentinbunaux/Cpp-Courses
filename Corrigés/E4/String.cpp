// String.cpp

#include <iostream>
#include <string.h>
#include <ctype.h>
#include "String.h"
using namespace std;

String::String(const char* ch2)
{
    ch = new char [strlen(ch2) + 1];
    strcpy (ch, ch2);
}

String::String(const String& objSource)
{
    ch = new char [strlen(objSource.ch) + 1];
    strcpy (ch, objSource.ch);
}

String::~String()
{
    delete [] ch;
}

void String::afficher() const
{
    cout << ch << endl;
}

void String::changerEnMaj()
{
    int i = 0;

    while (ch[i] != 0) {
        ch[i] = toupper(ch[i]);
        i++;
    }
}

bool String::estEgal(const String& str2) const
{
    if (strcmp(ch,str2.ch) == 0)
        return true;
    else
        return false;
}
