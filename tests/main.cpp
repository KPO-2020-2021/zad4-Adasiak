#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "./doctest/doctest.h"
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "Prostopadloscian.hh"
#include "matrix.hh"
#include "size.hh"



TEST_CASE("konstruktor parametryczny")
{
    double a = 1.0, b = 2.0, c=3.0 ;
    Vector <3> wektor  /*( a, b )*/  ;

    wektor[0] = a;
    wektor[1] =b;
    wektor[2] =c;

    CHECK(wektor[0] == 1);
    CHECK(wektor[1] == 2);
    CHECK(wektor[2] == 3);
}


TEST_CASE("konstruktor bezparametryczny")
{

    Vector <3> wektor;

    CHECK(wektor[0] == 0);
    CHECK(wektor[1] == 0);
    CHECK(wektor[2] == 0);
}

TEST_CASE("Dodawanie wektorów")
{
    double tab1[3]={1,2,3};
    double tab2[3]={2,1,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab2);
    Vector <3> wynik;

    wynik = wektor1 + wektor2;
    CHECK(wynik[0] == 3);
    CHECK(wynik[1] == 3);
    CHECK(wynik[2] == 6);
}

TEST_CASE("Odejmowanie wektorów")
{
    double tab1[3]={1,2,3};
    double tab2[3]={2,1,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab2);
    Vector <3> wynik;

    wynik = wektor1 - wektor2;
    CHECK(wynik[0] == -1);
    CHECK(wynik[1] == 1);
    CHECK(wynik[2] == 0);
}

TEST_CASE("wektor * stała")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    double a = 2;
    Vector <3> wynik;

    wynik = wektor1 * a;
    CHECK(wynik[0] == 2);
    CHECK(wynik[1] == 4);
    CHECK(wynik[2] == 6);
}

TEST_CASE("wektor - wyświetlanie")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    // double a[2]={1,2};
    std::ostringstream StrmWyj;
    StrmWyj << wektor1;
    std::cout << StrmWyj.str();
    CHECK("1 2 3 " == StrmWyj.str());
}

TEST_CASE("wektor - wpisywanie")
{
    Vector <3> a;

    std::istringstream in("1 1 1");
    in >> a;
    std::ostringstream out;
    out << a;

    CHECK("1 1 1 " == out.str());
}

TEST_CASE("operator porownania")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab1);

    CHECK(wektor1 == wektor2);
}

// TEST_CASE("T=blad")
// {
//     double tab1[2]={1,2};
//     Vector wektor1(tab1);
//     WARN_THROWS(wektor1[2]);
// }

TEST_CASE("operator porownania")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab1);

    CHECK(wektor1 == wektor2);
}

TEST_CASE("mierzenie odległosci")
{
    double tab1[3]={1,2,3};
    double wynik;
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab1);

    wynik = wektor1.spr(wektor2) ;

    CHECK(wynik == 0);
}
// // /****************************MACIERZ****************************/

TEST_CASE("konstruktor parametryczny")
{

    double tab[3][3] = {{2,2,2}, {2,2,2}};
    Matrix <3> macierz(tab);

    CHECK(macierz(0, 0) == 2);
    CHECK(macierz(0, 1) == 2);
    CHECK(macierz(0, 2) == 2);
    CHECK(macierz(1, 0) == 2);
    CHECK(macierz(1, 1) == 2);
    CHECK(macierz(1, 2) == 2);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Matrix <3> macierz;

    CHECK(macierz(0, 0) == 1);
    CHECK(macierz(0, 1) == 0);
    CHECK(macierz(0, 2) == 0);
    CHECK(macierz(1, 0) == 0);
    CHECK(macierz(1, 1) == 1);
    CHECK(macierz(1, 2) == 0);
}

TEST_CASE("macierz mnożenie * wektor")
{
    double tab1[3]={1,2,3};
    double tab2[3]={0,0,0};
    Vector <3>wektor1(tab1);
    Vector <3>wektor2(tab2);
    Matrix <3> macierz;

    wektor1 = macierz * wektor2;
    CHECK(wektor1 == wektor2);
}


// TEST_CASE("metoda gaussa")
// {
//     double tab[3][3] = {{1,1,1}, {0, 1,1}};
//     Matrix <3> macierz(tab);
//     macierz.Gaus();

//     CHECK(macierz(0, 0) == 1);
//     CHECK(macierz(0, 1) == 1);
//     CHECK(macierz(0, 2) == 1);
//     CHECK(macierz(1, 0) == 0);
//     CHECK(macierz(1, 1) == 1);
//     CHECK(macierz(1, 2) == 1);
// }


TEST_CASE("macierz 4x4 mnożenie * wektor")
{
    double tab1[4]={0,0,0,0};
    double tab2[3]={10,20,30};
    double a=90, b=90,c=90;
    Vector <4>wektor1(tab1);
    Vector <3>wektor2(tab2);
    Matrix <4> m;
    m= cztery(a,b,c,wektor2); 
    wektor1 = m * wektor1 ;

    // wektor1 = macierz * ;
    CHECK(wektor1 == wektor1);
}




// /****************************PROSTOPADLOSCIAN****************************/

TEST_CASE("konstruktor parametryczny")
{
    double tab1[3]={0,0,0};
    double tab2[3]={20,0,0};
    double tab3[3]={0,10,0};
    double tab4[3]={20,10,0};

    double tab5[3]={0,10,30};
    double tab6[3]={20,10,30};
    double tab7[3]={0,0,30};
    double tab8[3]={20,0,30};

    Vector <3> wektor(tab1), wektor1(tab2), wektor2(tab3), wektor3(tab4);
    Vector <3> wektor4(tab5), wektor5(tab6),wektor6(tab7),wektor7(tab8)  ;
    double h = 10, w = 20 , p=30;
    Prostopadloscian Pr(wektor, h, w ,p);

    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor1);
    CHECK(Pr[2] == wektor2);
    CHECK(Pr[3] == wektor3);
    CHECK(Pr[4] == wektor4);
    CHECK(Pr[5] == wektor5);
    CHECK(Pr[6] == wektor6);
    CHECK(Pr[7] == wektor7);
     
}

TEST_CASE("konstruktor bezparametryczny")
{

    Prostopadloscian Pr;
    Vector <3>wektor;
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
    CHECK(Pr[4] == wektor);
    CHECK(Pr[5] == wektor);
    CHECK(Pr[6] == wektor);
    CHECK(Pr[7] == wektor);
    
}

TEST_CASE("przesuniecie o wektor")
{
    double tab[3]={20,30,40};
    Prostopadloscian Pr;
    Vector <3>wektor(tab);
    Pr=Pr+wektor;
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
    CHECK(Pr[4] == wektor);
    CHECK(Pr[5] == wektor);
    CHECK(Pr[6] == wektor);
    CHECK(Pr[7] == wektor);
}

TEST_CASE("obrot wokol Osi OZ")
{

    Prostopadloscian Pr;
    double kat=90;
    Matrix <3> macierz;
    macierzobrotZ(kat);
    Pr = macierzobrotZ(kat) * Pr;
    Vector <3>wektor;
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
    CHECK(Pr[4] == wektor);
    CHECK(Pr[5] == wektor);
    CHECK(Pr[6] == wektor);
    CHECK(Pr[7] == wektor);
}


TEST_CASE("obrot wokol Osi OX")
{

    Prostopadloscian Pr;
    double kat=90;
    Matrix <3> macierz;
    macierzobrotZ(kat);
    Pr = macierzobrotX(kat) * Pr;
    Vector <3>wektor;
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
    CHECK(Pr[4] == wektor);
    CHECK(Pr[5] == wektor);
    CHECK(Pr[6] == wektor);
    CHECK(Pr[7] == wektor);
}


TEST_CASE("obrot wokol Osi OY")
{

    Prostopadloscian Pr;
    double kat=90;
    Matrix <3> macierz;
    macierzobrotY(kat);
    Pr = macierzobrotX(kat) * Pr;
    Vector <3>wektor;
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
    CHECK(Pr[4] == wektor);
    CHECK(Pr[5] == wektor);
    CHECK(Pr[6] == wektor);
    CHECK(Pr[7] == wektor);
}



TEST_CASE("prostokar - wyświetlanie")
{
    Prostopadloscian Pr;

    std::ostringstream StrmWyj;
    StrmWyj << Pr;
    std::cout << StrmWyj.str();
    CHECK("0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n" == StrmWyj.str());
}