#ifndef NAPTAR_HPP_INCLUDED
#define NAPTAR_HPP_INCLUDED

#include <iostream>
#include "gtest_lite.h"
#include "datum.h"
#include "esemeny.h"
#include "csaladi.h"
#include "munkahelyi.h"

class Naptar {
    size_t db;
    Esemeny* elso;

public:
    //Konstruktor
    Naptar() {
        elso = NULL;
        db = 0;
    }

    //Getter, setter
    size_t size() const { return db; }
    Esemeny* get_ptr() const {return elso;}
    void set_db(int darab) {db = darab;}

    bool foglalt_e(Datum date);

    //beteszi a naptarba a kapott esemenyt
    template <typename P>
    void foglal(P* uj) {
        //szabad-e meg az a nap
        if (foglalt_e(uj->get_datum())) {
            throw "Mar van ezen a napon esemeny!";
            return;
        }

        //datum szerint rendezetten epiti az esemenyek listajat
        Iterator lemarado(NULL);
        Iterator mozgo = this->begin();
        while (mozgo.get_esem() != NULL && ((*mozgo) - (uj->get_datum()) ) < 0 ) {
            lemarado = mozgo;
            ++mozgo;
        }
        //ha az uj esemenyt a lista elejere kell beszurni
        if (lemarado.get_esem() == NULL) {
            uj->set_kov(elso);
            elso = uj;
        }
        //ha az esemenyt a listaba kell beszurni
        else {
            lemarado.get_esem()->set_kov(uj);
            uj->set_kov(mozgo.get_esem());
        }
        //eggyel no a tarolt esemenyek szama
        db++;
    }

    //tarolt esemenyek datumanak felsorolasa
    void felsorol();
    //ket adott datumon szereplo esemenyek osszehasonlitasa
    bool hasonlit(Datum& a, Datum& b);
    //naptar tartalmanak kiiras szovegfajlba kulonbozo bontasban
    void havi(int h); /*hanyadik honapot irassa ki*/
    void eves();

    //iterator inner class
    class Iterator {
        Esemeny* esem;
    public:
        Iterator(Esemeny* esemeny = nullptr) :esem(esemeny) {}

        Esemeny* get_esem() const {return esem;}
        void set_esem(Esemeny* e) { esem = e;}

        //esem dátumát visszaado operator
        Datum operator*();
        //az esem->kov-et visszaado operator
        Iterator& operator++() {
            if (esem != NULL) {
                esem = esem->get_kov();
            }
            return *this;
        }
        bool operator==(Iterator rhs);
        bool operator!=(Iterator rhs);
    };
    //iterator fv-ek
    Iterator begin()  {
        return Iterator(elso);
    }
    Iterator end() {
        return Iterator(NULL);
    }

    void torol() {
        Naptar::Iterator iter(elso);
        while (iter != this->end()) {
            Esemeny* kov = iter.get_esem()->get_kov();
            delete iter.get_esem();
            iter.set_esem(kov);
        }
    }
};

#endif // NAPTAR_HPP_INCLUDED
