#ifndef ESEMENY_H_INCLUDED
#define ESEMENY_H_INCLUDED

#include <iostream>
#include <fstream>
#include "datum.h"

using std::string;

class Esemeny {
protected:
    Esemeny* kov;
    string nev;
    Datum datum;
    Hetnapja napra_esik;
    bool fontos;
    bool lemondhato;

public:
    //Konstruktor
    Esemeny() {
        kov = NULL;
        nev = "";
        datum.set_ho(1);
        datum.set_nap(1);
        napra_esik = Hetnapja(1);
        fontos = false;
        lemondhato = true;
    }
    Esemeny(string name, Datum date, bool f = false, bool lm = true)
        :nev(name), datum(date), fontos(f), lemondhato(lm) {
            kov = NULL;
            napra_esik = get_napra_esik();
        };

    //Getterek-setterek
    Esemeny* get_kov() const { return kov; }
    string get_nev() const { return nev; }
    Datum get_datum() const { return datum; }
    Hetnapja get_napra_esik() const { return napra_esik; }
    bool fontos_e() { return fontos; }
    bool lemondhato_e() { return lemondhato; }

    void set_kov(Esemeny* rhs) { kov = rhs; }
    void set_nev(string& n) {nev = n;}
    void set_datum(int h, int n) {datum.set_ho(h); datum.set_nap(n);}

    //Fajlmuveletek
    virtual void beolvas(ifstream& ifs);
    virtual void kiir(ofstream& ofs) const;

    //Operatorok
    bool operator==(Esemeny& rhs);

    //Destruktor
    virtual ~Esemeny() {

    }
};

#endif // ESEMENY_H_INCLUDED
