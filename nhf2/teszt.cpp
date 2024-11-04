#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "gtest_lite.h"
#include "memtrace.h"
#include "datum.h"
#include "naptar.h"
#include "esemeny.h"
#include "munkahelyi.h"
#include "csaladi.h"

using namespace std;

//Esemeny hozzaadasa a Naptarhoz
void teszt1(Naptar& naptar) {
    ifstream fajl("3.txt");
    string esemtipus;
    //ha a fajlt nem sikerul megnyitni
    if (!fajl.is_open()){
       throw runtime_error("A fajlt nem lehetett megnyitni.");
    }
    //itt kovetkezik az esemeny felvetele
    getline(fajl, esemtipus); //csak ketfele lehet az esemeny tipusa
    if (esemtipus == "Munkahelyi") {
        Munkahelyi* m = new Munkahelyi;
        m->beolvas(fajl);
        naptar.foglal(m);
    } else {
        Csaladi* cs = new Csaladi;
        cs->beolvas(fajl);
        naptar.foglal(cs);
    }
    TEST(Foglalas, foglalt-e)
            Datum x(5,10);
            Datum y(2, 3);
            EXPECT_EQ(true, naptar.foglalt_e(x));
            EXPECT_EQ(false, naptar.foglalt_e(y));
    END

   ifstream fajl2("1.txt");
    if (!fajl2.is_open()){
       throw runtime_error("A fajlt nem lehetett megnyitni.");
    }
    getline(fajl2, esemtipus);
    if (esemtipus == "Munkahelyi") {
        Munkahelyi* m2 = new Munkahelyi;
        m2->beolvas(fajl2);
        naptar.foglal(m2);
    } else {
        Csaladi* cs2 = new Csaladi;
        cs2->beolvas(fajl2);
        naptar.foglal(cs2);
    }

    ifstream fajl3("8.txt");
    if (!fajl3.is_open()){
       throw runtime_error("A fajlt nem lehetett megnyitni.");
    }
    getline(fajl3, esemtipus);
    if (esemtipus == "Munkahelyi") {
        Munkahelyi* m3 = new Munkahelyi;
        m3->beolvas(fajl3);
        naptar.foglal(m3);
    } else {
        Csaladi* cs3 = new Csaladi;
        cs3->beolvas(fajl3);
        naptar.foglal(cs3);
    }

    ifstream fajl4("7.txt");
    if (!fajl4.is_open()){
       throw runtime_error("A fajlt nem lehetett megnyitni.");
    }
    getline(fajl4, esemtipus);
    if (esemtipus == "Munkahelyi") {
        Munkahelyi* m4 = new Munkahelyi;
        m4->beolvas(fajl4);
        naptar.foglal(m4);
    } else {
        Csaladi* cs4 = new Csaladi;
        cs4->beolvas(fajl4);
        naptar.foglal(cs4);
    }

    TEST(Beolvasas, 1.txt)
            string nev = "Meeting a fonokkel\0";
            EXPECT_EQ(nev, naptar.get_ptr()->get_nev());
    END
    TEST(Beolvasas, 3.txt)
            EXPECT_EQ(5, naptar.get_ptr()->get_kov()->get_datum().get_ho());
    END
    TEST(Beolvasas, darab)
        int meret = naptar.size();
        EXPECT_EQ(4, meret);
    END
    TEST(Datum, napra_esik)
        Datum x(1,1);
        Hetnapja aktual = Hetnapja(x.hanyadik_nap() % 7 - 1);
        EXPECT_EQ(hetfo, aktual);
    END
}

///Ket datum kozott eltelt napok szama
void teszt2() {
    cout << "Melyik ket datum kulonbseget szeretne?\n";
    cout << "Egyik datum: ";
    Datum a;
    int h, n;
    cin >> h; a.set_ho(h);
    cin >> n; a.set_nap(n);
    cout << "Masik datum: ";
    Datum b;
    cin >> h; b.set_ho(h);
    cin>> n; b.set_nap(n);
    int kulonbseg;
    kulonbseg = abs(a-b);
    TEST(Datum, kulonbseg)
        Datum x(1,1);
        Datum y(1, 31);
        int k = x-y;
        EXPECT_EQ(-30, k);
    END
    cout << kulonbseg << " nap telik el a ket megadott datum kozott." << endl;
    TEST(Datum, hanyadik)
        Datum d(12, 31);
        EXPECT_EQ(365, d.hanyadik_nap());
    END
}

//Eddig lefoglalt datumok felsorolasa
void teszt3(Naptar& naptar) {
    teszt1(naptar); //a teszt így 3 esemennyel dolgozik
    naptar.felsorol();
    naptar.torol();
}

///Ket datum osszehasonlitasa
void teszt4(Naptar& naptar) {
    teszt1(naptar); //legyen elegendo esemeny a teszthez

    cout << "Melyik ket datumot szeretne osszehasonlitani?\n";
    cout << "Egyik datum: ";
    Datum a;
    int h, n;
    cin >> h; a.set_ho(h);
    cin >> n; a.set_nap(n);
    cout << "Masik datum: ";
    Datum b;
    cin >> h; b.set_ho(h);
    cin>> n; b.set_nap(n);
    if(naptar.hasonlit(a, b)) {
        cout << "A ket nap programja megegyezik." << endl;
    } else {
        cout << "A ket nap kulonbozo esemenyeket tartalmaz." << endl;
    }
    TEST(Naptar, hasonlit)
        Datum x(1,1);
        Datum y(5,10);
        EXPECT_EQ(false, naptar.hasonlit(x, y));
    END
}

//Naptar mentese nyomtatasra
void teszt5(Naptar& naptar) {
    teszt1(naptar); //legyen elegendo esemeny a teszthez
    cout << "Milyen bontasban szeretne menteni a naptart?\n";
    cout << "1: havi\n";
    cout << "2: eves\n";
    int valasz;
    cin >> valasz;
    if (valasz == 1) {
        cout << "Hanyadik honapot szeretne?\n";
        int hanyadik;
        cin >> hanyadik;
        naptar.havi(hanyadik);
    }
    if (valasz == 2) {
        naptar.eves();
    }
    cout << "A naptar mentese befejezodott." << endl;
}

void menu() {
    cout << "Melyik tesztesetet szeretned lefuttatni?\n";
    cout << "1. Esemeny hozzaadasa a Naptarhoz\n" <<
               "2. Ket datum kozott eltelt napok szama\n" <<
               "3. Eddig lefoglalt datumok felsorolasa, adott datum foglaltsaganak ellenorzese\n" <<
               "4. Ket datum osszehasonlitasa\n" <<
               "5. Naptar mentese tablazatos formaban\n" << endl;
    Naptar naptar;
    int eset;
    try {
        cin >> eset;
        if (eset > 5 || eset < 1) {
        throw out_of_range("Ilyen szamu teszteset nem letezik!");
        }
    }
    catch (out_of_range& oor) {
        cout << "Hiba: " << oor.what() << endl;
    }

    try{
        switch (eset) {
        case 1:
            teszt1(naptar);
            break;
        case 2:
            teszt2();
            break;
        case 3:
            teszt3(naptar);
            break;
        case 4:
            teszt4(naptar);
            break;
        case 5:
            teszt5(naptar);
            break;
        }
    }
    catch (runtime_error& re) {
        cout << "Hiba: " << re.what() << endl;
    }
    catch (const char* c) {
        cout << "Hiba: " << c << endl;
    }
}

int main()
{

    cout << "Udv a Naptaradban!" << endl;
    menu();
    int valasz;
    do {
        cout << "\nSzeretne meg hasznalni a Naptarat?     1: igen     2: nem" << endl;
        cin >> valasz;
        if (valasz != 1 && valasz != 2) {
            cout << "Nem jo valaszt adott!" << endl;
        }
        else {
            if (valasz == 1) {
                menu();
            }
        }
    } while (valasz != 2);



    return 0;
}
