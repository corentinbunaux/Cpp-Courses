// String.cpp

#include <iostream>
#include <string.h>
#include <ctype.h>
#include "String.h"
using namespace std;

String::String()
{
    ch = new char[1];
    ch[0] = '\0';
}

String::String(const char* ch2)
{
    ch = new char [strlen(ch2) + 1];
    strcpy (ch, ch2);
}

String::String(const String& source)
{
    ch = new char [strlen(source.ch) + 1];
    strcpy (ch, source.ch);
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

String& String::operator= (const String& str2)
{
    /* on ne fait rien si l'objet courant et str2 representent le meme objet
     * (instruction du style s1 = s1), car dans ce cas ch et str2.ch
     * representent la meme chaine et lorsqu'on detruit ch on detruit aussi
	   * str2.ch
     */
    if (this != &str2)
    {
        delete [] ch;
        ch = new char [strlen(str2.ch) + 1];
        strcpy (ch, str2.ch);
    }

    return *this;
}

ostream& operator<<(ostream& flux, const String& str)
{
    flux << str.ch;
    return flux;
}

bool String::operator!= (const String& str2) const
{
    return !estEgal(str2);
}
