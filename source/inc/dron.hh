#ifndef _DRONE_HH
#define _DRONE_HH

#include "prostopadloscian.hh"
#include "graniastoslup.hh"
#include "wirnik.hh"

using wektor3D = Wektor<double, 3>;

class dron : public prostopadloscian
{

    wirnik lewy, prawy; //wirniki
public:
    dron(Wektor3D tablica[], Wektor3D tab1[], Wektor3D tab2[], macierz_ob M, Wektor3D S, Wektor3D sr1, Wektor3D sr2, std::shared_ptr<drawNS::Draw3DAPI> wsk, std::string K)
    : prostopadloscian(tablica, M, S, wsk, K) 
    , lewy(sr1, wsk, K, tab1, M)
    , prawy(sr2, wsk, K, tab2, M) {}

    ~dron() 
    {
        usun_obiekt();
    }
    
    void rysuj()
    {   
        lewy.rysuj();
        prawy.rysuj();
        prostopadloscian::rysuj();
    }

    void usun_obiekt()
    {
        prostopadloscian::usun_obiekt();
        lewy.usun_obiekt();
        prawy.usun_obiekt();
    }

    void przesun(const wektor3D &we)
    {   
        wektor3D tmp(we/1000);
        for(int i(0); i < 1000; i++)
        {
            lewy.przesun(tmp);
            prawy.przesun(tmp);
            prostopadloscian::przesun(tmp);
            usun_obiekt();

        }
    }   
};

#endif