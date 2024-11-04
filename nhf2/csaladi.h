#ifndef CSALADI_H_INCLUDED
#define CSALADI_H_INCLUDED

#include <string>
#include <fstream>
#include "esemeny.h"
#include "datum.h"

class Csaladi :public Esemeny {
    int resztvevok;
public:
    //Konstruktor
    Csaladi() :Esemeny() {
        resztvevok = 1;
    }
    Csaladi(string name, Datum date, bool f = false, bool lm = true, int rvevok = 2)
        :Esemeny(name, date, f, lm), resztvevok(rvevok) {};
    //Getter
    int getResztvevok() const;
    //Fajlmuveletek
    void kiir(ofstream& ofs) const;
    void beolvas(ifstream& ifs);
};

#endif // CSALADI_H_INCLUDED
