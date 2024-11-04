#ifndef MUNKAHELYI_H_INCLUDED
#define MUNKAHELYI_H_INCLUDED

#include <string>
#include <fstream>
#include "esemeny.h"
#include "datum.h"


class Munkahelyi  :public Esemeny {
    int irodaszam;
    int resztvevok;
public:
    //Konstruktor
    Munkahelyi() :Esemeny() {
        irodaszam = 1;
        resztvevok = 1;
    }
    Munkahelyi(string name, Datum date, bool f = false, bool lm = true, int iroda = 1, int rvevok = 2)
    :Esemeny(name, date, f, lm), irodaszam(iroda), resztvevok(rvevok) {}
    //Getterek
    int getIrodaszam() const;
    int getResztvevok() const;
    //Fajlmuveletek
    void kiir(ofstream& ofs) const;
    void beolvas(ifstream& ifs);
};


#endif // MUNKAHELYI_H_INCLUDED
