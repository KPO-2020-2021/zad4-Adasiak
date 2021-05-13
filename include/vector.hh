#pragma once

// #ifndef Vector<  SIZE>_HH
// #define Vector<  SIZE>_HH

#include "size.hh"
#include <iostream>
#include <cmath>
#include <initializer_list>

#define PI 3.14159
#define MIN 0.0000000001
// #define Q 180;

template <int SIZE>
class Vector
{
    double size[SIZE];

public:
    Vector();
    Vector(double tmp[SIZE]);

/*! 
    \brief      

 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
    const double  &operator[](int index) const
    {
        if (index < 0 || index >= SIZE)
        {
            std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
        }
        return size[index];
    }

/*!
    \brief       
**************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */

    double &operator[](int index)
    {
        return const_cast<double &>(const_cast<const Vector<SIZE> *>(this)->operator[](index));
    }

    Vector<SIZE> operator+(const Vector<SIZE> &v);
    Vector<SIZE> operator-(const Vector<SIZE> &v);
    Vector<SIZE> operator*(const double &tmp);
    Vector<SIZE> operator/(const double &tmp);

    Vector<SIZE> translacja(const Vector<SIZE> &trans);

    double spr(const Vector<SIZE> &v);

    bool operator==(const Vector<SIZE> v) const;
};

//  #define PI 3.14159
/*!
    \brief     
  **************************************************************************
 |  Konstruktor klasy Vector<  SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Vector<SIZE>::Vector()
{
    for (int i = 0; i < SIZE; i++)
    {
        size[i] = 0;
    }
}

/*!
    \brief
*****************************************************************************
 |  Konstruktor klasy Vector<  SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu  double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Vector<SIZE>::Vector(double tmp[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        size[i] = tmp[i];
    }
}

/*!
    \brief
*****************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator+(const Vector<SIZE> &v)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = size[i] += v[i];
    }
    return result;
}

/*!
    \brief                        
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator-(const Vector<SIZE> &v)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = size[i] -= v[i];
    }
    return result;
}

/*!       
    \brief
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu  double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator*(const double &tmp)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/*!       

    \brief
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator/(const double &tmp)
{
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}

/*!       
    \brief
 |  Realizuje translacje dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania                                      |
 |      trans - drugi skladnik dodawania                                         |                                            |
 |                                                                              |
 |  Zwraca:                                                                   |
 |      Wektor sumy wketora pierotnego i wektora z wspolrzednymi przesuniecia |                                                         |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::translacja(const Vector<SIZE> &trans)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = size[i] += trans[i];
    }
    return result;
}

/*!       
    \brief
 |  Odlegosc odcinka.                                                           |
 |  Argumenty:                                                                  |
 |      poszczegolne wspolrzedne wektora                                        |                                            |
 |                                                                              |
 |  Zwraca:                                                                     |
 |      odleglosc miedzy nimi                                                   |                                                         |
 */
template <int SIZE>
double Vector<SIZE>::spr(const Vector<SIZE> &v)
{
    return sqrt(pow(size[0] - v[0], 2) + pow(size[1] - v[1], 2) + pow(size[2] - v[2], 2) );
}


/*!       
    \brief
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
// std::ostream &operator << (std::ostream &out, Vector<  SIZE> const &tmp) {
//     for (int i = 0; i < SIZE; i++) {
//         out << "[ " << tmp[ ] << " ]\n";
//     }
//     return out;
// }
template <int SIZE>
std::ostream &operator<<(std::ostream &out, Vector<SIZE> const &tmp)
{
    for (int i = 0; i < SIZE; i++)
    {
        out << tmp[i] << " ";
    }
    return out;
}

/*!      
    \brief
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Vector<SIZE> &tmp)
{
    for (int i = 0; i < SIZE; i++)
    {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

/*!       
    \brief
 |  Przeciazenie operatora ==                                                 |
 |  Argumenty:                                                                |
 |      porowniuje poszczegolne wspolrzene kolejnych 2 wektorow               |
 */
template <int SIZE>
bool Vector<SIZE>::operator==(const Vector<SIZE> v) const
{
    for (int i = 0; i < SIZE; i++)
        if (!(abs(this->size[i] - v.size[i]) <= (MIN)))
            return false;

    return true;
}
