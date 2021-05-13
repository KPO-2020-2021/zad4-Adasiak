#pragma once

#include "vector.hh"

// #include "matrix.hh"
#include "size.hh"
// #include "../include/lacze_do_gnuplota.hh"
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
class Prostopadloscian
{
public:
    // Vector<  3> a,b,c,d;
    Vector<3> pkt1[8];

public:
    Prostopadloscian(){};

    Prostopadloscian(Vector<3> pkt, double h, double w, double d);

    Vector<3> operator[](int Ind) const { return pkt1[Ind]; } //wypisywanie

    Vector<3> &operator[](int Ind) { return pkt1[Ind]; } //wpisywanie

    Prostopadloscian operator+(const Vector<3> &wektor);

    Vector<3> translacja(Vector<3> &trans);

    Vector<3> rotacja(double &kat);

    void sprawdz();

    bool sprdl() const;

    bool sprkat() const;

    // bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr, Vector<  3> Przesuniecie);

    // void rysuj();
};

// void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream&     StrmWy, Prostopadloscian Prostopadloscian,  /*double*/ Vector<  3>  Przesuniecie);

// bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr);

std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr);