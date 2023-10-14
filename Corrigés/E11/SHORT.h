// Short.h

#pragma once
#include <iostream>
using namespace std;

class SHORT
{
public :
    SHORT (long v);
    friend ostream& operator<< (ostream& flot, const SHORT& s);
    SHORT operator+ (const SHORT& s2) const;
    SHORT operator- (const SHORT& s2) const;
    SHORT operator* (const SHORT& s2) const;
    SHORT operator/ (const SHORT& s2) const;

private :
    short val;
};
