#ifndef DATUM_H_INCLUDED
#define DATUM_H_INCLUDED

#include <iostream>

using namespace std;

enum Hetnapja {
    hetfo, kedd, szerda, csutortok, pentek, szombat, vasarnap
};

class Datum {
    int ho, nap;
public:
    //Konstruktor
    Datum(int h = 1, int n = 1) :ho(h), nap(n) {};

    //Getterek, setterek
    int get_ho() const { return ho; }
    int get_nap() const {return nap; }
    void set_ho(int h) { ho = h; }
    void set_nap(int n) { nap = n; }

    //Az ev hanyadik napja az adott datum
    int hanyadik_nap();
    bool operator==(Datum& rhs);
    //ket datum kozott eltelt napok szama
    int operator-(Datum rhs);
};

#endif // DATUM_H_INCLUDED
