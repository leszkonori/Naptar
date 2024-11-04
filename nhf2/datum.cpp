#include <iostream>
#include "datum.h"
#include "memtrace.h"
#include "gtest_lite.h"

bool Datum::operator==(Datum& rhs) {
    if (ho == rhs.ho && nap == rhs.nap)
        return true;
    return false;
}

int Datum::hanyadik_nap() {
    //honapok napjainak szama egy rendezett tombben
    int honapok[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int hanyadik = 0;
    int i = 0;
    while (i < ho-1) /* az adott honap nem biztos, hogy teljes, ezert -1 */
    {
        hanyadik += honapok[i];
        i++;
    }
    hanyadik += nap; /* az adott honapban hanyadik nap */
    return hanyadik;
}


int Datum::operator-(Datum rhs) {
    int kul = hanyadik_nap() - rhs.hanyadik_nap();
    return kul;
}
