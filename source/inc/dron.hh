#ifndef _DRONE_HH
#define _DRONE_HH

#include "prostopadloscian.hh"
#include "graniastoslup.hh"
#include "wirnik.hh"

using wektor3D = Wektor<double, 3>;

class dron : public prostopadloscian
{

    wirnik lewy_wir, prawy_wir;
public:
    dron(Wektor3D tablica[], macierz_ob M, Wektor3D S, std::shared_ptr<drawNS::Draw3DAPI> wsk, std::string K, )
    : prostopadloscian(tablica, M, S, wsk, K) 
    , lewy_wir()
    , prawy_wir() {}

    ~dron() 
    {
        prostopadloscian::usun_obiekt();
        lewy_wir.usun_obiekt();
        prawy_wir.usun_obiekt();
    }
    
    void rysuj()
    {   
        lewy_wir.rysuj(srodek_bryly + orientacja * srodek_bryly);
        prawy_wir.rysuj();
        prostopadloscian::rysuj();
    }

    void przesun_przod(const double kat, const double odleglosc)
    {
        
    }
};

#endif