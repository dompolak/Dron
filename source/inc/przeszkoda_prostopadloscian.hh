#ifndef _PRZESZKODA_PROSTOPADLOSCIENNA_HH
#define _PRZESZKODA_PROSTOPADLOSCIENNA_HH

#include "przeszkoda.hh"
#include "prostopadloscian.hh"

class przeszkoda_prost : public prostopadloscian, public przeszkoda
{   
public:
    przeszkoda_prost(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S, Wektor3D tablica[])
    : prostopadloscian(wsk, K, M, S, tablica) {}

    void rysuj() { prostopadloscian::rysuj(); }
    bool czy_kolizja(const interfejs_drona & Dron)
    {

    }

};
#endif