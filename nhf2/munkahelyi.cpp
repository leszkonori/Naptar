#include <fstream>
#include <iomanip>
#include "munkahelyi.h"
#include "memtrace.h"
#include "gtest_lite.h"

void Munkahelyi::beolvas(ifstream& ifs) {
    string temp;
    getline(ifs, temp);
    nev = temp;
    int h, n;
    ifs >> h;
    ifs >> n;
    set_datum(h, n);
    getline(ifs, temp);
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
    int iroda;
    ifs >> iroda;
    irodaszam = iroda;
    int rvevok;
    ifs >> rvevok;
    resztvevok = rvevok;
    ifs.close();

    napra_esik = Hetnapja((datum.hanyadik_nap() % 7) -1);
}

void Munkahelyi::kiir(ofstream& ofs) const {
    ofs << setw(2) << setfill('0') <<right<< datum.get_ho() << "." << setw(2) << setfill('0') << right << datum.get_nap() << ". ";
    ofs << nev  << ", " << irodaszam << ". szamu iroda, " << resztvevok << " resztvevo" << std::endl;
}
