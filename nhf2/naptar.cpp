#include "naptar.h"
#include "datum.h"
#include "memtrace.h"
#include "gtest_lite.h"
#include <fstream>

Datum Naptar::Iterator::operator*() {
    return Datum(esem->get_datum());
}

bool Naptar::Iterator::operator==(Iterator rhs) {
    return esem == rhs.esem;
}
bool Naptar::Iterator::operator!=(Iterator rhs) {
    return esem != rhs.esem;
}

bool Naptar::foglalt_e(Datum date) {
    for(Naptar::Iterator iter = this->begin(); iter != this->end(); ++iter) {
        //ha megegyezo datumu tarolt esemenyt talal:
        if ((*iter) == date) {
            return true;
        }
    }
    return false;
}

void Naptar::felsorol() {
    size_t darab = 0;
    for (Naptar::Iterator iter = this->begin(); iter != this->end(); ++iter) {
        darab++;
        std::cout << iter.get_esem()->get_datum().get_ho() << "." << iter.get_esem()->get_datum().get_nap() << "." << std::endl;
    }
    TEST(Felsorolas, darab)
        EXPECT_EQ(db, darab);
    END
}

bool Naptar::hasonlit(Datum& a, Datum& b) {
    Naptar::Iterator iter;
    Esemeny* egyik = NULL;
    Esemeny* masik = NULL;
    for (iter = this->begin(); iter != this->end(); ++iter) {
        if (*iter == a) {
            egyik = iter.get_esem();
        }
        if (*iter == b) {
            masik = iter.get_esem();
        }
    }
    if (egyik == NULL && masik == NULL) {
        return true;
    }
    if (egyik != NULL && masik!= NULL) {
        if (egyik->get_nev() == masik->get_nev()) {
            return true;
        }
    }
    return false;
}

void Naptar::havi(int h) {
    ofstream fajl("havi.txt");
    //megnyilt-e a fajl
    if (!fajl.is_open()){
       throw runtime_error("A fajlt nem lehetett megnyitni.");
    }
    for(Naptar::Iterator iter = this->begin(); iter != this->end(); ++iter){
        if ( (*iter).get_ho() == h) {
            iter.get_esem()->kiir(fajl);
        }
    }
    fajl.close();
}
void Naptar::eves() {
    ofstream fajl("eves.txt");
    //megnyilt-e a fajl
    if (!fajl.is_open()){
       throw runtime_error("A fajlt nem lehetett megnyitni.");
    }
    for(Naptar::Iterator iter = this->begin(); iter != this->end(); ++iter){
        iter.get_esem()->kiir(fajl);
    }
    fajl.close();
}
