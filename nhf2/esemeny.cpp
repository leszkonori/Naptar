#include "esemeny.h"
#include "datum.h"
#include "memtrace.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Esemeny::beolvas(ifstream& ifs) {
    getline(ifs, nev);
    int ho, nap;
    ifs >> ho;
    ifs >> nap;
    Datum d(ho, nap);
    datum = d;
    string temp;
    getline(ifs, temp);
    if (temp == "fontos") {
        fontos = true;
    } else {
        fontos = false;
    }
    getline(ifs, temp);
    if (temp == "lemondhato") {
        lemondhato = true;
    } else {
        lemondhato = false;
    }
    ifs.close();

    napra_esik = Hetnapja((datum.hanyadik_nap() % 7) -1);

}

void Esemeny::kiir(ofstream& ofs) const {
    ofs << datum.get_ho() << "." << datum.get_nap() << ". " << nev << std::endl;
}
